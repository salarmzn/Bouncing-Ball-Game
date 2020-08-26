#include <fstream>
#include "Ball.h"


Ball::Ball()
{
	this->Width = 2;
}


Ball::~Ball()
{
}


void Ball::init(GLfloat x, GLfloat y)
{
	glColor3f(0.0, 0.0, 0.0);
	this->doCirclefill(xmin, ymin, Width);

	this->xmin = x;
	this->xMax = x  + Width;
	this->ymin = y;
	this->yMax = y + Width;

	nx = 1;
	ny = 1;


}



void Ball::Draw()
{
	glColor3f(0.901, 0.752, 0.333);

	this->doCirclefill(xmin , ymin, Width);	
}

void Ball::Move()
{
	glColor3f(0.0, 0.0, 0.0);
	this->doCirclefill(xmin, ymin, Width);

	
	if ( this-> xmin + nx >=0 )
		this->xmin += nx;

	this->ymin += this->ny; 

	this->Draw();

}



void Ball::ChangeMovement(GLboolean x, GLboolean y)
{
	if (x == GL_TRUE)
		nx *= -1;

	if (y == GL_TRUE)
		ny *= -1;
}


GLuint Ball::getx()
{
	return this->xmin;
}


GLuint Ball::gety()
{
	return this->ymin;
}

GLuint Ball::getWidth()
{
	return Width;
}

GLboolean Ball::Additivex()
{
	if (nx > 0)
		return GL_TRUE;
	else
		return GL_FALSE;
}

GLboolean Ball::Additivey()
{
	if (ny > 0)
		return GL_TRUE;
	else
		return GL_FALSE;
}
