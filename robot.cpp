#include "stdafx.h"
#include "robot.h"


GLvoid Robot::draw()
{
	
	glPushMatrix();
	{
		//������
		glMultMatrixf(m_mtxLocal_trans);
		glMultMatrixf(m_mtxLocal);


		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTranslatef(Robot::x, Robot::y - 40, Robot::z);
		glRotatef(Robot::direction, 0, 1, 0);
		// ��ü
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
		// �Ӹ�
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
		// ��
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
		// ����
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
		// ������
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
		// ���� �ٸ�
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
		// ������ �ٸ�
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
		glPushMatrix();//�����ĸ� ������ Ǫ���˾�.
		{
			glLoadIdentity();
			//��Ŀ� ȸ�� ����
			glRotatef(-10.0f, 1.0f, 0.0f, 0.0f);//������ ������ 5����.�� �����ִ� ����� 5��������.
												//������ó�� ������ �ѹ��� �����°� �ƴ�.
												//���Ӹ��ƴ϶� ��𼭵�. 
			glMultMatrixf(m_mtxLocal);
			glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxLocal);//�𵨺信 ����� ��Ʈ���� ���.������� ������ ���°�. 
														 //��� �����ͼ�--> ��� ������ְ�--> ������. 
		}
		glPopMatrix();
		break;
	}
}