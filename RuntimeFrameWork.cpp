#include "stdafx.h"
#include "Camera.h"
#include "Map.h"

#include "robot.h"
#include "airplane.h"
#include "RuntimeFrameWork.h"

#define GL_PI 3.1415f

//CRuntimeFrameWork* CRuntimeFrameWork::mySelf = nullptr;


CRuntimeFrameWork::CRuntimeFrameWork()
{
	m_pCamera = new CCamera();
	m_pMap = new Map();
	m_pRobot = new Robot();
	m_pAirplane = new Airplane();
	//m_pPlayer = new Player();
	// memset(초기화할 자원, 초기화할 값, 초기화할 자원의 크기);
	memset(m_mtxLocal, 0, sizeof(m_mtxLocal));
	m_mtxLocal[0] = m_mtxLocal[5] = m_mtxLocal[10] = m_mtxLocal[15] = 1;

	memset(m_mtxLocal2, 0, sizeof(m_mtxLocal));
	m_mtxLocal2[0] = m_mtxLocal2[5] = m_mtxLocal2[10] = m_mtxLocal2[15] = 1;

	m_vRotate = Vector3D{ 0.0f, 0.0f, 0.0f };
	m_pCamera->CameraReset();
}

GLvoid CRuntimeFrameWork::Init()
{
	srand((unsigned)time(NULL));
	::glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Display 모드 설정
	::glutInitWindowPosition(100, 100);
	::glutInitWindowSize(800, 600); // 윈도우 크기 설정 
									// 윈도우 설정은 생성전에
	::glutCreateWindow("PangLand"); // 인자로 넘긴 문자열의 이름을 가진 윈도우 생성


	// 콜백 등록은 윈도우 생성 이후

	::glutIdleFunc(m_fpIdle); // Idle 상태일때 호출할 콜백 등록
	::glutDisplayFunc(m_fpRender); // Display 콜백 등록
	::glutKeyboardFunc(m_fpKeyBorad);
	::glutSpecialFunc(m_fpSpecialKey);
	::glutMouseFunc(m_fpMouse);
	::glutPassiveMotionFunc(m_fpMouseMove);
	::glutReshapeFunc(m_fpReshape);
	
	glEnable(GL_DEPTH_TEST);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::Update()
{
	m_fCurrentTime = glutGet(GLUT_ELAPSED_TIME);
	m_nCurrentFrame++;

	if (m_fCurrentTime - m_fPrevTime > 1000 / FPS_PERSECOND)
	{
		m_fPrevTime = m_fCurrentTime;
		m_nCurrentFrame = 0;
		::glutPostRedisplay();
	}
	return GLvoid();
}

GLvoid CRuntimeFrameWork::Render()
{
	// GL상태변수 설정, 프레임 버퍼를 초기화
	// 초기화 될 색은 glutClearColor에서 사용된 색

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	{
		m_pMap->MapRender();
		//TimerFunc(0);
		//m_pRobot->draw();
		//m_pAirplane->draw();
	}
	
	glutSwapBuffers();
	return GLvoid();
}
GLvoid CRuntimeFrameWork::TimerFunc(int value)
{
	::glutPostRedisplay();
	::glutTimerFunc(500, m_fpTimer, 0);
	cout << "불린다 타이머" << endl;
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessKeyBoard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': case 'W':
		m_pCamera->CameraMove(3);
		break;
	case 's': case 'S':
		
		m_pCamera->CameraMove(2);

		break;
	case 'd': case 'D':
	
		m_pCamera->CameraMove(0);

		break;
	case 'a': case 'A':
		
		m_pCamera->CameraMove(1);

		break;
	case 'r': case 'R':

		m_pCamera->CameraReset();
		break;
	case '-':
		m_pCamera->CameraMove(5);
		break;
	case '+':
		m_pCamera->CameraMove(4);
		break;
	}
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessSpecialKeyBoard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		m_pCamera->CameraRotate(0);
		break;
	case GLUT_KEY_RIGHT:
		m_pCamera->CameraRotate(1);
		break;
	case GLUT_KEY_DOWN:
		m_pCamera->CameraRotate(2);
		break;
	case GLUT_KEY_UP:
		m_pCamera->CameraRotate(3);
		break;
	}
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessMouse(int button, int state, int x, int y)
{

	return GLvoid();
}

GLvoid CRuntimeFrameWork::OnProcessMouseMove(int x, int y)
{

	mouse.x = x - preMouse.x;
	preMouse.x = x;
	mouse.y = y - preMouse.y;
	preMouse.y = y;

	//vRotate.z += mouse.x;
	//vRotate.z += mouse.x;
	if (mouse.x > 0)
		m_pCamera->CameraRotate(1);
	else if (mouse.x < 0)
		m_pCamera->CameraRotate(0);

	if (mouse.y > 0)
		m_pCamera->CameraRotate(3);
	else if (mouse.y < 0)
		m_pCamera->CameraRotate(2);

	//camera.rotateX += mouse.y / 2;
	//camera.rotateX += mouse.y / 2;
	cout << "된다딘다" << endl;
	cout << mouse.x << endl;
	//::glutPostRedisplay;
	//::glutPassiveMotionFunc;
	Reshape(m_nViewPortWidth, m_nViewPortHeight);
	return GLvoid();
}

GLvoid CRuntimeFrameWork::Reshape(int width, int height)
{
	if(width != 0)
		m_nViewPortWidth = width;
	if(height != 0)
		m_nViewPortHeight = height;

	glViewport(0, 0, m_nViewPortWidth, m_nViewPortHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, 1, 1.0f, 1000.0f);
	
	vRotate = m_pCamera->GetCameraRotate();
	vEye = m_pCamera->GetCameraPos();
	vLook = m_pCamera->GetCameraLook();
	vUp = m_pCamera->GetCameraUp();

	gluLookAt(
		vEye.x, vEye.y, vEye.z,
		vLook.x, vLook.y, vLook.z,
		vUp.x, vUp.y, vUp.z);
	
	glRotatef(vRotate.x, 1.0f, 0.0f, 0.0f);
	glRotatef(vRotate.y, 0.0f, 1.0f, 0.0f);
	glRotatef(vRotate.z, 0.0f, 0.0f, 1.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return GLvoid();
}
