#include "NPuzzleGame.hpp"

NPuzzleGame::NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
	:BlockBasedGame(puzzleSize, gridSize)
{
	int index = 0;
	for (int x = 0; x < puzzleSize; x++)
	{ 
		for (int y = 0; y < puzzleSize; y++)
		{
			if (x == puzzleSize -1 && y == puzzleSize - 1)
			{
				this->gameGrid[x][y]->SetYPosition(y); //Sätter y då den betar av y kön först
				this->gameGrid[x][y]->SetXPosition(x);
				this->gameGrid[x][y]->SetValue(NULL);
			}
			else
			{
				this->gameGrid[x][y]->SetYPosition(y);//Sätter y då den betar av y kön först
				this->gameGrid[x][y]->SetXPosition(x);
				this->gameGrid[x][y]->SetValue(index++);
			}
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
			if (this->gameGrid[i][j]->GetValue() == NULL)
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
	Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j]->GetValue() == NULL)
			{
				gameGrid[i][j] = gameGrid[i][j - 1];
				gameGrid[i][j - 1] = NULL;
			}
		}
	}
}

void NPuzzleGame::MoveLeft()
{
	Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j]->GetValue() == NULL)
			{
				gameGrid[i-1][j] = gameGrid[i][j];
				gameGrid[i][j] = NULL;
			}
		}
	}
}

void NPuzzleGame::MoveRight()
{
	Block* tempPointer;
	int size = GetPuzzleSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (this->gameGrid[i][j]->GetValue() == NULL)
			{
				gameGrid[i+1][j] = gameGrid[i][j];
				gameGrid[i][j] = NULL;
			}
		}
	}
}

int NPuzzleGame::GameStatus() const
{
	std::vector<int> trueGrid;
	int aValue = 0, sideSize = GetPuzzleSize();
	int gridSize = sideSize * sideSize;
	trueGrid.resize(gridSize);
	int walkChecker = 0;
	int winOrLose = 0;
	for (int i = 0; i < sideSize; i++)
	{
		for (int j = 0; j < sideSize; j++)
		{
			aValue = gameGrid[j][i]->GetValue();
			trueGrid.push_back(aValue);
		}
	}

	//Comparison loop
	//Om walkChecker har samma värde som gridSize har man vunnit
	for (int x = 0; x < gridSize; x++)
	{
		std::cout << trueGrid[x];
		if (trueGrid[x] == x)
		{
			walkChecker++;
		}
	}
	//Hur skiljer jag på om spelet är pågående eller om man har förlorat?
	if (walkChecker == gridSize)
	{
		winOrLose = 1;
	}
	else
	{	
		winOrLose = 0;
	}

	return winOrLose;
}

void NPuzzleGame::UpdateScore()
{
}
