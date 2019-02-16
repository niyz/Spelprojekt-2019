#include "BlockBasedGame.hpp"

BlockBasedGame::BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize)
{
	//Initiera medlemsvariabler med de argument som skickas med konstruktorn.
	this->puzzleSize = puzzleSize;
	this->gridSize = gridSize;
	gameGrid.resize(puzzleSize);
	for (int i = 0; i < puzzleSize; i++) //Tillf�llig 2 s� vi f�r en 2x2 vector
	{
		gameGrid[i].resize(puzzleSize);
		for (int j = 0; j < puzzleSize; j++)
		{

			gameGrid[i][j] = new Block(i, j, 0, 0, 0, 0);
			//xPos, yPos, startValue, r,g,b
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
			if (gameGrid[i][j]->GetValue() == index)
			{
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

	size_t gridSize = 0; //H�ller storleken p� hela br�det
	for (int i = 0; i < gameGrid.size(); i++)
	{
		gridSize += gameGrid[i].size();
	}
	size_t sideSize = gameGrid.size(); //H�ller storleken p� en sida
	if (state.size() >= gridSize) //J�mf�relse med hela br�det d� A anv�nder sig av 1d vector
	{
		//size_t diff = state.size() - gridSize;
		//std::cout << "DIFF: " << diff << std::endl;
		gameGrid.resize(sideSize); //fixa antal kolumner
		for (int i = 0; i < sideSize; i++)
		{
			gameGrid[i].resize(sideSize); //fixar antal rader
		}
		for (int i = 0; i < sideSize; i++)
		{
			for (int j = 0; j < sideSize; j++)
			{
				this->gameGrid[i][j]->SetValue(state[i]->GetValue()); //Uppdaterar v�rdet p� griddet, antar att alla platser ska uppdateras gentemot det inskickade br�det.
			}
		}
		
	}



	//if (state.size() >= this->gameGrid.size())
	//{
	//	//orig = 3*3 = 9
	//	//ny = 16 (4*4)
	//	// nya tiles 7
	//	std::cout << ("stir it up");
	//	//H�mta storleken p� den nya gridden
	//	int stateSize = state.size();

	//	//statesize = 16
	//	//16 / 3 = 5
	//		//percolumnin = 5;
	//	int perColumnInt = this->GetPuzzleSize() / stateSize;

	//	//l�ser 2 nya kolumner med hittils 3 i varje = 6
	//	// 9-6 = 3
	//	this->gameGrid.resize(perColumnInt);

	//	for (int i = 0; i < this->gameGrid.size(); i++)
	//	{
	//		gameGrid[i].resize(perColumnInt);
	//	}
	//	for (int i = 0; i < state.size(); i++)
	//	{
	//		
	//	}
	//}
	//else
	//{
	//	std::cout << ("A wadodem a wadodemdemdem");
	//}
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
