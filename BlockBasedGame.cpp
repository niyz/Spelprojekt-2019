#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	//this->puzzleSize = puzzleSize; //pu
	this->puzzleSize = puzzleSize;
	this->gridSize = gridSize;
	gameGrid.resize(puzzleSize);
	for (int i = 0; i < puzzleSize; i++) //Tillf�llig 2 s� vi f�r en 2x2 vector
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

	//G�r tillf�lligt om till 1d f�r detta g�r fan inte
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
	//std::cout << "-------------" << std::endl;
	//for (size_t i = 0; i < tempGrid.size(); i++)
//	{
	//	if (tempGrid[i] != nullptr)
	//	{
	//		std::cout << tempGrid[i]->GetValue() << std::endl;
	//	}
		//else
//			std::cout << "null" << std::endl;
	//}
//	std::cout << "--------Print from operator[] Finished----------" << std::endl;

	Block* valuePtr = nullptr;
	if (tempGrid[index] != nullptr)
	{
		valuePtr = tempGrid[index];
	}
	return valuePtr;


	////index = 2
	////index �r indx, inte value
	//int counter = 0;
	//bool found = false;
	//Block* indexValuePtr = nullptr;;
	//for (int j = 0; j < this->puzzleSize && found == false; j++)
	//{
	//	for (int i = 0; i < this->puzzleSize && found == false; i++)
	//	{
	//		if (gameGrid[i][j] != nullptr)
	//		{
	//			if (counter == index && gameGrid[i][j] != nullptr)
	//			{
	//				indexValuePtr = gameGrid[i][j];
	//				found = true;
	//			}
	//			else
	//				indexValuePtr = nullptr;
	//		}
	//		else
	//			indexValuePtr = nullptr;
	//		counter++;
	//	}
	//}

	//return indexValuePtr;
}

Block * BlockBasedGame::operator[](std::uint8_t index)
{

	//G�r tillf�lligt om till 1d f�r detta g�r fan inte
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
	//std::cout << "-------------" << std::endl;
	//for (size_t i = 0; i < tempGrid.size(); i++)
//	{
	//	if (tempGrid[i] != nullptr)
	//	{
	//		std::cout << tempGrid[i]->GetValue() << std::endl;
	//	}
		//else
//			std::cout << "null" << std::endl;
	//}
//	std::cout << "--------Print from operator[] Finished----------" << std::endl;

	Block* valuePtr = nullptr;
	if (tempGrid[index] != nullptr)
	{
		valuePtr = tempGrid[index];
	}
	return valuePtr;


	////index = 2
	////index �r indx, inte value
	//int counter = 0;
	//bool found = false;
	//Block* indexValuePtr = nullptr;;
	//for (int j = 0; j < this->puzzleSize && found == false; j++)
	//{
	//	for (int i = 0; i < this->puzzleSize && found == false; i++)
	//	{
	//		if (gameGrid[i][j] != nullptr)
	//		{
	//			if (counter == index && gameGrid[i][j] != nullptr)
	//			{
	//				indexValuePtr = gameGrid[i][j];
	//				found = true;
	//			}
	//			else
	//				indexValuePtr = nullptr;
	//		}
	//		else
	//			indexValuePtr = nullptr;
	//		counter++;
	//	}
	//}

	//return indexValuePtr;
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

	//Det stora problemet just nu �r  Error: SetBoardState changed when called with vector smaller than expected.
	if (state.size() >= totalPuzzleSize) //J�mf�relse med hela br�det d� A anv�nder sig av 1d vector
	{
		std::cout << "***********************SetboardState running*************" << std::endl;

		uint16_t indexX;
		uint16_t indexY;
		uint16_t xAxle;
		uint16_t yAxle;
		size_t gridSize = 0; //H�ller storleken p� hela br�det
		size_t sideSize = gameGrid.size(); //H�ller storleken p� en sida
	
	


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
				//i ett tillf�lle har state-vectorn ett BS v�rde p� 8e platsen.. den p�verkar jag v�ll inte ens?
				this->gameGrid[indexX][indexY] = new Block(state[i]->GetXPosition(), state[i]->GetYPosition(), state[i]->GetValue(), state[i]->GetColourR(), state[i]->GetColourG(), state[i]->GetColourB());
			}
		}

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
