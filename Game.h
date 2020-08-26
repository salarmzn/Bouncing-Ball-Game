#pragma once
#include <iostream>
#include <Windows.h>
#include "GameLevel.h"
#include "Board.h"
#include "Ball.h"
#include "Menu.h"


using namespace std;



class Game
{
public:
	Game(GLuint width,GLuint height,GLuint step);
	~Game();
	GameState State;
	GLboolean keys[1024];
	GLuint Width, Height, Step;
	GLuint Level = 1, Lives = 2;
	GameLevel gamelevel;
	Ball ball;
	Board board;
	Menu menu;

	void Init();

	// GameLoop
	void ProcessInput(int key);
	void Update();
	void UpdateBall();
	void Draw();
	void GameActive();
	void PrintLives();
	void GameMenu();
	void GameOver();
	void GameWin();
	

};

