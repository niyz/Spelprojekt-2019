#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	//this->puzzleSize = puzzleSize; //pu
	this->puzzleSize = puzzleSize;
	this->gridSize = gridSize;
	gameGrid.resize(puzzleSize);
	for (int i = 0; i < puzzleSize; i++) //Tillfällig 2 så vi får en 2x2 vector
	{
		gameGrid[i].resize(puzzleSize);
		for (int j = 0; j < puzzleSize; j++)
		{
			gameGrid[i][j] = nullptr;
		}
	}

}


const Block * BlockBasedGame::operator[](std::uint8_t index) const
{

	//Gör tillfälligt om till 1d för detta går fan inte
	//std::cout << "--------Print from operator[]----------" << std::endl;
	size_t sizeOfSide = this->gameGrid.size();
	std::vector<Block*> tempGrid;
	tempGrid.resize(sizeOfSide * sizeOfSide);
	int counter2 = 0;
	for (size_t j = 0; j < gameGrid.size(); j++)
	{
		for (size_t i = 0; i < gameGrid.size(); i++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				tempGrid[counter2] = gameGrid[i][j];
			}
			counter2++;
		}
	}

	Block* valuePtr = nullptr;
	if (tempGrid[index] != nullptr)
	{
		valuePtr = tempGrid[index];
	}
	return valuePtr;


}

Block * BlockBasedGame::operator[](std::uint8_t index)
{

	//Gör tillfälligt om till 1d för detta går fan inte
	//std::cout << "--------Print from operator[]----------" << std::endl;
	size_t sizeOfSide = this->gameGrid.size();
	std::vector<Block*> tempGrid;
	tempGrid.resize(sizeOfSide * sizeOfSide);
	int counter2 = 0;
	for (size_t j = 0; j < gameGrid.size(); j++)
	{
		for (size_t i = 0; i < gameGrid.size(); i++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				tempGrid[counter2] = gameGrid[i][j];
			}
			counter2++;
		}
	}

	Block* valuePtr = nullptr;
	if (tempGrid[index] != nullptr)
	{
		valuePtr = tempGrid[index];
	}
	return valuePtr;


}

BlockBasedGame::~BlockBasedGame()
{
	for (int i = 0; i < this->GetPuzzleSize(); i++)
	{
		for (int j = 0; j < this->GetPuzzleSize(); j++)
		{
			delete this->gameGrid[i][j];
		}
	}
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
	//int boardSize = gameGrid.size() * gameGrid.size();
	int totalPuzzleSize = this->puzzleSize*puzzleSize;

	//Det stora problemet just nu är  Error: SetBoardState changed when called with vector smaller than expected.
	if (state.size() >= totalPuzzleSize) //Jämförelse med hela brädet då A använder sig av 1d vector
	{
		std::cout << "***********************SetboardState running*************" << std::endl;

		uint16_t indexX;
		uint16_t indexY;
		uint16_t xAxle;
		uint16_t yAxle;
		size_t gridSize = 0; //Håller storleken på hela brädet
		size_t sideSize = gameGrid.size(); //Håller storleken på en sida




		//Delete current grid
		for (int i = 0; i < gameGrid.size(); i++)
		{
			for (int j = 0; j < gameGrid[i].size(); j++)
			{
				if (gameGrid[i][j] != nullptr)
				{
					delete gameGrid[i][j];
					gameGrid[i][j] = nullptr;
				}
			}
		}

		//Update gameGrid
		for (int i = 0; i < state.size(); i++)
		{
			if (state[i] != nullptr)
			{
				indexX = state[i]->GetXPosition();
				indexY = state[i]->GetYPosition();
				xAxle = indexX;
				yAxle = indexY;
				//Fixing some wierd issues where coordinates in the form of 0,100
				if (indexY != 0)
					indexY = indexY / 100;
				if (indexX != 0)
					indexX = indexX / 100;
				this->gameGrid[indexX][indexY] = new Block(state[i]->GetXPosition(), state[i]->GetYPosition(), state[i]->GetValue(), state[i]->GetColourR(), state[i]->GetColourG(), state[i]->GetColourB());
			}
		}
	}
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
