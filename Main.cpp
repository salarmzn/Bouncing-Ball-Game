
#include <Windows.h>
#include "Game.h"


const GLuint Window_Width = 800;
const GLuint Window_Height = 700;
const GLuint Pos_x = 100;
const GLuint Pos_y = 10;
const GLuint step = 10;
const GLuint GameTime = 10 , BallTime = 50;
GLint W_key;
Game game(Window_Width, Window_Height, step);

void draw()
{
	game.Draw();
}
void special(int key, int x, int y)
{

	game.ProcessInput(key);
}

void Update(int value)
{
	if (GetAsyncKeyState(VK_RIGHT))
		special(GLUT_KEY_RIGHT,0,0);

	if (GetAsyncKeyState(VK_LEFT))
		special(GLUT_KEY_LEFT,0,0);

	game.Update();

	glutTimerFunc(GameTime, Update, 0);
	
}



void BallUpdate(int value)
{
	game.UpdateBall();
	glutTimerFunc(BallTime, BallUpdate, 0);
}


void keyboard(unsigned char key, int x, int y)
{

	/*int k = key;
	cout << k << endl;*/
	if (key == 32 && game.State == Game_Pause)
	{
		game.State = Game_Active;
		return;
	}
	game.ProcessInput(key);

	
	if (key == 's')
		game.State = Game_Win;

	if ((key == 'M' || key == 'm')&& game.State == Game_Active)
	{
		game.menu.Active = 3;
		game.State = Game_Menu;
	}
		
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(Pos_x, Pos_y);
	glutInitWindowSize(Window_Width, Window_Height);
	 W_key = glutCreateWindow("Salar Game");

	
	game.Init();
	game.State = Game_Active;
	glutDisplayFunc(draw);
	glutSpecialFunc(special);
	glutTimerFunc(GameTime, Update, 0);
	glutTimerFunc(BallTime,BallUpdate , 0);
	glutKeyboardFunc(keyboard);


	glutMainLoop();
	
	return 0;
}