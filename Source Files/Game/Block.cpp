#include "Header Files\Game\Block.hpp"

Block::Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint8_t colourR, std::uint8_t colourG, std::uint8_t colourB)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->startValue = startValue;
	this->colourR = colourR;
	this->colourG = colourG;
	this->colourB = colourB;

}
