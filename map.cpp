#include "stdafx.h"
#include "Map.h"

Map::Map() : mapSize(15)
{
	arr = new MapInfo*[mapSize];
	//mapinfo 주소가르키는 포인터 mapsize만큼 할당
	for (int i = 0; i < mapSize; ++i)
	{
		arr[i] = new MapInfo[mapSize];
		for (int j = 0; j < mapSize; ++j)
			arr[i][j].Map_pos = Vector3D{ static_cast<float>(i * 20) - 140, 0.0f, static_cast<float>(j * 20) - 140 };
	}
	//각배열 가리키는 포인터에 배열 할당
}
void Map::MapRender()
{
	
	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			/*cout << arr[i][j].Map_pos.x << " " << arr[i][j].Map_pos.y << " " << arr[i][j].Map_pos.z << endl;*/
			glPushMatrix();
			{
				glTranslatef(0, -60, 0);
				Vector3D pos = arr[i][j].Map_pos;
				(i+j) % 2 == 0 ? glColor3f(1.0f, 1.0f, 0.0f) : glColor3f(0.0f, 0.0f, 0.0f);
				glTranslatef(pos.x, pos.y, pos.z);
				glutSolidCube(20);
			}
			glPopMatrix();
		}
	}
}