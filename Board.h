#pragma once
#include "Objects.h"


class Board :
	private Objects
{
private:
	
public:
	Board();
	~Board();
	void SetValues(GLuint x, GLuint y, GLuint width, GLuint height);
	void Draw();
	void MoveR();
	void MoveL();
	GLuint getX();
	GLint GetLengh();
	GLint getTop();

};



