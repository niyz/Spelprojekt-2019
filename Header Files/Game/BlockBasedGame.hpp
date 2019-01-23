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
		//"Ska returnera en pekare till det block som finns på den angivna positionen"
		//"Om inget annat block finns skall nullptr returneras.
	Block* operator[](std::uint8_t index);
		//wtf?
		//"Ska returnera en pekare till det block som finns på den angivna positionen"
		//"Om inget annat block finns skall nullptr returneras.

	virtual ~BlockBasedGame();
		//Dekonstruktor, virtuell för att den ärvs neråt, right?

	/*____________________Funktioner___________________*/

	std::uint8_t GetPuzzleSize() const;
	std::uint16_t GetGridSize() const;
	void ReadHighscore(std::string filePath);
		//Om filen inte finnns ska listan nollställas, men fil inte skapas.
	void SaveHighscore(std::string filePath);
		//Ska säkerstäölla att listan är uppdaterad innan poäng skrivs till fil.
		//Om filen inte existerar skall denna skapas
		//Om inte tillräckligt många poäng finns i filen ska 0 skrivas in på resternade.
	std::uint16_t Highscore(std::uint8_t index);
		//Ska återställa att listan är uppdaterad innan efterfrågad poäng returneras.
	std::uint16_t CurrentScore();
		//Ska se till att nuvarande poäng är uppdaterad först
	void SetBoardState(const std::vector<Block*> &state);
		//Om storleken på den inskickade std::vector är mindre än storleken på brädet ska ingen ändring göras.
		//De inskickade block* får INTE sparas internt i BlockBasedGame

	/*____________(Rent) Virtuella Funktioner________________*/
	
	/*_____Flyttar på en eller flera spelbrickor utefter spelbeskrivningen____*/
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;


	virtual int GameStatus() const = 0;
		// -1 för att indikera förlust
		// 0 för att indikera pågående
		// 1 för att indikera vinst

	virtual void UpdateScore() = 0;
		//Ska uppdatera nuvarande poäng
		//Ska se till så att listan med HighScore är sorterad








};

#endif
