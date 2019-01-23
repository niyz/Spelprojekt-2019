#include "NPuzzleGame.hpp"

NPuzzleGame::NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
	:BlockBasedGame(puzzleSize * puzzleSize, gridSize)
{
}

NPuzzleGame::~NPuzzleGame()
{
	//Kommer denna ta bort 
}

void NPuzzleGame::MoveUp()
{
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
