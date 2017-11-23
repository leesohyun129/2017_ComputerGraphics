#pragma once

class CCamera
{
private:
	Vector3D			m_vRotateAngle;
	Matirx				m_mtxLocal;

public:
	CCamera();
	~CCamera() = default;

	GLvoid CameraZoom(int away);
	GLvoid CameraMove(int away);
	GLvoid CameraRotate(int away);
	GLvoid CameraReset();

	Vector3D GetCameraRotate() const { return m_vRotateAngle; }
	Vector3D GetCameraPos() const { return m_mtxLocal.r1; }
	Vector3D GetCameraLook() const { return m_mtxLocal.r2; }
	Vector3D GetCameraUp() const { return m_mtxLocal.r3; }
	GLvoid GetCameraRotate(Vector3D vec) { m_vRotateAngle = vec; }
	GLvoid SetCameraPos(Vector3D vec) { m_mtxLocal.r1 = vec; }
	GLvoid SetCameraLook(Vector3D vec) { m_mtxLocal.r2 = vec; }
	GLvoid SetCameraUp(Vector3D vec) { m_mtxLocal.r3 = vec; }
};