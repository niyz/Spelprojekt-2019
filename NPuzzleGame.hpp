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
	//Spelbr�det �terfinns i respektive subklass, �vriga medlemsvariabler finns i basklassen.

public:
	NPuzzleGame(std::uint8_t puzzleSize, std::uint16_t gridSize);
	~NPuzzleGame();

	NPuzzleGame(const NPuzzleGame&) = delete;
	NPuzzleGame& operator=(const NPuzzleGame&) = delete;
	/*____________________Funktioner________________________*/

	void MoveUp();
		//F�rflyttar brickan nedanf�r den tomma platsen upp�t
	void MoveDown();
	//F�rflyttar brickan ovanf�r den tomma platsen ned�t

	void MoveLeft();
	//F�rflyttar brickan till h�ger om den tomma platsen till v�nster

	void MoveRight();
	//F�rflyttar brickan till v�nster om den tomma platsen h�ger

	int GameStatus() const; 
		//Returnerar 1 om alla brickor �r p� korrekt plats
		//0 annars
	void UpdateScore();

};

#endif

