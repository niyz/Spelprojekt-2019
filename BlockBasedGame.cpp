#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	this->puzzleSize = puzzleSize; //pu
	this->gridSize = gridSize;
	gameGrid.resize(puzzleSize);
	Block * ptr = nullptr;
	for (int i = 0; i < puzzleSize; i++) //Tillfällig 2 så vi får en 2x2 vector
	{
		gameGrid[i].resize(puzzleSize);
		for (int j = 0; j < puzzleSize; j++)
		{
			gameGrid[i][j] = nullptr;
			/*if (i == puzzleSize - 1 && j == puzzleSize - 1)
				gameGrid[i][j] = ptr;
			else
				gameGrid[i][j] = new Block(i, j, 1, 0, 0, 0);*/
		}
	}
}


const Block * BlockBasedGame::operator[](std::uint8_t index) const
{
	//No idea
	Block* indexValuePtr = nullptr;;
	for (int i = 0; i < this->puzzleSize; i++)
	{
		for (int j = 0; j < this->puzzleSize; j++)
		{
			if (gameGrid[i][j]->GetValue() == index)
			{
				indexValuePtr = gameGrid[i][j];
			}
		}
	}
	return indexValuePtr;
}

Block * BlockBasedGame::operator[](std::uint8_t index)
{
	//index = 2
	//index är indx, inte value
	int counter = 0;
	bool found = false;
	Block* indexValuePtr = nullptr;;
	for (int j = 0; j < this->puzzleSize && found == false; j++)
	{
		for (int i = 0; i < this->puzzleSize && found == false; i++)
		{
			if (gameGrid[i][j] != nullptr)
			{
				if (counter == index && gameGrid[i][j] != nullptr)
				{
					indexValuePtr = gameGrid[i][j];
					found = true;
				}
				else
					indexValuePtr = nullptr;
			}
			else
				indexValuePtr = nullptr;
			counter++;
		}
	}

	return indexValuePtr;
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
	std::cout << "***********************SetboardState running*************" << std::endl;

	uint16_t indexX;
	uint16_t indexY;
	uint16_t xAxle;
	uint16_t yAxle;
	size_t gridSize = 0; //Håller storleken på hela brädet
	gridSize = gameGrid.size() * gameGrid.size();
	size_t sideSize = gameGrid.size(); //Håller storleken på en sida

	int totalStateSize = state.size() + 1;
	int newSideSize = sqrt(totalStateSize);
	if (state.size() >= gridSize) //Jämförelse med hela brädet då A använder sig av 1d vector
	{
		//14:26 uppdaterade så att den NYA sideSizen är från state.vectorn.
		gameGrid.resize(newSideSize); //fixa antal kolumner // 
		for (int i = 0; i < newSideSize; i++)
		{
			gameGrid[i].resize(newSideSize); //fixar antal rader
		}

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
				else
					std::cout << "Found null" << std::endl;
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
				//i ett tillfälle har state-vectorn ett BS värde på 8e platsen.. den påverkar jag väll inte ens?
				this->gameGrid[indexX][indexY] = new Block(state[i]->GetXPosition(), state[i]->GetYPosition(), state[i]->GetValue(), state[i]->GetColourR(), state[i]->GetColourG(), state[i]->GetColourB());
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//printa gamegrid efter new
		std::cout << " Printa gameGrid efter new " << std::endl;
		for (int i = 0; i < gameGrid.size(); i++)
		{
			for (int j = 0; j < gameGrid[i].size(); j++)
			{
				if (gameGrid[i][j] != nullptr)
					std::cout << "gameGrid[" << i << "][" << j << "] : " << gameGrid[i][j]->GetValue() << std::endl;
				else
					std::cout << "gameGrid[" << i << "][" << j << "] : null" << std::endl;
			}
		}
		std::cout << "GameGrid updated!!!!" << std::endl;
	}
	else
		std::cout << "Did not pass size comparison." << std::endl;
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
