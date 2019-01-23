#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	puzzleSize = puzzleSize * puzzleSize;
	gridSize = gridSize;
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
