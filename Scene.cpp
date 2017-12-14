#include "stdafx.h"
#include "Scene.h"

GLvoid Scene::drawlogo()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < Scene::logonum; ++j)
		{
			for (int k = 0; k < Scene::logonum; ++k)
			{
				if (t[i].arr[j][k] == 1)
				{

					glPushMatrix();
					{
						glColor3f(1, 0, 0);
						glTranslatef(-450 + i * 100 + 10 * k, 50 - 10 * j, 500);
						glTranslatef(logoTrans.x, logoTrans.y, logoTrans.z);
						glRotatef(logoAngle,0 , 1, 0);
						glutSolidCube(15);
					}
					glPopMatrix();
				}
			}
		}
	}

}
GLvoid Scene::Button()
{

}
void Scene::read()
{
	
		ifstream ifs{ "logoA.txt", ios::in };

		//for (int i = 0; i < 10; ++i)
		//	ifs.read(reinterpret_cast<char*>((t[i].arr)), sizeof (int)*num*num);
		char c;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < Scene::logonum; ++j)
			{
				for (int k = 0; k < Scene::logonum; ++k)
				{
					ifs >> t[i].arr[j][k];
				}
			}
			//ifs >> c;
		}
		ifs.close();

}