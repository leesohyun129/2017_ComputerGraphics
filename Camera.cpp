#include "stdafx.h"
#include "Camera.h"
//소현 TO DO : 11.24 카메라 설정 
CCamera::CCamera()
{
	m_vRotateAngle = Vector3D{ 0.0f, 0.0f, 0.0f };
	m_mtxLocal.r1 = Vector3D{ 0.0f, 0.0f, 10.0f };
	m_mtxLocal.r2 = Vector3D{ 0.0f, 0.0f, -1.0f };
	m_mtxLocal.r3 = Vector3D{ 0.0f, 1.0f, 0.0f };
	//m_mtxLocal.r1.z = -500;
}

GLvoid CCamera::CameraZoom(int away)
{
	m_mtxLocal.r1.z += (away * MOVE_FACTOR);
	//1: 확대 3:축소
	return GLvoid();
}

GLvoid CCamera::CameraMove(int away)
{
	int sign = 1;

	switch (away) {
	case 0:
	case 1: 
		away == 0 ? sign = sign : sign = -sign;
		m_mtxLocal.r1.x += (sign * MOVE_FACTOR);
		m_mtxLocal.r2.x += (sign * MOVE_FACTOR);
		break;
	case 2:
	case 3: 
		away == 2 ? sign = sign : sign = -sign;
		m_mtxLocal.r1.y += (sign * MOVE_FACTOR);
		m_mtxLocal.r2.y += (sign * MOVE_FACTOR);
		break;
	case 4://z축 
		away == 3 ? sign = sign : sign = -sign;
		m_mtxLocal.r1.z -= (sign * MOVE_FACTOR);
		m_mtxLocal.r2.z -= (sign * MOVE_FACTOR);
		break;
	case 5://z축
		away == 3 ? sign = sign : sign = -sign;
		m_mtxLocal.r1.z += (sign * MOVE_FACTOR);
		m_mtxLocal.r2.z += (sign * MOVE_FACTOR);
		break;
	}

	return GLvoid();
}

GLvoid CCamera::CameraRotate(int away)
{
	int sign = 1;

	switch (away) {
	case 0:
	case 1:
		away == 0 ? sign = sign : sign = -sign;
		m_vRotateAngle.y += (sign * ROTATE_FACTOR);
		break;
	case 2:
	case 3:
		away == 2 ? sign = sign : sign = -sign;
		m_vRotateAngle.x += (sign * ROTATE_FACTOR);
		break;
	}

	//GLfloat normalize = sqrt(pow(m_mtxLocal.r1.x, 2) + pow(m_mtxLocal.r1.y, 2) + pow(m_mtxLocal.r1.z, 2));
	//
	//m_mtxLocal.r2.x = -m_mtxLocal.r1.x / normalize;
	//m_mtxLocal.r2.y = -m_mtxLocal.r1.y / normalize;
	//m_mtxLocal.r2.z = -m_mtxLocal.r1.z / normalize;

	return GLvoid();
}

GLvoid CCamera::CameraReset()
{
	m_vRotateAngle = Vector3D{ 0.0f, 0.0f, 0.0f };
	m_mtxLocal.r1 = Vector3D{ 0.0f, 0.0f, -10.0f };
	m_mtxLocal.r2 = Vector3D{ 0.0f, 0.0f, -1.0f };
	m_mtxLocal.r3 = Vector3D{ 0.0f, 1.0f, 0.0f };
	return GLvoid();
}


