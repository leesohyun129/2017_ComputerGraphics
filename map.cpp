#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	arr = new MapInfo*[mapSize];
	//mapinfo �ּҰ���Ű�� ������ mapsize��ŭ �Ҵ�
	for (int i = 0; i < mapSize; ++i)
		arr[i] = new MapInfo[mapSize];
	//���迭 ����Ű�� �����Ϳ� �迭 �Ҵ�
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