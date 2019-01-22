#ifndef Block_h
#define Block_h
#include <cstdint>

class Block
{	
	private:
		std::uint16_t xPos;
		std::uint16_t yPos;
		std::uint16_t startValue;
		std::uint8_t colourR, colourG, colourB;
	public:
		Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint16_t colourR, std::uint16_t colourG, std::uint16_t colourB);
};


#endif