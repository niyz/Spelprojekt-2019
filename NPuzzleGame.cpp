#include "NPuzzleGame.hpp"

NPuzzleGame::NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
	:BlockBasedGame(puzzleSize, gridSize)
{
	int index = 0;
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			if (i == puzzleSize && j == puzzleSize - 1)
				this->gameGrid[i][j]->SetValue(NULL);
			else
				this->gameGrid[i][j]->SetValue(index++);
			
		}
	}
}

NPuzzleGame::~NPuzzleGame()
{
	//another
}

void NPuzzleGame::MoveUp()
{
	//
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
