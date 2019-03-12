#include "PointSlidingGame.hpp"

PointSlidingGame::PointSlidingGame(std::uint8_t puzzleSize, std::uint16_t gridSize, std::uint16_t goalScore)
	:BlockBasedGame(puzzleSize, gridSize)
{
	this->goalScore = goalScore;
	//Randomize for starting positions
	int xRand1 = rand() % puzzleSize;
	int yRand1= rand() % puzzleSize;
	int xRand2 = rand() % puzzleSize;
	int yRand2 = rand() % puzzleSize;

	this->gameGrid[xRand1][yRand1] = new Block(xRand1 * 100, yRand1 * 100, 2, 0, 0, 0);
	this->gameGrid[xRand2][yRand2] = new Block(xRand2 * 100, yRand2 * 100, 2, 0, 0, 0);

	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			std::cout << gameGrid[i][j] << std::endl;
		}
	}
}

PointSlidingGame::~PointSlidingGame()
{
	// statisk
}

void PointSlidingGame::MoveUp()
{
	//Funktionerna bör nog uppdatera x/y-medelsmvariabel också.

	//move
	int sideSize = this->GetPuzzleSize();
	bool moved = false;
	bool added = false;
	int randY, randX, newVal = 0;
	int maxVal = sideSize - 1;

	for (int i = 0; i < sideSize; i++)
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = sideSize-1; j >= 1; j--)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j - 1] == nullptr)
				{
					gameGrid[i][j - 1] = new Block(i * 100, (j - 1) * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	//add
	for (int i = 0; i < sideSize; i++)
	{
		for (int j = sideSize-1; j >= 1; j--)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j - 1] != nullptr)
				{
					if (gameGrid[i][j]->GetValue() == gameGrid[i][j - 1]->GetValue())
					{
						newVal = gameGrid[i][j]->GetValue();
						newVal = newVal + newVal;
						gameGrid[i][j]->SetValue(newVal);
						delete this->gameGrid[i][j-1];
						gameGrid[i][j-1] = nullptr;
					}
				}
			}
		}
	}
	//move
	for (int i = 0; i < sideSize; i++)
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = sideSize - 1; j >= 1; j--)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j - 1] == nullptr)
				{
					gameGrid[i][j - 1] = new Block(i * 100, (j-1) * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	for (int i = 0; i < 20 && added == false; i++)
	{
		srand(time(NULL));
		randX = rand() % maxVal + 0;
		randY = rand() % maxVal + 0;
		std::cout << "randX: " << randX << "\nrandy: " << randY << std::endl;
		if (gameGrid[randX][randY] == nullptr)
		{
			this->gameGrid[randX][randY] = new Block(randX * 100, randY * 100, 2, 0, 0, 0);
			added = true;
		}

	}
	if (added == true)
		std::cout << "Randomize worked" << std::endl;
	else
		std::cout << "Randomize failed" << std::endl;


	//Om randomiseringen inte funkde

	for (int i = 0; i < sideSize && added == false; i++)
	{
		for (int j = 0; j < sideSize && added == false; j++)
		{
			if (gameGrid[i][j] == nullptr)
			{
				this->gameGrid[i][j] = new Block(i * j, randY * 100, 2, 0, 0, 0);
			}
		}
	}
}

void PointSlidingGame::MoveDown()
{
	//Funktionerna bör nog uppdatera x/y-medelsmvariabel också.



	int sideSize = this->GetPuzzleSize();
	bool moved = false;
	bool added = false;
	int randY, randX, newVal = 0;
	int maxVal = sideSize - 1;
	//move

	for (int i = 0; i < sideSize; i++)
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = 0; j < sideSize-1; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j + 1] == nullptr)
				{
					gameGrid[i][j + 1] = new Block(i * 100, (j + 1) * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	//add
	for (int i = 0; i < sideSize; i++)
	{
		for (int j = 0; j < sideSize-1; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j + 1] != nullptr)
				{
					if (gameGrid[i][j]->GetValue() == gameGrid[i][j + 1]->GetValue())
					{
						newVal = gameGrid[i][j]->GetValue();
						newVal = newVal + newVal;
						gameGrid[i][j]->SetValue(newVal);
						delete this->gameGrid[i][j+1];
						gameGrid[i][j + 1] = nullptr;
					}
				}
			}
		}
	}
	//move
	for (int i = 0; i < sideSize; i++)
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = 0; j < sideSize-1; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j + 1] == nullptr)
				{
					gameGrid[i][j + 1] = new Block(i * 100, (j+1) * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	for (int i = 0; i < 20 && added == false; i++)
	{
		srand(time(NULL));
		randX = rand() % maxVal + 0;
		randY = rand() % maxVal + 0;
		std::cout << "randX: " << randX << "\nrandy: " << randY << std::endl;
		if (gameGrid[randX][randY] == nullptr)
		{
			this->gameGrid[randX][randY] = new Block(randX * 100, randY * 100, 2, 0, 0, 0);
			added = true;
		}

	}
	if (added == true)
		std::cout << "Randomize worked" << std::endl;
	else
		std::cout << "Randomize failed" << std::endl;


	//Om randomiseringen inte funkde

	for (int i = 0; i < sideSize && added == false; i++)
	{
		for (int j = 0; j < sideSize && added == false; j++)
		{
			if (gameGrid[i][j] == nullptr)
			{
				this->gameGrid[i][j] = new Block(i * j, randY * 100, 2, 0, 0, 0);
			}
		}
	}

}

void PointSlidingGame::MoveLeft()
{
	//Funktionerna bör nog uppdatera x/y-medelsmvariabel också.

	int sideSize = this->GetPuzzleSize();
	int randX, randY = 0;
	bool added = false;
	int maxVal = sideSize-1;
	int newVal = 0;
	bool moved = false;

	for (int i = sideSize -1; i >= 1; i--) // Flyttar brickor
	{
		if (moved == true)
		{
			i = sideSize-1;
			moved = false;
		}
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i - 1][j] == nullptr)
				{
					gameGrid[i - 1][j] = new Block((i-1)*100, j*100, gameGrid[i][j]->GetValue(), 0,0,0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	for (int i = sideSize -1; i >= 1; i--) //addera brickor
	{
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i - 1][j] != nullptr)
				{
					if (gameGrid[i][j]->GetValue() == gameGrid[i - 1][j]->GetValue())
					{
						newVal = gameGrid[i][j]->GetValue();
						newVal = newVal + newVal;
						gameGrid[i][j]->SetValue(newVal);
						delete this->gameGrid[i-1][j];
						gameGrid[i - 1][j] = nullptr;
					}				
				}
			}
		}
	}
	for (int i = sideSize -1; i >= 1; i--) // Flyttar brickor
	{
		if (moved == true)
		{
			i = sideSize-1;
			moved = false;
		}
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i - 1][j] == nullptr)
				{
					gameGrid[i - 1][j] = new Block((i - 1) * 100, j * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}
	//Randomisera ny ruta

	for (int i = 0; i < 20 && added == false; i++)
	{
		srand(time(NULL));
		randX = rand() % maxVal + 0;
		randY = rand() % maxVal + 0;
		std::cout << "randX: " << randX << "\nrandy: " << randY << std::endl;
		if (gameGrid[randX][randY] == nullptr)
		{
			this->gameGrid[randX][randY] = new Block(randX * 100, randY * 100, 2, 0, 0, 0);
			added = true;
		}

	}
	if (added == true)
		std::cout << "Randomize worked" << std::endl;
	else
		std::cout << "Randomize failed" << std::endl;


	//Om randomiseringen inte funkde

	for (int i = 0; i < sideSize && added == false; i++)
	{
		for (int j = 0; j < sideSize && added == false; j++)
		{
			if (gameGrid[i][j] == nullptr)
			{
				this->gameGrid[i][j] = new Block(i * j, randY * 100, 2, 0, 0, 0);
			}
		}
	}


}

