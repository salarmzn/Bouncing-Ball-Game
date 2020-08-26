#include "Game.h"



Game::Game(GLuint w,GLuint h,GLuint s)
{
	
	this->Width = w;
	this->Height = h;
	this->Step = s;

}


Game::~Game()
{


}

void Game::Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, this->Width / this->Step, 0, this->Height / this->Step);

	Lives = 2;
	Level = 1;

	gamelevel.Init(Width, Height, Step);
	
	gamelevel.LoadLevel(Level);

	board.SetValues((this->Width / 20) - 5, 10, 10, 2);


	ball.init(this->board.getX()  + (this->board.GetLengh() /2), board.getTop() + ball.getWidth());

	menu.init(Width / Step, Height / Step);
}

void Game::Draw()
{
	switch (State)
	{
	case Game_Active:
		GameActive();
		break;
	case Game_Pause:
		GameActive();
		break;
	case Game_Menu:
		GameMenu();
		break;
	case Game_Win:
		GameWin();
		break;
	case Game_Over:
		GameOver();
		break;
	case Game_Exit:
		exit(0);
		break;
	default:
		break;
	}

}


void Game::ProcessInput(int key)
{

	switch (State)
	{
	case Game_Active:
		switch (key)
		{
		case GLUT_KEY_RIGHT:

			if ((board.getX() + 12) <= Width / 10)
				board.MoveR();
			break;

		case GLUT_KEY_LEFT:
			if (board.getX() != 0)
				board.MoveL();
			break;
		case 32:
			State = Game_Pause;
			
		default:
			break;
		}
		break;
	case Game_Menu:
		switch (key)
		{
		case GLUT_KEY_UP:
			menu.MoveUp();
			break;

		case GLUT_KEY_DOWN:
			menu.MoveDown();
			break;

		case 13:
			State = menu.Selected();
			if (State == Game_Over)
			{
				this->Init();
				State = Game_Active;
			}
				
			break;
		default:
			break;
		}
		break;
	case Game_Win:
		GameWin();
		break;
	case Game_Over:
		if (key == 13)
		{
			this->Init();
			State = Game_Active;
		}
		break;
	default:
		break;
	}
	

}

void Game::UpdateBall()
{
	if (this->State == Game_Active)
	{
		ball.Move();


		GLuint x = this->ball.getx();
		GLuint y = this->ball.gety();

		GLboolean r = GL_FALSE, t = GL_FALSE;
		//ball.Move(1,1);


		/*********************Hit To Board*********************************/

		if (y - ball.getWidth() <= this->board.getTop() && y - (ball.getWidth() / 2) >= this->board.getTop())
		{
			

			if (x + this->ball.getWidth() >= this->board.getX() && x < this->board.getX() && this->ball.Additivex())
			{
				t = GL_TRUE;
				r = GL_TRUE;

			}

			if ((x > this->board.getX() + this->board.GetLengh()) &&
				(x - this->ball.getWidth() <= this->board.getX() + this->board.GetLengh())
				&& !this->ball.Additivex())
			{
				t = GL_TRUE;
				r = GL_TRUE;

			}

			if (x >= this->board.getX() && x <= this->board.getX() + this->board.GetLengh())
			{
				t = GL_TRUE;

			}
		}

		/*********************Hit To Block*********************************/

		if (gamelevel.IsComplete == GL_TRUE)
			State = Game_Win;

		if (this->gamelevel.Collision(x, y + ball.getWidth(), this->ball.getWidth()))
		{
			t = GL_TRUE;
			//State = Game_Menu;
			//cout << 1 << endl;
		}

		if (this->gamelevel.Collision(x, y - ball.getWidth() + 1, this->ball.getWidth()))
		{
			t = GL_TRUE;
			//State = Game_Menu;
			//cout << 2 << endl;
		}

		if (this->gamelevel.Collision(x + ball.getWidth() - 1, y, this->ball.getWidth()))
		{
			r = GL_TRUE;
			//State = Game_Menu;
			//cout << 3 << endl;
		}

		if (this->gamelevel.Collision(x - ball.getWidth() - 1, y, this->ball.getWidth()))
		{
			r = GL_TRUE;
			//State = Game_Menu;
			//cout << 4 << endl;
		}


		/**********************Hit To Wall*****************************/

		if (y + this->ball.getWidth() > (Height / Step))//Top Wall
		{
			t = GL_TRUE;

		}

		if (y + 3 * this->ball.getWidth() <= this->board.getTop())//Bottom
		{
			--Lives;
			if (Lives == 0)
			{
				State = Game_Over;
				return;
			}
			


			PrintLives();

			ball.init(this->board.getX() + (this->board.GetLengh() / 2) - 1, board.getTop() + ball.getWidth() - 1);
			this->ball.Move();
			this->State = Game_Pause;
			//Sleep();

		}

		if (x + this->ball.getWidth() + 1 > (Width / Step) || x - this->ball.getWidth() <= 0)//Left And Right Wall
		{
			r = GL_TRUE;

		}
		ball.ChangeMovement(r, t);


	}

}

void Game::Update()
{
	// Redisplay frame
	glutPostRedisplay();
		

}


void Game::PrintLives()
{

	/// write Livs text
	char LivesText[] = "Lives : 00 ";
	GLint level2 = Lives % 10;
	GLint level1 = Lives / 10;

	LivesText[8] = level1 + 48;
	LivesText[9] = level2 - 1 + 48;


	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	{
		glVertex2f(3, 5);
		glVertex2f(3, 7.4);
		glVertex2f(17, 7.4);
		glVertex2f(17, 5);


	}
	glEnd();

	///Clear BacGround Of Text
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex2f(3.2, 5);
		glVertex2f(3.2, 7);
		glVertex2f(16.8, 5);
		glVertex2f(16.8, 7);
	}
	glEnd();

	glColor3f(0.0, 1.0, 0.8);
	glRasterPos2f(5, 5.5);

	for (int k = 0; k < 13; k++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, LivesText[k]);
}

void Game::GameActive()
{	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	this->gamelevel.Draw();

	board.Draw();
	
	ball.Draw();

	PrintLives();

	glFlush();
}



void Game::GameOver()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	char Text[] = " ***** Game Over ***** ";

	glColor3f(0.5, 0.5, 0.8);
	glRasterPos2f(Width / (Step * 2) - 15, Height / (Step * 2));

	for (int k = 0; k < 23; k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Text[k]);


	glFlush();
	
}

void Game::GameMenu()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	menu.Draw();
	glFlush();
}

void Game::GameWin()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	char Text[] = " You Win Level ";
	char ch = Level + 48;
	glColor3f(0.5, 0.5, 0.8);
	glRasterPos2f(Width / (Step * 2) - 15, Height / (Step * 2));

	for (int k = 0; k < 23; k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Text[k]);
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ch);

	

	glFlush();
	Sleep(2000);
	Level++;
	gamelevel.LoadLevel(Level);
	board.SetValues((this->Width / 20) - 5, 10, 10, 2);
	ball.init(this->board.getX() + (this->board.GetLengh() / 2), board.getTop() + ball.getWidth());
	State = Game_Active;
}