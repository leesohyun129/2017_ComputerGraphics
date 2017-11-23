 #pragma once

class CCamera;

class CRuntimeFrameWork
{
private:
	static CRuntimeFrameWork* mySelf;

private:
	GLint m_nViewPortWidth;
	GLint m_nViewPortHeight;
	GLboolean m_bGimbalLock{ true };

private:
	GLint m_fCurrentTime;
	GLfloat m_fPrevTime;
	GLint m_nCurrentFrame;
	GLfloat m_mtxLocal[16];
	GLfloat m_mtxLocal2[16];

	Vector3D m_vRotate;

	CCamera*			m_pCamera{ nullptr };

// using ����
public:
	//typedef GLvoid(*Idle)();
	using Idle = GLvoid(*)();
	using Display = GLvoid(*)();
	//typedef GLvoid(*KeyBoard)(unsigned char, int, int);
	using KeyBoard = GLvoid(*)(unsigned char, int, int);
	using SpecialKeyBoard = GLvoid(*)(int, int, int);
	using Mouse = GLvoid(*)(int, int, int, int);
	using MouseMove = GLvoid(*)(int, int);
	using Resize = GLvoid(*)(int, int);

// �Լ� ������ ����
private:
	Idle m_fpIdle{ nullptr };
	Display m_fpRender{ nullptr };
	KeyBoard m_fpKeyBorad{ nullptr };
	SpecialKeyBoard m_fpSpecialKey{ nullptr };
	Mouse m_fpMouse{ nullptr };
	MouseMove m_fpMouseMove{ nullptr };
	Resize m_fpReshape{ nullptr };

public:
	void RegisterIdle(Idle func) { m_fpIdle = func; };
	void RegisterRender(Display func) { m_fpRender = func; };
	void RegisterKeyBoard(KeyBoard func) { m_fpKeyBorad = func; };
	void RegisterSpecialKeyBoard(SpecialKeyBoard func) { m_fpSpecialKey = func; };
	void RegisterMouse(Mouse func) { m_fpMouse = func; };
	void RegisterMouseMove(MouseMove func) { m_fpMouseMove = func; };
	void RegisterReshape(Resize func) { m_fpReshape = func; };

public:
	CRuntimeFrameWork();
	~CRuntimeFrameWork() = default;

	GLvoid Init();
	GLvoid Update();
	GLvoid Render();
	GLvoid OnProcessKeyBoard(unsigned char key, int x, int y);
	GLvoid OnProcessSpecialKeyBoard(int key, int x, int y);
	GLvoid OnProcessMouse(int button, int state, int x, int y);
	GLvoid OnProcessMouseMove(int x, int y);
	GLvoid Reshape(int width, int height);

};
