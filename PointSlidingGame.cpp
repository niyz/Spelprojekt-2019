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
	size_t sideSize = this->GetPuzzleSize();
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
					gameGrid[i][j - 1] = gameGrid[i][j];
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
					gameGrid[i][j - 1] = gameGrid[i][j];
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



	size_t sideSize = this->GetPuzzleSize();
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
					gameGrid[i][j + 1] = gameGrid[i][j];
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
					gameGrid[i][j + 1] = gameGrid[i][j];
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

	size_t sideSize = this->GetPuzzleSize();
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
					gameGrid[i - 1][j] = gameGrid[i][j];
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
					gameGrid[i - 1][j] = gameGrid[i][j];
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

	size_t sideSize = this->GetPuzzleSize();
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
					gameGrid[i + 1][j] = gameGrid[i][j];
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
					gameGrid[i + 1][j] = gameGrid[i][j];
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
	int score = 0;
	int sideSize = this->GetPuzzleSize();

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
}
