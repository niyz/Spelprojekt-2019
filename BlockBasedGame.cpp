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
		}
	}
}


const Block * BlockBasedGame::operator[](std::uint8_t index) const
{
	//No idea
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
}

void BlockBasedGame::SaveHighscore(std::string filePath)
{
}

std::uint16_t BlockBasedGame::Highscore(std::uint8_t index)
{
	return std::uint16_t();
}

std::uint16_t BlockBasedGame::CurrentScore()
{
	return std::uint16_t();
}

void BlockBasedGame::SetBoardState(const std::vector<Block*>& state)
{
}

void BlockBasedGame::MoveUp()
{
}

void BlockBasedGame::MoveDown()
{
}

void BlockBasedGame::MoveLeft()
{
}

void BlockBasedGame::MoveRight()
{
}

int BlockBasedGame::GameStatus() const
{
	return 0;
}

void BlockBasedGame::UpdateScore()
{
}
