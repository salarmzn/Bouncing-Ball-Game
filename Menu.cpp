#include "Menu.h"


Menu::Menu()
{
	
}


Menu::~Menu()
{
}

void Menu::init(GLuint w, GLuint h)
{
	Width = w;
	Height = h;

	NormalColor[0] = 0.823;
	NormalColor[1] = 0.941;
	NormalColor[2] = 0.274;

	ActiveColor[0] = 0.627;
	ActiveColor[1] = 0.98;
	ActiveColor[2] = 0.862;

	BorderColor[0] = 1.0;
	BorderColor[1] = 1.0;
	BorderColor[2] = 1.0;

	xmin = Width / 2 - 10;
	ymin = Height / 2 + 5;

}

void Menu::Draw()
{
	/// write Livs text
	char *items[3] = { "   Exit   ", "  Restart ", "  Resume  " };
	//*items[2]  = );
	//*items[1]  = ;
	//*items[0] = char("   Exit   ");
	

	for (int i = 0; i < 3; i++)
	{

		///Clear BacGround Of Text
		if (i + 1 == Active )
			glColor3fv(ActiveColor);
		else
			glColor3fv(NormalColor);


		glBegin(GL_QUAD_STRIP);
		{
			glVertex2f(xmin , ymin + i*ItemH);
			glVertex2f(xmin + ItemW, ymin + i*ItemH);
			glVertex2f(xmin , ymin + (i + 1)*ItemH);
			glVertex2f(xmin + ItemW, ymin + (i + 1)*ItemH);
		}
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(xmin + 5, ymin + i*ItemH + 1);

		for (int k = 0; k < 10 ; k++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, items[i][k]);
	}


}

void Menu::MoveUp()
{
	if (Active < 3)
	{
		Active++;
		Draw();
	}
		

}

void Menu::MoveDown()
{
	if (Active > 1)
	{
		--Active;
		Draw();
	}
}

GameState Menu::Selected()
{
	switch (Active)
	{
	case 3:
		return Game_Active;
		break;

	case 2:
		return Game_Over;
		break;

	case 1:
		return Game_Exit;
		break;
	default:
		return Game_Active;
		break;
	}
	
}


