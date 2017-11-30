#include "stdafx.h"
#include "robot.h"


GLvoid Robot::draw()
{
	
	glPushMatrix();
	{
		//짐벌락
		glMultMatrixf(m_mtxLocal_trans);
		glMultMatrixf(m_mtxLocal);


		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTranslatef(Robot::x, Robot::y - 40, Robot::z);
		glRotatef(Robot::direction, 0, 1, 0);
		// 몸체
		GLfloat color_body[] = { 1.0f, 0.0f, 0.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_body);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glScalef(1, 1.5, 1);
			glColor4f(1.0, 0, 0, 0);
			glutSolidCube(20);
			glColor4f(0, 0, 0, 0);
			glutWireCube(20);
		}
		glPopMatrix();
		// 머리
		GLfloat color_head[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_head);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(0, 23, 0);
			glColor4f(1.0, 1.0, 1.0, 0);
			glutSolidCube(15);
			glColor4f(0, 0, 0, 0);
			glutWireCube(15);
		}
		glPopMatrix();
		// 코
		GLfloat color_nose[] = { 0.4f, 0.4f, 0.2f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_nose);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(7.5, 23, 0);
			glColor4f(0.4, 0.4, 0.2, 0);
			glScalef(2, 1, 1);
			glutSolidCube(5);
			glColor4f(0, 0, 0, 0);
			glutWireCube(5);
		}
		glPopMatrix();
		// 왼팔
		GLfloat color_Leftarm[] = { 0.0f, 1.0f, 0.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_Leftarm);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(0, 0, 15);
			glTranslatef(0, 15, 0);
			glRotatef(Robot::angle, 0, 0, 1);
			glTranslatef(0, -15, 0);
			glScalef(1, 3, 1);
			glColor4f(0, 1, 0, 0);
			glutSolidCube(10);
			glColor4f(0, 0, 0, 0);
			glutWireCube(10);
		}
		glPopMatrix();
		// 오른팔
		GLfloat color_Rightarm[] = { 0.0f, 0.2f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_Rightarm);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(0, 0, -15);
			glTranslatef(0, 15, 0);
			glRotatef(-Robot::angle, 0, 0, 1);
			glTranslatef(0, -15, 0);
			glScalef(1, 3, 1);
			glColor4f(0, 0.2, 1, 0);
			glutSolidCube(10);
			glColor4f(0, 0, 0, 0);
			glutWireCube(10);
		}
		glPopMatrix();
		// 왼쪽 다리
		GLfloat color_Leftleg[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_Leftleg);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(0, -30, 6);
			glTranslatef(0, 15, 0);
			glRotatef(-Robot::angle, 0, 0, 1);
			glTranslatef(0, -15, 0);
			glScalef(1, 3, 1);
			glColor4f(1, 0, 1, 0);
			glutSolidCube(10);
			glColor4f(0, 0, 0, 0);
			glutWireCube(10);
		}
		glPopMatrix();
		// 오른쪽 다리
		GLfloat color_Rightleg[] = { 0.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_Rightleg);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 16);
		glPushMatrix();
		{
			glTranslatef(0, -30, -6);
			glTranslatef(0, 15, 0);
			glRotatef(Robot::angle, 0, 0, 1);
			glTranslatef(0, -15, 0);
			glScalef(1, 3, 1);
			glColor4f(0, 1, 1, 0);
			glutSolidCube(10);
			glColor4f(0, 0, 0, 0);
			glutWireCube(10);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

GLvoid Robot::move(unsigned char key)
{
	//if (key == 8)
	//{
	//	direction = 90;
	//	if (angle == 60)
	//		angle_add = false;
	//	if (angle == -60)
	//		angle_add = true;
	//	if (angle_add)
	//		angle += 10;
	//	else if (!angle_add)
	//		angle -= 10;

	//}
	//if (key == 2)
	//{
	//	direction = -90;
	//	if (angle == 60)
	//		angle_add = false;
	//	if (angle == -60)
	//		angle_add = true;
	//	if (angle_add)
	//		angle += 10;
	//	else if (!angle_add)
	//		angle -= 10;
	//}
	//if (key == 'a' || key == 'A')
	//{
	//	direction = 180;
	//	if (angle == 60)
	//		angle_add = false;
	//	if (angle == -60)
	//		angle_add = true;
	//	if (angle_add)
	//		angle += 10;
	//	else if (!angle_add)
	//		angle -= 10;
	//}
	//if (key == 'd' || key == 'D')
	//{
	//	direction = 0;
	//	if (angle == 60)
	//		angle_add = false;
	//	if (angle == -60)
	//		angle_add = true;
	//	if (angle_add)
	//		angle += 10;
	//	else if (!angle_add)
	//		angle -= 10;
	//}

	switch (key)
	{
	case 2:
		//	direction = -90;
		//	if (angle == 60)
		//		angle_add = false;
		//	if (angle == -60)
		//		angle_add = true;
		//	if (angle_add)
		//		angle += 10;
		//	else if (!angle_add)
		//		angle -= 10;
		glPushMatrix();
		{
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, 10.0f);
			glMultMatrixf(m_mtxLocal_trans);
			glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxLocal_trans);
		}
		glPopMatrix();
		glPushMatrix();//결과행렬만 만들라고 푸쉬팝씀.
		{
			glLoadIdentity();
			//행렬에 회전 적용
			glRotatef(-10.0f, 1.0f, 0.0f, 0.0f);//각도는 무조건 5도씩.그 전에있던 행렬을 5도씩돌림.
												//전에꺼처럼 각도로 한번에 돌리는게 아님.
												//구뿐만아니라 어디서든. 
			glMultMatrixf(m_mtxLocal);
			glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxLocal);//모델뷰에 사용할 매트릭스 행렬.현재행렬 가지고 오는거. 
														 //행렬 가져와서--> 결과 만들어주고--> 곱해줌. 
		}
		glPopMatrix();
		break;
	}
}