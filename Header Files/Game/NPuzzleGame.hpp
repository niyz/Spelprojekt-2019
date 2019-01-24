#ifndef NPuzzleGame_h
#define NPuzzleGame_h
#include "BlockBasedGame.hpp"


/*
Har tydligen cirka 362k olika lösningar. 
Starta varje spelplan med ett "löst" bräde, 
flytta sedan blocken ett ojämnt antal gånger
*/


class NPuzzleGame : public BlockBasedGame //Child class
{
private:
	std::vector<std::vector<Block>> gameGrid;
	//Spelbrädet återfinns i respektive subklass, övriga medlemsvariabler finns i basklassen.

public:
	NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize);
	~NPuzzleGame();

	/*___________Funktioner______________*/

	void MoveUp();
		//Förflyttar brickan nedanför den tomma platsen uppåt
	void MoveDown();
	//Förflyttar brickan ovanför den tomma platsen nedåt

	void MoveLeft();
	//Förflyttar brickan till höger om den tomma platsen till vänster

	void MoveRight();
	//Förflyttar brickan till vänster om den tomma platsen höger

	int GameStatus() const; 
		//Returnerar 1 om alla brickor är på korrekt plats
		//0 annars
	void UpdateScore();
};

#endif

