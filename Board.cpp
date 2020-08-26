#include "Board.h"


Board::Board()
{
	
}


Board::~Board()
{

}

void Board::SetValues(GLuint x, GLuint y, GLuint w, GLuint h)
{
	this->xmin = x;
	this->ymin = y;
	this->Width = w;
	this->Height = h;
}



void Board::Draw()
{
	glColor3f(0.627, 0.333, 0.333);

	doCirclefill(this->xmin + this->Height / 2, this->ymin + this->Height / 2, this->Height/2);
	doCirclefill(this->xmin + this->Width - this->Height / 2, this->ymin + this->Height / 2, this->Height / 2);

	glBegin(GL_QUAD_STRIP);
	{
		glVertex2d(this->xmin + this->Height / 2, this->ymin);
		glVertex2i(this->xmin + this->Height / 2, this->ymin + Height);
		glVertex2i(this->xmin + this->Width - this->Height / 2, this->ymin);
		glVertex2i(this->xmin + this->Width - this->Height / 2, this->ymin + this->Height);
	}
	glEnd();
}

void Board::MoveR()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex2i(this->xmin, this->ymin);
		glVertex2i(this->xmin, this->ymin + Height);
		glVertex2i(this->xmin + this->Width, this->ymin);
		glVertex2i(this->xmin + this->Width, this->ymin + this->Height);
	}
	glEnd();

	this->xmin++;
	this->Draw();
	
}

void Board::MoveL()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex2i(this->xmin, this->ymin);
		glVertex2i(this->xmin, this->ymin + Height);
		glVertex2i(this->xmin + this->Width, this->ymin);
		glVertex2i(this->xmin + this->Width, this->ymin + this->Height);
	}
	glEnd();

	this->xmin--;
	this->Draw();
}

GLuint Board::getX()
{
	return this->xmin;
}

GLint Board::GetLengh()
{
	return this->Width;
}

GLint Board::getTop()
{
	return this->ymin + this->Height;
}