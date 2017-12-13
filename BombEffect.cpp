#include "stdafx.h"
#include "BombEffect.h"

void Explosion_effect::init()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			Particle_x[i][j] = 0;
			Particle_y[i][j] = 0;
			Particle_z[i][j] = 0;
			velocity[i][j] = 1.6 + (float)(rand() % 30) / 10.0f;
			Radius[i][j] = 0;
			Particle_dead[i][j] = false;
		}
	}
	Explode = false;
	velocity[29][29] = 1.5;
}

GLvoid Explosion_effect::draw(Vector3D pos)
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat color[] = { 0.18f, 0.18f, 1.0f, 0.7f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	glColor4f(0.18, 0.18, 1.0, 1.0);
	if (Explode)
	{
		glPushMatrix();
		{
			glTranslatef(0, 0, 0);
			glTranslatef(pos.x, -40, pos.z);
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					Particle_x[i][j] = ((Radius[i][j] * cos((j * 12)*RAD))*(cos((i * 12)*RAD)));
					Particle_y[i][j] = ((Radius[i][j] * sin((i * 12)*RAD)));
					Particle_z[i][j] = ((Radius[i][j] * sin((j * 12)*RAD))*(cos((i * 12)*RAD)));
				}
			}

			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					if (!Particle_dead[i][j])
					{
						glPushMatrix();
						glTranslatef(Particle_x[i][j], Particle_y[i][j], Particle_z[i][j]);
						glutSolidCube(1);
						glPopMatrix();
					}
				}
			}
		}
		glPopMatrix();
	}
}

GLvoid Explosion_effect::animation()
{
	if (Explode)
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if ((Particle_x[i][j] < -10 || Particle_x[i][j] > 10)
					|| (Particle_z[i][j] < -10 || Particle_z[i][j] > 10)
					|| (Particle_y[i][j] < -10 || Particle_y[i][j] > 10))
				{
					Particle_dead[i][j] = true;
				}
				else
					Radius[i][j] += velocity[i][j];
			}
		}
	}
	if (Particle_dead[29][29])
	{
		Explode = false;
		init();
	}
}

GLvoid Bomb::draw(Vector3D pos)
{
	glPushMatrix();
	{
		GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat color_bomb[] = { 0.2f, 0.2f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_bomb);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMateriali(GL_FRONT, GL_SHININESS, 64);
		glColor4f(0.2, 0.2, 1.0, 1.0);
		glTranslatef(0, 0, 0);
		glTranslatef(pos.x, y, pos.z);
		glPushMatrix();
		{
			glutSolidSphere(10, 20, 20);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(0, 10, 0);
			glRotatef(90, 1, 0, 0);
			glutSolidTorus(2, 1.5, 25, 15);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Bomb::init()
{
	y = 400;
	velocity = rand() % 25 + 5;
	range =/* rand() % 3 +*/ 3;
	isdraw = true;
	isfalling = true;
	count = 0;
}