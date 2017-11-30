#include "stdafx.h"
#include "BombEffect.h"

void Explosion_effect::init()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 59; j++)
			velocity[i][j] = 8 + rand() % 5;
	}
	velocity[59][59] = 6;
}

GLvoid Explosion_effect::draw(int xPos, int yPos, int zPos)
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat color[] = { 0.18f, 0.18f, 1.0f, 0.7f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			Particle_x[i][j] = ((Radius[i][j] * cos((j * 6)*RAD))*(cos((i * 6)*RAD))) + xPos;
			Particle_y[i][j] = ((Radius[i][j] * sin((i * 6)*RAD))) + yPos;
			Particle_z[i][j] = ((Radius[i][j] * sin((j * 6)*RAD))*(cos((i * 6)*RAD))) + zPos;
		}
	}

	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (!Particle_dead[i][j] && Explode)
			{
				glPushMatrix();
				glTranslatef(Particle_x[i][j], Particle_y[i][j], Particle_z[i][j]);
				glutSolidCube(3);
				glPopMatrix();
			}
		}
	}
}

GLvoid Explosion_effect::animation()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if ((Particle_x[i][j] < -60 || Particle_x[i][j] > 60)
				|| (Particle_z[i][j] < -60 || Particle_z[i][j] > 60)
				|| (Particle_y[i][j] < -60 || Particle_y[i][j] > 60))
			{
				Particle_dead[i][j] = true;
			}
			else
				Radius[i][j] += velocity[i][j];
		}
	}
	if (Particle_dead[59][59])
		Explode = false;

	if (!Explode)
	{
		for (int i = 0; i < 60; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				Radius[i][j] = 5;
				Particle_dead[i][j] = false;
			}
		}
	}
}