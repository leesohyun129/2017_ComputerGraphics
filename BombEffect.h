#pragma once

#define PI 3.1415926535897
#define RAD PI / 180

class Explosion_effect {
public:
	float Particle_x[60][60];
	float Particle_y[60][60];
	float Particle_z[60][60];
	bool Explode = true;
	bool Particle_dead[60][60] = { false };
	int count = 0;
	int Radius[60][60] = { 5 };
	int velocity[60][60];

	GLvoid draw(int xPos, int yPos, int zPos);
	GLvoid animation();
	void init();
};