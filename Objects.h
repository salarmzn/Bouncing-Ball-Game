#pragma once
#include <iostream>
#include <GL\glut.h>

class Objects
{
protected:
	GLuint xmin, xMax, ymin, yMax, Width, Height;
	GLfloat BackgrounColor[3];
public:	
	Objects();
	~Objects();
	void doCirclefill(double x, double y, double radius);
};
