#pragma once
class Robot {
public:
	int x = 0;
	int y = -50;
	int z = 0;
	bool isjump = false;
	bool isfalling = false;

	int direction;
	int angle;
	bool angle_add = true;

	GLvoid draw();
	GLvoid move(unsigned char key);
};