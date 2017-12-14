// Tuter_OpenGL_GimbalLock.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include "RuntimeFrameWork.h"
	
CRuntimeFrameWork runtimeFrameWork;

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	runtimeFrameWork.RegisterIdle([]() {runtimeFrameWork.Update(); });
	runtimeFrameWork.RegisterRender([]() {runtimeFrameWork.Render(); });
	runtimeFrameWork.RegisterMouse([](int button, int state, int x, int y) {runtimeFrameWork.OnProcessMouse(button, state, x, y); });
	runtimeFrameWork.RegisterMouseMove([](int x, int y) {runtimeFrameWork.OnProcessMouseMove(x, y); });
	runtimeFrameWork.RegisterKeyBoard([](unsigned char key, int x, int y) {runtimeFrameWork.OnProcessKeyBoard(key, x, y); });
	runtimeFrameWork.RegisterSpecialKeyBoard([](int key, int x, int y) {runtimeFrameWork.OnProcessSpecialKeyBoard(key, x, y); });
	runtimeFrameWork.RegisterReshape([](int w, int h) {runtimeFrameWork.Reshape(w, h); });
	runtimeFrameWork.RegisterTimer([](int value) {runtimeFrameWork.TimerFunc(value); });
	runtimeFrameWork.Init();
	glutMainLoop(); // �̺�Ʈ ���� ����
	return 0;
}

