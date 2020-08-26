#pragma once

#include <GL\glut.h>

enum GameState{
	Game_Active,
	Game_Menu,
	Game_Win,
	Game_Over,
	Game_Exit,
	Game_Pause
};


class Menu
{
	GLfloat ActiveColor[3];
	GLfloat NormalColor[3];
	GLfloat BorderColor[3];
	char item1[10];
	char item2[10];
	char item3[10];
	char item4[10];
	char item5[10];
	char item6[10];

	//char *text[] = {"salar" , "MZn"};
	GLuint Width, Height;
	GLuint ItemW = 20, ItemH = 4,xmin,ymin;
	
public:
	GLuint Active = 3;
	Menu();
	~Menu();
	void init(GLuint width, GLuint hright);
	void Draw();
	void MoveUp();
	void MoveDown();
	GameState Selected();

};

