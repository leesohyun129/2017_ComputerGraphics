#include "stdafx.h"
#include "airplane.h"

GLvoid Airplane::draw()
{
	glPushMatrix();
	{
		GLfloat color[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 64);
		// ¸öÃ¼
		{
			glPushMatrix();
			glTranslatef(20, 0, 0);
			glScalef(5, 1, 1);
			glutSolidCube(40);
			glPopMatrix();
		}
		// ¾Õ
		{
			glColor3f(1.0, 0.5, 0.0);
			for (int i = 0; i < 4; i++)
			{
				glPushMatrix();
				{
					glRotatef(90 * i, 1, 0, 0);
					glTranslatef(-80, 20, 0);
					glRotatef(13.05, 0, 0, 1);
					glBegin(GL_QUADS);
					glVertex3f(-70, 0, -5);
					glVertex3f(-70, 0, 5);
					glVertex3f(0, 0, 20);
					glVertex3f(0, 0, -20);
					glEnd();
				}
				glPopMatrix();
			}
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			{
				glTranslatef(-148, 0, 0);
				glutSolidSphere(2, 20, 20);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glColor3f(1.0, 0.0, 0.0);
				glBegin(GL_QUADS);
				glVertex3f(-148, 2, 25);
				glVertex3f(-148, 2, -25);
				glVertex3f(-148, -2, -25);
				glVertex3f(-148, -2, 25);
				glEnd();
				glBegin(GL_QUADS);
				glVertex3f(-148, 25, 2);
				glVertex3f(-148, -25, 2);
				glVertex3f(-148, -25, -2);
				glVertex3f(-148, 25, -2);
				glEnd();
			}
			glPopMatrix();
		}
		// ³¯°³
		{
			glColor3f(0.5, 1.0, 0.0);
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 20);
				glVertex3f(60, 10, 20);
				glVertex3f(70, 0, 200);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, 20);
				glVertex3f(60, -10, 20);
				glVertex3f(70, 0, 200);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(60, -10, 20);
				glVertex3f(60, 10, 20);
				glVertex3f(70, 0, 200);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, -20);
				glVertex3f(60, 10, -20);
				glVertex3f(70, 0, -200);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, 0, -20);
				glVertex3f(60, -10, -20);
				glVertex3f(70, 0, -200);
				glEnd();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(-30, 0, 0);
				glBegin(GL_TRIANGLES);
				glVertex3f(60, -10, -20);
				glVertex3f(60, 10, -20);
				glVertex3f(70, 0, -200);
				glEnd();
			}
			glPopMatrix();
		}
		// µÚ
		{
			glPushMatrix();
			{
				glColor3f(0.0, 1.0, 0.0);
				glBegin(GL_QUADS);
				glVertex3f(120, 20, -20);
				glVertex3f(120, 20, 20);
				glVertex3f(170, 20, 10);
				glVertex3f(170, 20, -10);
				glEnd();

				glBegin(GL_TRIANGLES);
				glVertex3f(120, 20, 20);
				glVertex3f(120, -20, 20);
				glVertex3f(170, 20, 10);
				glEnd();

				glBegin(GL_TRIANGLES);
				glVertex3f(120, 20, -20);
				glVertex3f(120, -20, -20);
				glVertex3f(170, 20, -10);
				glEnd();

				glPushMatrix();
				{
					glColor3f(0.0, 0.7, 0.0);
					glBegin(GL_QUADS);
					glVertex3f(120, -20, -20);
					glVertex3f(120, -20, 20);
					glVertex3f(170, 20, 10);
					glVertex3f(170, 20, -10);
					glEnd();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		// µÞ³¯°³
		{
			glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3f(120, 20, 0);
			glVertex3f(160, 20, 0);
			glVertex3f(170, 50, 0);
			glVertex3f(150, 50, 0);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(120, 15, 20);
			glVertex3f(160, 15, 10);
			glVertex3f(170, 15, 70);
			glVertex3f(150, 15, 70);
			glEnd();
			glBegin(GL_QUADS);
			glVertex3f(120, 15, -20);
			glVertex3f(160, 15, -10);
			glVertex3f(170, 15, -70);
			glVertex3f(150, 15, -70);
			glEnd();
			glPopMatrix();
		}
	}
	glPopMatrix();
}