void PointSlidingGame::MoveRight()
{
	//Funktionerna bör nog uppdatera x/y-medelsmvariabel också.

	int sideSize = this->GetPuzzleSize();
	int randX, randY = 0;
	bool added = false;
	int maxVal = sideSize-1;
	int newVal = 0;
	bool moved = false;
	for (int i = 0; i < sideSize-1; i++) // Flyttar brickor
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i + 1][j] == nullptr)
				{
					gameGrid[i + 1][j] = new Block((i + 1) * 100, j * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);;
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}

	for (int i = 0; i < sideSize - 1; i++) // Adderar brickor
	{
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i + 1][j] != nullptr)
				{
					if (gameGrid[i][j]->GetValue() == gameGrid[i+1][j]->GetValue())
					{
						newVal = gameGrid[i][j]->GetValue();
						newVal = newVal + newVal;
						gameGrid[i][j]->SetValue(newVal);
						delete this->gameGrid[i + 1][j];
						gameGrid[i+1][j] = nullptr;
					}
				}
			}
		}
	}

	for (int i = 0; i < sideSize - 1; i++) // Flyttar brickor
	{
		if (moved == true)
		{
			i = 0;
			moved = false;
		}
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i + 1][j] == nullptr)
				{
					gameGrid[i + 1][j] = new Block((i + 1) * 100, j * 100, gameGrid[i][j]->GetValue(), 0, 0, 0);
					delete this->gameGrid[i][j];
					gameGrid[i][j] = nullptr;
					moved = true;
				}
			}
		}
	}

	//Randomisera ny ruta

	for (int i = 0; i < 20 && added == false; i++)
	{
		srand(time(NULL));
		randX = rand() % maxVal + 0;
		randY = rand() % maxVal + 0;
		std::cout << "randX: " << randX << "\nrandy: " << randY << std::endl;
		if (gameGrid[randX][randY] == nullptr)
		{
			this->gameGrid[randX][randY] = new Block(randX * 100, randY * 100, 2, 0, 0, 0);
			added = true;
		}

	}
	if (added == true)
		std::cout << "Randomize worked" << std::endl;
	else
		std::cout << "Randomize failed" << std::endl;


	//Om randomiseringen inte funkde

	for (int i = 0; i < sideSize && added == false; i++)
	{
		for (int j = 0; j < sideSize && added == false; j++)
		{
			if (gameGrid[i][j] == nullptr)
			{
				this->gameGrid[i][j] = new Block(i * j, randY * 100, 2, 0, 0, 0);
			}
		}
	}

}

