#include "Objects.h"


Objects::Objects()
{
	BackgrounColor[0] = 0.0;
	BackgrounColor[1] = 0.0;
	BackgrounColor[2] = 0.0;
	//this->X = x;
	//this->Y = y;
}


Objects::~Objects()
{
}


void Objects::doCirclefill(double x, double y, double radius)
{
	// TODO: Set to specified texture if necessary
	//glEnable(GL_BLEND);
	//glColor4ub((GLubyte)color.red, (GLubyte)color.green, (GLubyte)color.blue, (GLubyte)color.alpha);
	double y1 = y;
	double x1 = x;
	glBegin(GL_TRIANGLES);
	for (int i = 0; i <= 360; i++)
	{
		double angle = (float)(((double)i) / 57.29577957795135);
		double x2 = x + (radius*(float)sin((double)angle));
		double y2 = y + (radius*(float)cos((double)angle));
		glVertex2d(x, y);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		y1 = y2;
		x1 = x2;
	}
	glEnd();
//	glDisable(GL_BLEND);
}