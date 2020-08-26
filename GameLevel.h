#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "Block.h"

using namespace std;


class GameLevel
{
	GLuint **Mtx;
	ifstream in;
	GLuint hg, Level, score = 0 , blocks = 0;
	
public:
	GLuint Swidth, SHeight, step;
	GLboolean IsComplete = GL_FALSE;
	GameLevel();
	~GameLevel();
	void Init(GLuint Width, GLuint Height,GLuint Steps);
	void LoadLevel(GLuint level);
	void Draw();
	GLboolean Collision(GLuint x, GLuint y, GLuint w);
	void PrintScore();
};

