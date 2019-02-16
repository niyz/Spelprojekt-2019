
#include <iostream>
#include <string>
#include "Window.hpp"
#include "NPuzzleGame.hpp"
#include "PointSlidingGame.hpp"

int main(int argc, const char* argv[])
{
	Window gameWindow;
	BlockBasedGame* game = nullptr;
	std::uint8_t size = std::stoi(argv[1]);
	std::string filePath = "";
	if (argc < 2)
	{
		std::cout << "Not enough arguments." << std::endl;
		return -1;
	}
	else if (argc == 2)
	{
		std::cout << "Starting NPuzzleGame with size " << argv[1] << std::endl;
		game = new NPuzzleGame(size, 900/size);
		filePath = "NPuzzleGameScore";
	}
	else if (argc == 3)
	{
		std::cout << "Starting PointSlidingGame with size " << argv[1] << " and goal score " << argv[2] << std::endl;
		game = new PointSlidingGame(size, 900 / size, std::stoi(argv[2]));
		filePath = "PointSlidingGame";
	}
	gameWindow.BindCallableFunctionToKey(Key::KEY_UP_ARROW, std::function<void()>([&game]() -> void {
		game->MoveUp();
	}));
	gameWindow.BindCallableFunctionToKey(Key::KEY_DOWN_ARROW, std::function<void()>([&game]() -> void {
		game->MoveDown();
	}));
	gameWindow.BindCallableFunctionToKey(Key::KEY_LEFT_ARROW, std::function<void()>([&game]() -> void {
		game->MoveLeft();
	}));
	gameWindow.BindCallableFunctionToKey(Key::KEY_RIGHT_ARROW, std::function<void()>([&game]() -> void {
		game->MoveRight();
	}));
	std::uint8_t black[] = { 0, 0, 0 };
	std::uint8_t colour[3] = { 0, 0, 0 };
	game->ReadHighscore(filePath);

	while (gameWindow.IsOpen())
	{
		gameWindow.Clear();
		gameWindow.CreateGrid(static_cast<std::uint8_t>(size));
		for (std::uint8_t index = 0; index != size*size; ++index)
		{
			auto block = (*game)[index];
			if (!block)
				continue;
			block->ColourAsArray(colour);
			gameWindow.PaintBox(block->GetXPosition(),
				block->GetYPosition(),
				game->GetGridSize(),
				colour,
				block->GetValue(),
				black);
		}
		gameWindow.Display();
		auto status = game->GameStatus();
		if (status == -1)
		{
			std::cout << "Game over, you lost." << std::endl;
			std::cout << "Highscorelist:\n" <<
						"1. \t" << game->Highscore(0) <<
						"2. \t" << game->Highscore(1) <<
						"3. \t" << game->Highscore(2) <<
						"4. \t" << game->Highscore(3) <<
						"5. \t" << game->Highscore(4) << std::endl;
						

			std::cin.get();
			gameWindow.Close();
		}
		else if (status == 1)
		{
			std::cout << "Congratulations, you won!" << std::endl;
			std::cout << "Highscorelist:\n" <<
						"1. \t" << game->Highscore(0) <<
						"2. \t" << game->Highscore(1) <<
						"3. \t" << game->Highscore(2) <<
						"4. \t" << game->Highscore(3) <<
						"5. \t" << game->Highscore(4) << std::endl;
			std::cin.get();
			gameWindow.Close();
		}
	}
	game->SaveHighscore(filePath);
	delete game;
	return 0;
}