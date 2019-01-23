#ifndef BlockBasedGame_h
#define BlockBasedGame_h
#include <cstdint>
#include "Block.hpp"
#include <string>
#include <vector>

class BlockBasedGame //ABSTRAKT KLASS
{
private:
	std::uint8_t puzzleSize;
	std::uint16_t gridSize;

public:
	BlockBasedGame(std::uint8_t puzzleSize, std::uint16_t gridSize);

	const Block* operator[](std::uint8_t index) const;
		//wtf?
		//"Ska returnera en pekare till det block som finns p� den angivna positionen"
		//"Om inget annat block finns skall nullptr returneras.
	Block* operator[](std::uint8_t index);
		//wtf?
		//"Ska returnera en pekare till det block som finns p� den angivna positionen"
		//"Om inget annat block finns skall nullptr returneras.

	virtual ~BlockBasedGame();
		//Dekonstruktor, virtuell f�r att den �rvs ner�t, right?

	/*____________________Funktioner___________________*/

	std::uint8_t GetPuzzleSize() const;
	std::uint16_t GetGridSize() const;
	void ReadHighscore(std::string filePath);
		//Om filen inte finnns ska listan nollst�llas, men fil inte skapas.
	void SaveHighscore(std::string filePath);
		//Ska s�kerst��lla att listan �r uppdaterad innan po�ng skrivs till fil.
		//Om filen inte existerar skall denna skapas
		//Om inte tillr�ckligt m�nga po�ng finns i filen ska 0 skrivas in p� resternade.
	std::uint16_t Highscore(std::uint8_t index);
		//Ska �terst�lla att listan �r uppdaterad innan efterfr�gad po�ng returneras.
	std::uint16_t CurrentScore();
		//Ska se till att nuvarande po�ng �r uppdaterad f�rst
	void SetBoardState(const std::vector<Block*> &state);
		//Om storleken p� den inskickade std::vector �r mindre �n storleken p� br�det ska ingen �ndring g�ras.
		//De inskickade block* f�r INTE sparas internt i BlockBasedGame

	/*____________(Rent) Virtuella Funktioner________________*/
	
	/*_____Flyttar p� en eller flera spelbrickor utefter spelbeskrivningen____*/
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;


	virtual int GameStatus() const = 0;
		// -1 f�r att indikera f�rlust
		// 0 f�r att indikera p�g�ende
		// 1 f�r att indikera vinst

	virtual void UpdateScore() = 0;
		//Ska uppdatera nuvarande po�ng
		//Ska se till s� att listan med HighScore �r sorterad








};

#endif
