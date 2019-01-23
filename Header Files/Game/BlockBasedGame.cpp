#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//hmm, beskrivningen är lite weird.
}

const Block * BlockBasedGame::operator[](std::uint8_t index) const
{
	//No idea
	return nullptr;
}

Block * BlockBasedGame::operator[](std::uint8_t index)
{
	return nullptr;
}

BlockBasedGame::~BlockBasedGame()
{
	//Commenting for the sake of push
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
