#ifndef Block_h
#define Block_h
#include <cstdint>

class Block
{
private:
	std::uint16_t xPos, yPos, startValue;
	std::uint8_t colourR, colourG, colourB;

public:
	Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint8_t colourR, std::uint8_t colourG, std::uint8_t colourB);
		//Denna konstruktor skall fungera som en default-konstruktor med rimliga startvärden.
	Block(const Block&);
		//copy konstruktor
	Block &operator=(const Block&);
		//Tilldelnings konstruktor/operator
	bool operator==(const Block&) const;
		//Jämförelse operator
	bool operator!=(const Block&) const; 
		//Jämförelse operator
		//Ska endast kolla om blocken har samma värde

	/*_______________Funktioner_____________*/


	std::uint16_t getXPosition() const;
	std::uint16_t getYPosition() const;
	std::uint16_t getValue() const;
	std::uint16_t getColourR() const;
	std::uint16_t getColourG() const;
	std::uint16_t getColourB() const;
	void ColourasArray(std::uint8_t *colour) const;
		//Antag att denna pekare är till en array med 3 platser (RGB).
	void SetXPosition(std::uint16_t);
	void SetYPosition(std::uint16_t);
	void SetValue(std::uint16_t);
	void SetColourR(std::uint16_t);
	void SetColourG(std::uint16_t);
	void SetColourB(std::uint16_t);
	void SetColour(std::uint16_t *colour);










};


#endif 