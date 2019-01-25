#ifndef BLOCK_H
#define BLOCK_H
#include <cstdint>

class Block
{	
	private:
		std::uint16_t xPos; //uint16_t = Width of exactly 16, wtf?
		std::uint16_t yPos;
		std::uint16_t startValue;
		std::uint8_t colourR, colourG, colourB; //uint8_t = Width of exactly 8, wtf?
	public:
		Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint8_t colourR, std::uint8_t colourG, std::uint8_t colourB);
			//Skall fungera som default konstruktor med rimliga startvärden.
		Block(const Block&rhs);
			//Copy-konstruktor, borde inte behövas skapas då vi inte har pekare..
		Block &operator=(const Block&rhs);
			//Tilldelningsoperator
		bool operator==(const Block&rhs) const;
			//Jämförelseoperator
		bool operator!=(const Block&) const;
			//Jämförelseoperator
		
		/*__________________Funktioner_______________________*/

		std::uint16_t GetXPosition() const;
		std::uint16_t GetYPosition() const;
		std::uint16_t GetValue() const;
	
		std::uint8_t GetColourR() const;
		std::uint8_t GetColourG() const;
		std::uint8_t GetColourB() const;

		void ColourAsArray(std::uint8_t *colour) const;
			//Antag att denna pekare är till en array med 3 platser (RGB).Get-funktion?

		void SetXPosition(std::uint16_t);
		void SetYPosition(std::uint16_t);
		void SetValue(std::uint16_t);

		void SetColourR(std::uint8_t);
		void SetColourG(std::uint8_t);
		void SetColourB(std::uint8_t);

		void SetColour(std::uint8_t *colour);
			//Antag att denna pekare är till en array med 3 platser (RGB)







};


#endif