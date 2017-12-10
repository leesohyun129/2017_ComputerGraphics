#pragma once

#define PI 3.1415926535897
#define RAD PI / 180

class Explosion_effect {
public:
	float Particle_x[60][60];
	float Particle_y[60][60];
	float Particle_z[60][60];
	bool Explode = false;
	bool Particle_dead[60][60] = { false };
	float Radius[60][60] = { 0 };
	float velocity[60][60];

	GLvoid draw(Vector3D pos);
	GLvoid animation();
	void init();
};

class Bomb {
public:
	float x;
	float y = 400;
	float z;

	bool isdraw;
	bool isfalling;
	bool Explode;
	int count = 0;
	int range;
	int velocity;

	GLvoid draw(Vector3D pos);
	void init();
};