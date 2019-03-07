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
	//Block* tempPointer;
	bool stepped = false;
	int size = GetPuzzleSize();
	for (int i = 0; i < size && stepped == false; i++)
	{
		for (int j = 0; j < size && stepped == false; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i][j] = gameGrid[i][j + 1];
				this->gameGrid[i][j+1] = nullptr;
				this->nrOfMoves++;
				stepped = true;
			}
		}
	}
}

void NPuzzleGame::MoveDown()
{
//	Block* tempPointer;
	bool stepped = false;
	int size = GetPuzzleSize();
	for (int i = 0; i < size && stepped == false; i++)
	{
		for (int j = 0; j < size && stepped == false; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i][j] = gameGrid[i][j - 1];
				gameGrid[i][j - 1] = NULL;
				this->nrOfMoves++;
				stepped = true;
			}
		}
	}
}

void NPuzzleGame::MoveLeft()
{
	//Block* tempPointer;
	bool stepped = false;
	int size = GetPuzzleSize();
	for (int i = 0; i < size && stepped == false; i++)
	{
		for (int j = 0; j < size&& stepped == false; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i][j] = gameGrid[i+1][j];
				gameGrid[i+1][j] = NULL;
				this->nrOfMoves++;
				stepped = true;
			}
		}
	}
}

void NPuzzleGame::MoveRight()
{
	//Block* tempPointer;
	bool stepped = false;
	int size = GetPuzzleSize();
	for (int i = 0; i < size && stepped == false; i++)
	{
		for (int j = 0; j < size&& stepped == false; j++)
		{
			if (this->gameGrid[i][j] == nullptr)
			{
				gameGrid[i][j] = gameGrid[i - 1][j];
				gameGrid[i - 1][j] = NULL;
				this->nrOfMoves++;
				stepped = true;
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
	int totalSize = int(gameGrid.size());
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
				tempGrid2[counter3] = nullptr;
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
		
	}

	if (trueGrid == tempGrid2.size())
	{
		retVal = 1;
	}	
	return retVal;
}

void NPuzzleGame::UpdateScore()
{
	int status = this->GameStatus();
	if (status == 1)
	{
		bool updated = false;
		int currentResult = this->CurrentScore();
		int sizeOfList = 5;
		int tempScores[5];
		tempScores[0] = 0;
		tempScores[1] = 0;
		tempScores[2] = 0;
		tempScores[3] = 0;
		tempScores[4] = 0;

		for (int i = 0; i < sizeOfList && updated == false; i++)
		{
			if (currentResult <= highScores[i])
			{
				tempScores[i] = currentResult;
				for (int j = i; j < sizeOfList - 1; j++) //minus 1 för att inte steppa utanför
				{
					tempScores[j + 1] = highScores[j];
				}
				updated = true;
			}
			else if (currentResult > highScores[i] && highScores[i] != 0)
			{
				tempScores[i] = highScores[i];
			}
			else if (highScores[i] == 0)
			{
				tempScores[i] = currentResult;
				updated = true;
			}
		}

		//kopierar tillbaka listan
		for (int i = 0; i < sizeOfList; i++)
		{
			highScores[i] = tempScores[i];
		}

	}

}
		

	
	
		
		



