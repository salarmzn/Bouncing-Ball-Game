#include "Block.h"


Block::Block(GLuint x1, GLuint x2, GLuint y1, GLuint y2)
{
	this->xmin = x1;
	this->xMax = x2;
	this->ymin = y1;
	this->yMax = y2;

	this->NormalColor[0] = 0.359;
	this->NormalColor[1] = 0.784;
	this->NormalColor[2] = 0.784;

	this->StoneColor[0] = 0.745;
	this->StoneColor[1] = 0.784;
	this->StoneColor[2] = 0.784;
}


Block::~Block()
{

}

void Block::Draw()
{
	switch (Kind)
	{
	case empti:
		glColor3fv(BackgrounColor);
		glBegin(GL_QUAD_STRIP);
		{
			glVertex2i(this->xmin, this->ymin);
			glVertex2i(this->xmin, this->yMax);
			glVertex2i(this->xMax, this->ymin);
			glVertex2i(this->xMax, this->yMax);
		}
		glEnd();
		break;
	case normal:
		glColor3fv(NormalColor);
		glBegin(GL_QUAD_STRIP);
		{
			glVertex2i(this->xmin, this->ymin);
			glVertex2i(this->xmin, this->yMax);
			glVertex2i(this->xMax, this->ymin);
			glVertex2i(this->xMax, this->yMax);
		}
		glEnd();
		break;
	case stone:
		glColor3fv(StoneColor);
		glBegin(GL_QUAD_STRIP);
		{
			glVertex2i(this->xmin, this->ymin);
			glVertex2i(this->xmin, this->yMax);
			glVertex2i(this->xMax, this->ymin);
			glVertex2i(this->xMax, this->yMax);
		}
		glEnd();
		break;
	default:
		break;
	}

}
