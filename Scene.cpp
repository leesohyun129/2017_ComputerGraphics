#include "stdafx.h"
#include "Scene.h"


GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info)
{
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	if ((fp = fopen(filename, "rb")) == NULL)return NULL;
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) { fclose(fp); return NULL; }
	if (header.bfType != 'MB') { fclose(fp); return NULL; }
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	if ((*info = (BITMAPINFO*)malloc(infosize)) == NULL) { fclose(fp); exit(0); return NULL; }
	if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) { free(*info); fclose(fp); return NULL; }
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth*((*info)->bmiHeader.biHeight)) * 3;
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) { free(*info); fclose(fp); return NULL; }
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) { free(*info); free(bits); fclose(fp); return NULL; }
	fclose(fp);
	return bits;
}
GLvoid Scene::control()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);

		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.5);

			glTexCoord2f(0, 1);
			glVertex3f(-900, 700, 0);

			glTexCoord2f(0, 0);
			glVertex3f(-900, -700, 0);

			glTexCoord2f(1, 0);
			glVertex3f(900, -700, 0);

			glTexCoord2f(1, 1);
			glVertex3f(900, 700, 0);
		}
		glEnd();
	}
	glPopMatrix();
}
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
	//button: gamestart
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);

		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.5);

			glTexCoord2f(0, 1);
			glVertex3f(-150, button_top, 0);
			
			glTexCoord2f(0, 0);
			glVertex3f(-150, button_bottom, 0);
			
			glTexCoord2f(1, 0);
			glVertex3f(150, button_bottom, 0);
			
			glTexCoord2f(1, 1);
			glVertex3f(150, button_top, 0);
		}
		glEnd();
	}
	glPopMatrix();

	//button: quit
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[1]);

		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.5);

			glTexCoord2f(0, 1);
			glVertex3f(-500, button_top, 0);

			glTexCoord2f(0, 0);
			glVertex3f(-500, button_bottom, 0);

			glTexCoord2f(1, 0);
			glVertex3f(-300, button_bottom, 0);

			glTexCoord2f(1, 1);
			glVertex3f(-300, button_top, 0);
		}
		glEnd();
	}
	glPopMatrix();

	//button: help
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);

		glBegin(GL_QUADS);
		{
			glColor4f(1, 1, 1, 0.5);

			glTexCoord2f(0, 1);
			glVertex3f(300, button_bottom, 0);

			glTexCoord2f(0, 0);
			glVertex3f(300, button_top, 0);

			glTexCoord2f(1, 0);
			glVertex3f(500, button_top, 0);

			glTexCoord2f(1, 1);
			glVertex3f(500, button_bottom, 0);
		}
		glEnd();
	}
	glPopMatrix();
}
void Scene::setTexture()
{
	glGenTextures(6, texture);
	textureBits_Start = LoadDIBitmap("GAMESTART.bmp", &gamestart_Info);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, gamestart_Info->bmiHeader.biWidth, gamestart_Info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, textureBits_Start);

	textureBits_Quit = LoadDIBitmap("QUIT.bmp", &quit_Info);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, quit_Info->bmiHeader.biWidth, quit_Info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, textureBits_Quit);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	textureBits_Help = LoadDIBitmap("HELP.bmp", &help_Info);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, help_Info->bmiHeader.biWidth, help_Info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, textureBits_Help);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	textureBits_Control = LoadDIBitmap("helptemp.bmp", &control_Info);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, control_Info->bmiHeader.biWidth, control_Info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, textureBits_Control);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

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