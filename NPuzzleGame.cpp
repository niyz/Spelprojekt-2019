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
	//Utkommenterat sedan ändringen av nullvärde -> nullptr

	//std::vector<int> trueGrid;
	//int aValue = 0, sideSize = GetPuzzleSize();
	//int gridSize = sideSize * sideSize;
	//trueGrid.resize(gridSize);
	//int walkChecker = 0;
	//int winOrLose = 0;
	//for (int i = 0; i < sideSize; i++)
	//{
	//	for (int j = 0; j < sideSize; j++)
	//	{
	//		aValue = gameGrid[j][i]->GetValue();
	//		trueGrid.push_back(aValue);
	//	}
	//}

	////Comparison loop
	////Om walkChecker har samma värde som gridSize har man vunnit
	//for (int x = 0; x < gridSize; x++)
	//{
	//	std::cout << trueGrid[x];
	//	if (trueGrid[x] == x)
	//	{
	//		walkChecker++;
	//	}
	//}
	////Hur skiljer jag på om spelet är pågående eller om man har förlorat?
	//if (walkChecker == gridSize)
	//{
	//	winOrLose = 1;
	//}
	//else
	//{	
	//	winOrLose = 0;
	//}

	//return winOrLose;
	return 0;
}

void NPuzzleGame::UpdateScore()
{
}
