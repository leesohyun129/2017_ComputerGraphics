#pragma once

struct MapInfo
{
	Vector3D Map_pos;
	float size;
};
class Map
{
private:
	int mapSize;
public:
	MapInfo **arr;
	Map();
	~Map() = default;
	bool isBomb[15][15];
	bool Explode[15][15];

	void MapRender();
};