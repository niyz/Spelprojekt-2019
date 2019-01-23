#ifndef NPuzzleGame_h
#define NPuzzleGame_h
#include "BlockBasedGame.hpp"


/*
Har tydligen cirka 362k olika l�sningar. 
Starta varje spelplan med ett "l�st" br�de, 
flytta sedan blocken ett oj�mnt antal g�nger
*/


class NPuzzleGame : public BlockBasedGame //Child class
{
private:
	//De enda medlemsvariablerna denna anv�nder �r de som �terfinns i parentklassen.
public:
	NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize);
	~NPuzzleGame();

	/*___________Funktioner______________*/

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	int GameStatus() const; 
		//Returnerar 1 om alla brickor �r p� korrekt plats
		//0 annars
	void UpdateScore();
};

#endif

