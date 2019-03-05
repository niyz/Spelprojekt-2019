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
	//test var
	//testvar
	//For testing purpose
	highScores[0] = 5;
	highScores[1] = 2;
	highScores[2] = 76;
	highScores[3] = 5;
	highScores[4] = 2354;


	int temp;
	int nah = 0;
	
	std::cout << "adding scores" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << highScores[i] << std::endl;
	}
	//Sort
	std::cout << "Sorting..." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (highScores[i] < highScores[j])
			{
				temp = highScores[j];
				highScores[j] = highScores[i];
				highScores[i] = temp;
			}
		}
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	if (highScores[i] )
	//}
	std::cout << "Printing sorted arr" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << highScores[i] << std::endl;
	}


	
	//Insert
	temp = 0;
	for (int i = 0; i < 5; i++)
	{
		if (nrOfMoves < highScores[i])
		{
			std::cout << "Found: " << nrOfMoves << " lower than highscores[" << i << "]: " << highScores[i] << std::endl;
			highScores[4] = nrOfMoves;
			for (int x = 0; x < 5; x++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (highScores[x] < highScores[j])
					{
						temp = highScores[j];
						highScores[j] = highScores[x];
						highScores[x] = temp;
					}
				}
			}
			break;
		}
	}
	std::cout << "Printing sorted arr" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << highScores[i] << std::endl;
	}

	//
	//this->nrOfMoves++;
}


