#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	this->puzzleSize = puzzleSize;
	this->gridSize = gridSize;

	for (int i = 0; i < puzzleSize; i++) //Tillfällig 2 så vi får en 2x2 vector
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			gameGrid[i][j] = new Block(i, j, 0, 0, 0, 0);
			//xPos, yPos, startValue, r,g,b
		}
	}
}


const Block * BlockBasedGame::operator[](std::uint8_t index) const
{
	//No idea

	for (int i = 0; i < this->puzzleSize; i++)
	{
		for (int j = 0; j < this->puzzleSize; j++)
		{
			//gameGrid[i][j].get mailat ajx om denna.
		}
	}
	return nullptr;
}

Block * BlockBasedGame::operator[](std::uint8_t index)
{
	Block* indexPtr = nullptr;

	return nullptr;
}

BlockBasedGame::~BlockBasedGame()
{
	//Commenting for the sake of push
	for (int i = 0; i < puzzleSize; i++)
	{
		for (int j = 0; j < puzzleSize; j++)
		{
			delete gameGrid[i][j];
		}
	}
	// delete [] gameGrid;
}

std::uint8_t BlockBasedGame::GetPuzzleSize() const
{
	return this->puzzleSize;
}

std::uint16_t BlockBasedGame::GetGridSize() const
{
	return this->gridSize;
}

void BlockBasedGame::ReadHighscore(std::string filePath)
{
	//TODO
}

void BlockBasedGame::SaveHighscore(std::string filePath)
{
	//TODO
}

std::uint16_t BlockBasedGame::Highscore(std::uint8_t index)
{
	//TODO

	return std::uint16_t();
}

std::uint16_t BlockBasedGame::CurrentScore()
{
	//TODO

	return std::uint16_t();
}

void BlockBasedGame::SetBoardState(const std::vector<Block*>& state)
{
	//TODO

}

void BlockBasedGame::MoveUp()
{
	//TODO

}

void BlockBasedGame::MoveDown()
{
	//TODO

}

void BlockBasedGame::MoveLeft()
{
	//TODO

}

void BlockBasedGame::MoveRight()
{
	//TODO

}

int BlockBasedGame::GameStatus() const
{
	//TODO

	return 0;
}

void BlockBasedGame::UpdateScore()
{
	//TODO

}
