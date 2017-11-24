#include "stdafx.h"
#include "Camera.h"
#include "Map.h"
#include "RuntimeFrameWork.h"

#define GL_PI 3.1415f

//CRuntimeFrameWork* CRuntimeFrameWork::mySelf = nullptr;


CRuntimeFrameWork::CRuntimeFrameWork()
{
	m_pCamera = new CCamera();
	m_pMap = new Map();
	// memset(�ʱ�ȭ�� �ڿ�, �ʱ�ȭ�� ��, �ʱ�ȭ�� �ڿ��� ũ��);
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
	::glutInitWindowSize(800, 600); // ������ ũ�� ���� 
	::glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Display ��� ����
	// ������ ������ ��������
	::glutCreateWindow("PangLand"); // ���ڷ� �ѱ� ���ڿ��� �̸��� ���� ������ ����
	// �ݹ� ����� ������ ���� ����

	::glutIdleFunc(m_fpIdle); // Idle �����϶� ȣ���� �ݹ� ���
	::glutDisplayFunc(m_fpRender); // Display �ݹ� ���
	::glutKeyboardFunc(m_fpKeyBorad);
	::glutSpecialFunc(m_fpSpecialKey);
	::glutMouseFunc(m_fpMouse);
	::glutPassiveMotionFunc(m_fpMouseMove);
	::glutReshapeFunc(m_fpReshape);

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
	// GL���º��� ����, ������ ���۸� �ʱ�ȭ
	// �ʱ�ȭ �� ���� glutClearColor���� ���� ��

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	{
		m_pMap->MapRender();
	}
	
	glutSwapBuffers();
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
	gluPerspective(60.0f, m_nViewPortWidth / m_nViewPortHeight, 1.0f, 1000.0f);
	
	Vector3D vRotate = m_pCamera->GetCameraRotate();
	Vector3D vEye = m_pCamera->GetCameraPos();
	Vector3D vLook = m_pCamera->GetCameraLook();
	Vector3D vUp = m_pCamera->GetCameraUp();

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
