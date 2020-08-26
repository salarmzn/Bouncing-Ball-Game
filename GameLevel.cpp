#include "GameLevel.h"



GameLevel::GameLevel()
{
	
	
}


GameLevel::~GameLevel()
{
}

string int2str(GLint x) {
	// converts int to string
	stringstream ss;
	ss << x;
	return ss.str();
}

void GameLevel::Init(GLuint w, GLuint h,GLuint s)
{
	this->Swidth = w;
	this->SHeight = h;
	this->step = s;

	Mtx = new GLuint*[(SHeight / (step * 5))];
	for (GLuint i = 0; i < (SHeight / (step * 5)); i++)
	{
		Mtx[i] = new GLuint[((Swidth / (step * 5)) / 2)];
	}
}

void GameLevel::LoadLevel(GLuint level)
{
	

	string s = "Levels/" + int2str(level) + ".lvl";

	in.open(s);

	for (int i = 0; !in.eof() ; i++)
	{
		for (int j = 0; j < ((Swidth / (step * 5))); j++)
		{
			in >> Mtx[i][j];
			if (Mtx[i][j] == 1)
				blocks++;
		}
		hg = i;
	}

	in.close();
	Level = level;
	
	if (level == 1)
	{
		score = 0;
	}
	IsComplete = GL_FALSE;
	
}

void GameLevel::Draw()
{
	for (int i = 0; i<=hg ; i++)
	{
		for (int j = 0; j < (Swidth/(step*5)); j++)
		{
			
			GLuint 
				xmin = j * 5, 
				xMax = j * 5 + 4, 
				ymin = ((SHeight / step) - (i * 5)), 
				yMax = ((SHeight / step) - (i * 5 + 4));

			Block block(xmin, xMax, ymin, yMax);

			switch (Mtx[i][j])
			{
			case 0:
				block.Kind = empti;
				break;
			case 1:
				block.Kind = normal;
				
				break;
			case 2:
				block.Kind = stone;
				break;
				
			default:
				break;
			} 
			block.Draw();
		}
	}

	PrintScore();
}

GLboolean GameLevel::Collision(GLuint x, GLuint y, GLuint w)
{
	GLuint top =( ((SHeight / step) - y) / 5) + 1 ;

	//cout << y << "  " << top << endl;

	if (top <= this->hg + 1)
	{
		GLuint right = (x + w) / 5, left = (x - w) / 5;


		if (Mtx[top - 1][right] == 1)
		{	
			this->Mtx[top - 1][right] = 0;
			Block block(x, x + 4, y, y + 4);
			block.Kind = empti;
			block.Draw();
			score++;
			--blocks;
			//IsComplete = GL_TRUE;
			PrintScore();
			
			cout << x << "  " << y << "  " << w << "\n";
			return GL_TRUE;
			cout << "Yes  = 1 , y =" << y << "\n";
		}

		else if (Mtx[top - 1][right] == 2)
		{
			cout << x << "  " << y << "  " << w << "\n";
			
			return GL_TRUE;
			cout << "Yes  = 2 , y =" << y << "\n";
		}
		else
		{
			//cout << x << "  " << y << "  " << w << "\n";
			return GL_FALSE;
		}
		{
			cout << "Yes  = 0 , y =" << y << "\n";
		}

		if (blocks == 0)
			IsComplete = GL_TRUE;
	}
	
	return GL_FALSE;
}


void GameLevel::PrintScore()
{
	/// write Score text
	char ScoreText[] = "Score : 0000 ";
	GLint score1 = score % 10;
	GLint score2 = GLint(score / 10) % 10;
	GLint score3 = GLint(score / 100) % 10;
	GLint score4 = score / 1000;
	ScoreText[11] = score1 + 48;
	ScoreText[10] = score2 + 48;
	ScoreText[9] = score3 + 48;
	ScoreText[8] = score4 + 48;

	/// write Level text
	char LevelText[] = "Level : 00 ";
	GLint level1 = Level % 10;
	GLint level2 = Level / 10;

	LevelText[9] = level1 + 48;
	LevelText[8] = level2 + 48;


	//Draw Border
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	{
		glVertex2f(3, 5);
		glVertex2f(3, 0.8);
		glVertex2f(17, 0.8);
		glVertex2f(17, 5);


	}
	glEnd();


	///Clear BacGround Of Text
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	{
		glVertex2f(3.2, 1);
		glVertex2f(3.2, 5);
		glVertex2f(16.8, 1);
		glVertex2f(16.8, 5);
	}
	glEnd();


	glColor3f(0.8, 0.0, 0.0);
	glRasterPos2f(5, 2);
	for (int k = 0; k < 13; k++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ScoreText[k]);

	glColor3f(0.3, 0.0, 0.9);
	glRasterPos2f(5, 3.7);
	for (int k = 0; k < 13; k++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, LevelText[k]);


}