int PointSlidingGame::GameStatus() const
{
	int sideSize = this->GetPuzzleSize();
	int retVal = -1;
	bool notFinished = false;
	bool won = false;
	for (int i = 0; i < sideSize && notFinished == false; i++)
	{
		for (int j = 0; j < sideSize && notFinished == false; j++)
		{
			if (gameGrid[i][j] == nullptr)
			{
				retVal = 0;
				notFinished = true;
			}
		}
	}

	for (int i = 0; i < sideSize; i++)
	{
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (gameGrid[i][j]->GetValue() == this->goalScore)
				{
					retVal = 1;
					won = true;
				}
			}
		}
	}
	return retVal;
}

void PointSlidingGame::UpdateScore()
{
	/////Fixa
	int score = 0;
	int sideSize = this->GetPuzzleSize();
	int sizeOfList = 5;
	int tempScores[5];
	bool updated = false;
	tempScores[0] = 0;
	tempScores[1] = 0;
	tempScores[2] = 0;
	tempScores[3] = 0;
	tempScores[4] = 0;
	//Summing up total score
	for (int i = 0; i < sideSize; i++) 
	{
		for (int j = 0; j < sideSize; j++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				score = score + gameGrid[i][j]->GetValue();
			}
		}
	}
	this->topScore = score;

	for (int x = 0; x < 10; x++)
	{
		updated = false;
		if (x == 0)
			score = 64;
		else if (x == 1)
			score = 128;
		else if (x == 2)
			score = 128;
		else if (x == 3)
			score = 512;
		else if (x == 4)
			score = 16;
		else if (x == 5)
			score = 32;
		else if (x == 6)
			score = 1024;
		else if (x == 7)
			score = 1024;
		else if (x == 8)
			score = 512;
		else if (x == 9)
			score = 64;
		for (int i = 0; i < sizeOfList && updated == false; i++)
		{
			if (score >= highScores[i])
			{
				if (i == sizeOfList - 1) //För det sista itemet
				{
					highScores[i] = score;
					for (int x = 0; x < sizeOfList; x++)
					{
						tempScores[x] = highScores[x];
					}
				}
				else
				{
					tempScores[i] = score;
					for (int j = i; j < sizeOfList - 1; j++)
					{
						tempScores[j + 1] = highScores[j];
					}
					updated = true;
				}

			}
			else
			{
				tempScores[i] = highScores[i];
			}
		}

		for (int i = 0; i < sizeOfList; i++)
		{
			highScores[i] = tempScores[i];
			tempScores[i] = 0;
		}
		
	}
	
}
