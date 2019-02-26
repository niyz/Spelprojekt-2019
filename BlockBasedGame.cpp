#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	this->puzzleSize = puzzleSize;
	this->gridSize = gridSize;
	gameGrid.resize(puzzleSize);
	Block * ptr = nullptr;
	for (int i = 0; i < puzzleSize; i++) //Tillfällig 2 så vi får en 2x2 vector
	{
		gameGrid[i].resize(puzzleSize);
		for (int j = 0; j < puzzleSize; j++)
		{
			if (i == puzzleSize - 1 && j == puzzleSize - 1)
				gameGrid[i][j] = ptr;
			else
				gameGrid[i][j] = new Block(i, j, 0, 0, 0, 0);
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
	
	Block* indexValuePtr = nullptr;;
	for (int i = 0; i < this->puzzleSize; i++)
	{
		for (int j = 0; j < this->puzzleSize; j++)
		{
			if (gameGrid[i][j] == nullptr || gameGrid[i][j]->GetValue() == index )
			{
				//&& gameGrid[i][j] != nullptr)
				indexValuePtr = gameGrid[i][j];
			}
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
	uint16_t xAxle;
	uint16_t yAxle;
	size_t gridSize = 0; //Håller storleken på hela brädet
	for (int i = 0; i < gameGrid.size(); i++)
	{
		gridSize += gameGrid[i].size();
	}
	size_t sideSize = gameGrid.size(); //Håller storleken på en sida
	std::cout << "Original sizes: " << std::endl << std::endl;
	std::cout << "Side size: " << sideSize << std::endl;
	std::cout << "Grid size: " << gridSize << std::endl;
	std::cout << "------------------------------------" << std::endl;

	if (state.size() >= gridSize) //Jämförelse med hela brädet då A använder sig av 1d vector
	{
		//size_t diff = state.size() - gridSize;
		//std::cout << "DIFF: " << diff << std::endl;
		gameGrid.resize(sideSize); //fixa antal kolumner
		for (int i = 0; i < sideSize; i++)
		{
			gameGrid[i].resize(sideSize); //fixar antal rader
		}
		std::cout << "Updated sizes: " << std::endl << std::endl;
		std::cout << "Side size (x-axle): " << gameGrid.size() << std::endl;
		std::cout << "Vector 1 size(y-axle): " << gameGrid[0].size() << std::endl;
		std::cout << "Vector 2 size(y-axle): " << gameGrid[1].size() << std::endl;
		std::cout << "Vector 3 size(y-axle): " << gameGrid[2].size() << std::endl;
		std::cout << "------------------------------------" << gridSize << std::endl;

		for (int i = 0; i < state.size() -1; i++)
		{
			std::cout << i << " : " << state[i]->GetXPosition() << ", " << state[i]->GetYPosition() << std::endl;
		}
		for (int i = 0; i < gridSize; i++)
		{
			//Holding the coordinates
			if (state[i] != nullptr)
			{
				xAxle = state[i]->GetXPosition();
				yAxle = state[i]->GetYPosition();

				//Fixing some wierd issues where coordinates in the form of 0,100
				if (yAxle != 0)
					yAxle = yAxle / 100;
				if (xAxle != 0)
					xAxle = xAxle / 100;

				std::cout << "xAxle: " << xAxle << std::endl;
				std::cout << "yAxle: " << yAxle << std::endl;
			}
			

			if (state[i] != nullptr)
			{
				this->gameGrid[xAxle][yAxle]->SetValue(state[i]->GetValue());
				this->gameGrid[xAxle][yAxle]->SetXPosition(state[i]->GetXPosition());
				this->gameGrid[xAxle][yAxle]->SetYPosition(state[i]->GetYPosition());
				this->gameGrid[xAxle][yAxle]->SetColourR(state[i]->GetColourR());
				this->gameGrid[xAxle][yAxle]->SetColourG(state[i]->GetColourG());
				this->gameGrid[xAxle][yAxle]->SetColourB(state[i]->GetColourB());
			}
			else //TODO: HITTA DEN SISTA KORDINATEN
			{
				this->gameGrid[xAxle][yAxle] = nullptr;
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
