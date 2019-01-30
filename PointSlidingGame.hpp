#ifndef PointSlidingGame_h
#define PointSlidingGame_h
#include "BlockBasedGame.hpp"

class PointSlidingGame : public BlockBasedGame //Child class
{
private:
	int goalScore; //L�r h�lla det 
	//De andra medlemsvariablerna denna anv�nder �r de som �terfinns i parentklassen.

public:
	PointSlidingGame(std::uint8_t puzzleSize, std::uint16_t gridSize,  std::uint16_t goalScore);
	//Ska skapa br�det med tv� stycken brickor med v�rdet 2 utplacerade
	//goalScore �r en tv�potens
	~PointSlidingGame();

	PointSlidingGame(const PointSlidingGame&) = delete;
	PointSlidingGame& operator=(const PointSlidingGame&) = delete;

	/*_______Funktioner______*/
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	//Vid Lyckad f�rflyttning ska en ny bricka med v�rdet tv� slumpas in p� tom plats. Tips: Dela upp f�rflyttningen i tv� steg. En del som l�gger samman brickorna som ska kombineras och en del som utf�r sj�lva f�rflyttningen.

	int GameStatus() const;
	//-1 om det inte finns n�gra m�jliga drag
	//0 om det finns m�jliga drag och ingen bricka har samma v�rde som goalScore
	// 1 om det finns en bricka som har samma v�rde som goalScore
	void UpdateScore();
		//F�r PointSlidingGame ska po�ngen vara den totala summan p� f�ltet och sorteras i fallande ordning.

};


#endif

