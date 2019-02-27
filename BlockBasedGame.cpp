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
				gameGrid[i][j] = new Block(i, j, 1, 0, 0, 0);
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
	std::cout << "***********************SetboardState running*************" << std::endl;
	std::cout << "State Size:" << state.size() << std::endl;

	uint16_t indexX;
	uint16_t indexY;
	uint16_t xAxle;
	uint16_t yAxle;
	size_t gridSize = 0; //Håller storleken på hela brädet
	gridSize = gameGrid.size() * gameGrid.size();
	size_t sideSize = gameGrid.size(); //Håller storleken på en sida

	if (state.size() >= gridSize) //Jämförelse med hela brädet då A använder sig av 1d vector
	{

		gameGrid.resize(sideSize); //fixa antal kolumner
		for (int i = 0; i < sideSize; i++)
		{
			gameGrid[i].resize(sideSize); //fixar antal rader
		}
		//Printa gameGrid innan delete
		std::cout << " Printa gameGrid innan delete " << std::endl;
		for (int i = 0; i < gameGrid.size(); i++)
		{
			for (int j = 0; j < gameGrid[i].size(); j++)
			{
				if (gameGrid[i][j] != nullptr)
					std::cout << "gameGrid[" << i << "][" << j <<"] : " << gameGrid[i][j]->GetValue() << std::endl;
				else
					std::cout << "gameGrid[" << i << "][" << j << "] : null" << std::endl;
			}
		}
		//lets delete
		for (int i = 0; i < gameGrid.size(); i++)
		{
			for (int j = 0; j < gameGrid[i].size(); j++)
			{
				if (gameGrid[i][j] != nullptr)
				{
					delete gameGrid[i][j];
					gameGrid[i][j]->SetValue(1);
				}
				else
					std::cout << "Found null" << std::endl;
			}
		}
	/*	std::cout << "gameGrid size after delete" << gameGrid.size() << std::endl;
		std::cout << "gameGrid 0 size after delete: " << gameGrid[0].size() << std::endl;
		std::cout << "gameGrid 1 size after delete: " << gameGrid[0].size() << std::endl;
		std::cout << "gameGrid 2 size after delete: " << gameGrid[0].size() << std::endl;*/


		//printa gamegrid efter delete
		std::cout << " Printa gameGrid efter delete " << std::endl;
	//m	std::cout << gameGrid[0][0] << std::endl;
	/*	for (int i = 0; i < gameGrid.size(); i++)
		{
			for (int j = 0; j < gameGrid[i].size(); j++)
			{
				if (gameGrid[i][j] != nullptr)
					std::cout << "gameGrid[" << i << "][" << j << "] : " << gameGrid[i][j]->GetValue() << std::endl;
				else
					std::cout << "gameGrid[" << i << "][" << j << "] : null" << std::endl;
			}
		}*/

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Holding the coordinates
		for (int i = 0; i < state.size(); i++)
		{
			//Holding the coordinates
			if (state[i] != nullptr)
			{
				indexX = state[i]->GetXPosition();
				indexY = state[i]->GetYPosition();

				//Fixing some wierd issues where coordinates in the form of 0,100
				if (indexY != 0)
					indexY = indexY / 100;
				if (indexX != 0)
					indexX = indexX / 100;

				this->gameGrid[indexX][indexY] = new Block(state[i]->GetXPosition(), state[i]->GetYPosition(), state[i]->GetValue(), state[i]->GetColourR(), state[i]->GetColourG(), state[i]->GetColourB());
			}
			else //TODO: HITTA DEN SISTA KORDINATEN
			{
				this->gameGrid[indexX + 1][indexY] = nullptr;
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

																							//std::cout << "Updated sizes: " << std::endl << std::endl;
																							//std::cout << "Side size (x-axle): " << gameGrid.size() << std::endl;
																							//std::cout << "Vector 1 size(y-axle): " << gameGrid[0].size() << std::endl;
																							//std::cout << "Vector 2 size(y-axle): " << gameGrid[1].size() << std::endl;
																							//std::cout << "Vector 3 size(y-axle): " << gameGrid[2].size() << std::endl;
																							//std::cout << "------------------------------------" << std::endl;
	//	for (int i = 0; i < gameGrid.size(); i++)
	//		std::cout << "gameGrid after update:" << gameGrid[i].size() << std::endl;
	//	std::cout << std::endl << std::endl << std::endl << std::endl;
	//	std::cout << "Printing coordinates:" << std::endl;

	//	for (int i = 0; i < state.size(); i++)
	//	{
	//		if (state[i] == nullptr)
	//		{
	//			std::cout << "state[x][y] has no coordinates"  << std::endl;
	//		}
	//		else
	//		{
	//			//std::cout << i << " : " << state[i]->GetXPosition() << ", " << state[i]->GetYPosition() << std::endl;
	//			std::cout << "state[" << state[i]->GetXPosition() << "][" << state[i]->GetYPosition()  << "]"<< std::endl;

	//		}
	//	}
	//	for (int i = 0; i < state.size(); i++)
	//	{
	//		//Holding the coordinates
	//		if (state[i] != nullptr)
	//		{
	//			xAxle = state[i]->GetXPosition();
	//			yAxle = state[i]->GetYPosition();

	//			//Fixing some wierd issues where coordinates in the form of 0,100
	//			if (yAxle != 0)
	//				yAxle = yAxle / 100;
	//			if (xAxle != 0)
	//				xAxle = xAxle / 100;

	//			/*std::cout << "xAxle: " << xAxle << std::endl;
	//			std::cout << "yAxle: " << yAxle << std::endl;
	//			std::cout << "--------------" << std::endl << std::endl << std::endl;*/

	//			this->gameGrid[xAxle][yAxle]->SetValue(state[i]->GetValue());
	//			this->gameGrid[xAxle][yAxle]->SetXPosition(xAxle);
	//			this->gameGrid[xAxle][yAxle]->SetYPosition(yAxle);
	//			this->gameGrid[xAxle][yAxle]->SetColourR(state[i]->GetColourR());
	//			this->gameGrid[xAxle][yAxle]->SetColourG(state[i]->GetColourG());
	//			this->gameGrid[xAxle][yAxle]->SetColourB(state[i]->GetColourB());



	//		}
	//		else //TODO: HITTA DEN SISTA KORDINATEN
	//		{
	///*			xAxle = state[i]->GetXPosition();
	//			yAxle = state[i]->GetYPosition();*/
	//			//Fixing some wierd issues where coordinates in the form of 0,100
	///*			if (yAxle != 0)
	//				yAxle = yAxle / 100;
	//			if (xAxle != 0)
	//				xAxle = xAxle / 100;*/
	//			this->gameGrid[xAxle +1][yAxle] = nullptr;
	//		}
	//	}
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
