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
	MapInfo **arr;
public:
	Map();
	~Map() = default;

	void MapRender();
};