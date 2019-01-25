#include "PointSlidingGame.hpp"

PointSlidingGame::PointSlidingGame(std::uint8_t puzzleSize, std::uint16_t gridSize, std::uint16_t goalScore)
	:BlockBasedGame(puzzleSize, gridSize)
{
	this->goalScore = goalScore;
}

PointSlidingGame::~PointSlidingGame()
{
	// statisk
}

void PointSlidingGame::MoveUp()
{
}

void PointSlidingGame::MoveDown()
{
}

void PointSlidingGame::MoveLeft()
{
}

void PointSlidingGame::MoveRight()
{
}

int PointSlidingGame::GameStatus() const
{
	return 0;
}

void PointSlidingGame::UpdateScore()
{
}
