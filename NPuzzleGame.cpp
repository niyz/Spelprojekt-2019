#include "NPuzzleGame.hpp"

NPuzzleGame::NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
	:BlockBasedGame(puzzleSize, gridSize)
{
	int index = 0;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize - 1; j++)
		{
			if (i == puzzleSize && j == puzzleSize)
			{
				this->gameGrid[i][j]->SetXPosition(i);
				this->gameGrid[i][j]->SetYPosition(j);
				this->gameGrid[i][j]->SetValue(NULL);
			}
			else
			{
				this->gameGrid[i][j]->SetXPosition(i);
				this->gameGrid[i][j]->SetYPosition(j);
				this->gameGrid[i][j]->SetValue(index++);
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

	Block* tempPointer;
	for (int i = 0; i < GetPuzzleSize(); i++)
	{
		for (int j = 0; j < GetPuzzleSize(); j++)
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
}

void NPuzzleGame::MoveLeft()
{
}

void NPuzzleGame::MoveRight()
{
}

int NPuzzleGame::GameStatus() const
{
	return 0;
}

void NPuzzleGame::UpdateScore()
{
}
