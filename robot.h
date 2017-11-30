#pragma once
class Robot {
public:
	int x = 0;
	int y = 10;//-50;
	int z = 0;
	bool isjump = false;
	bool isfalling = false;
	float m_mtxLocal[16] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
	float m_mtxLocal_trans[16] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };

	int direction;
	int angle;
	bool angle_add = true;

	GLvoid draw();
	GLvoid move(unsigned char key);
};