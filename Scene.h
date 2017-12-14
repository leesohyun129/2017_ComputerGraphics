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
	T t[10];
	Vector3D logoTrans; 
	float logoAngle;
	bool logoMove = false;
	int logonum = 5;
	int scene_Num = 1;
	GLvoid Button();
	void read();
	GLvoid drawlogo();
};