#ifndef PointSlidingGame_h
#define PointSlidingGame_h
#include "BlockBasedGame.hpp"

class PointSlidingGame : public BlockBasedGame //Child class
{
private:
	int goalScore; //Lär hålla det 
	//De andra medlemsvariablerna denna använder är de som återfinns i parentklassen.

public:
	PointSlidingGame(std::uint8_t puzzleSize, std::uint16_t gridSize,  std::uint16_t goalScore);
	//Ska skapa brädet med två stycken brickor med värdet 2 utplacerade
	//goalScore är en tvåpotens
	~PointSlidingGame();

	PointSlidingGame(const PointSlidingGame&) = delete;
	PointSlidingGame& operator=(const PointSlidingGame&) = delete;

	/*_______Funktioner______*/
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	//Vid Lyckad förflyttning ska en ny bricka med värdet två slumpas in på tom plats. Tips: Dela upp förflyttningen i två steg. En del som lägger samman brickorna som ska kombineras och en del som utför själva förflyttningen.

	int GameStatus() const;
	//-1 om det inte finns några möjliga drag
	//0 om det finns möjliga drag och ingen bricka har samma värde som goalScore
	// 1 om det finns en bricka som har samma värde som goalScore
	void UpdateScore();
		//För PointSlidingGame ska poängen vara den totala summan på fältet och sorteras i fallande ordning.

};


#endif

