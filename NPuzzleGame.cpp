#include "NPuzzleGame.hpp"

NPuzzleGame::NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
	:BlockBasedGame(puzzleSize, gridSize)
{
	int startVal = 1;
	int counter = 0;
	for (int y = 0; y < puzzleSize; y++)
	{ 
		for (int x = 0; x < puzzleSize; x++)
		{
			if (counter == puzzleSize * puzzleSize - 1)
			{
				this->gameGrid[x][y] = nullptr;
			}
			else
				this->gameGrid[x][y] = new Block(x*100, y*100, startVal++, 0, 0, 0);
			counter++;
		}
	}
}

NPuzzleGame::~NPuzzleGame()
{
	//another
}

void NPuzzleGame::MoveUp()
{
	int size = GetPuzzleSize();
	Block* tempPointer;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				tempPointer = gameGrid[i][j + 1];
				this->gameGrid[i][j] = tempPointer;
				gameGrid[i][j + 1]->SetValue(NULL);
			}
		}
	}
}

void NPuzzleGame::MoveDown()
{
//	Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i][j] = gameGrid[i][j - 1];
				gameGrid[i][j - 1] = NULL;
			}
		}
	}
}

void NPuzzleGame::MoveLeft()
{
//	Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i-1][j] = gameGrid[i][j];
				gameGrid[i][j] = NULL;
			}
		}
	}
}

void NPuzzleGame::MoveRight()
{
	//Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i+1][j] = gameGrid[i][j];
				gameGrid[i][j] = NULL;
			}
		}
	}
}

int NPuzzleGame::GameStatus() const
{
	std::vector<Block*> tempGrid2;
	int retVal = 0;
	int trueGrid = 0;
	int counter3 = 0;
	int totalSize = gameGrid.size();
	totalSize = totalSize * totalSize;
	tempGrid2.resize(totalSize);
	int lastPiece = totalSize - 1;

	//Fixar 1d loop tillfälligt
	for (size_t j = 0; j < gameGrid.size(); j++)
	{
		for (size_t i = 0; i < gameGrid.size(); i++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				tempGrid2[counter3] = gameGrid[i][j];
			}
			else
				tempGrid2[counter3] == nullptr;
			counter3++;
		}
	}

	for (int x = 0; x < tempGrid2.size(); x++)
	{
		if (tempGrid2[x] != nullptr)
		{
			if (tempGrid2[x]->GetValue() == x + 1)
			{
				trueGrid++;
			}
		}
		else if (tempGrid2[lastPiece] == nullptr)
		{
			trueGrid++;
		}
		else
		{
			std::cout << "Rutor på fel plats" << std::endl;
		}
			

			
	}

	if (trueGrid == tempGrid2.size())
	{
		retVal = 1;
	}

	
	return retVal;
}

void NPuzzleGame::UpdateScore()
{
}


