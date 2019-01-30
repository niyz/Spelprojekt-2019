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
				this->gameGrid[x][y]->SetYPosition(y); //Sätter y då den betar av J kön först
				this->gameGrid[x][y]->SetXPosition(x);
				this->gameGrid[x][y]->SetValue(NULL);
			}
			else
			{
				this->gameGrid[x][y]->SetYPosition(y);//Sätter y då den betar av J kön först
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
