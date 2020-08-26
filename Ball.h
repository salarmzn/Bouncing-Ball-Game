#pragma once
#include "Objects.h"



using namespace std;
class Ball :
	private Objects
{

private:
	
	GLint nx,ny; //Next_x ,Next_y
	
public:
	Ball();
	~Ball();
	
	void init(GLfloat xmin, GLfloat ymin);
	void Move();
	void ChangeMovement(GLboolean x, GLboolean y);
	void Draw();
	GLuint getx();
	GLuint gety();
	GLuint getWidth();
	GLboolean Additivex();
	GLboolean Additivey();
};

