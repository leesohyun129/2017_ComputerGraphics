#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	arr = new MapInfo*[mapSize];
	//mapinfo 주소가르키는 포인터 mapsize만큼 할당
	for (int i = 0; i < mapSize; ++i)
		arr[i] = new MapInfo[mapSize];
	//각배열 가리키는 포인터에 배열 할당
}
void Map::MapRender()
{
	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			cout << arr[i][j].Map_pos.x << endl;
			
		}
	}
}