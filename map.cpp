#include "stdafx.h"
#include "Map.h"

Map::Map() : mapSize(60)
{
	arr = new MapInfo*[mapSize];
	//mapinfo �ּҰ���Ű�� ������ mapsize��ŭ �Ҵ�
	for (int i = 0; i < mapSize; ++i)
	{
		arr[i] = new MapInfo[mapSize];
		for (int j = 0; j < mapSize; ++j)
			arr[i][j].Map_pos = Vector3D{ static_cast<float>(j), static_cast<float>(i), 0.0f };
	}
	//���迭 ����Ű�� �����Ϳ� �迭 �Ҵ�
}
void Map::MapRender()
{
	//ũ�� 1ť�� ���� 30 ����30 -->900
	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			//cout << arr[i][j].Map_pos.x << " " << arr[i][j].Map_pos.y << " " << arr[i][j].Map_pos.z << endl;
			glPushMatrix();
			{
				glTranslatef(-25, -10, 20);
				glRotatef(75, 1.0, 0.0, 0.0);
				Vector3D pos = arr[i][j].Map_pos;
				(i+j) % 2 == 0 ? glColor3f(1.0f, 1.0f, 0.0f) : glColor3f(0.0f, 0.8f, 0.8f);
				glTranslatef(pos.x, pos.y, pos.z);
				glutSolidCube(1);

			}
			glPopMatrix();
		}
	}
}