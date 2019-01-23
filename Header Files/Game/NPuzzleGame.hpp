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
	//De enda medlemsvariablerna denna använder är de som återfinns i parentklassen.
public:
	NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize);
	~NPuzzleGame();

	/*___________Funktioner______________*/

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	int GameStatus() const; 
		//Returnerar 1 om alla brickor är på korrekt plats
		//0 annars
	void UpdateScore();
};

#endif

