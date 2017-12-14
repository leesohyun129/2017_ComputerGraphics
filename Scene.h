#pragma once
struct T
{
	float x;
	float y;
	float z;
	float size;

	int arr[5][5];
};

class Scene
{

private:
public:
	BITMAPINFO *gamestart_Info;
	BITMAPINFO *help_Info;
	BITMAPINFO *quit_Info;
	BITMAPINFO *control_Info;



	T t[10];
	GLuint texture[6];
	GLubyte* textureBits_Start;
	GLubyte* textureBits_Help;
	GLubyte* textureBits_Quit;
	GLubyte* textureBits_Control;


	float button_bottom = -400;
	float button_top = -300;

	Vector3D logoTrans; 
	float logoAngle;
	bool logoMove = false;
	int logonum = 5;
	int scene_Num = 0;
	GLvoid Button();
	GLvoid control();
	void read();
	void setTexture();
	GLvoid drawlogo();
};