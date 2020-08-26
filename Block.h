#pragma once
#include "Objects.h"

enum BlockKind{
	empti,
	normal,
	stone
};

class Block :
	public Objects
{
	GLfloat NormalColor[3];
	GLfloat StoneColor[3];
public:
	Block(GLuint xmin,GLuint xMax ,GLuint ymin,GLuint yMax);
	BlockKind Kind;
	~Block();
	void Draw();
};

