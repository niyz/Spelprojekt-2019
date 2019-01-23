#include "..\..\Header Files\Game\Block.hpp"


Block::Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint8_t colourR, std::uint8_t colourG, std::uint8_t colourB)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->startValue = startValue;
	this->colourR = colourR;
	this->colourG = colourG;
	this->colourB = colourB;
}

Block::Block(const Block &)
{
	//??
}

Block & Block::operator=(const Block &)
{
	// TODO: insert return statement here
}

bool Block::operator==(const Block &) const
{
	return false;
}

bool Block::operator!=(const Block &) const
{
	return false;
}

std::uint16_t Block::GetXPosition() const
{
	return this->xPos;
}

std::uint16_t Block::GetYPosition() const
{
	return this->yPos;;
}

std::uint16_t Block::GetValue() const
{
	return this->startValue;
}

std::uint8_t Block::GetColourR() const
{
	return this->colourR;
}

std::uint8_t Block::GetColourG() const
{
	return this->colourG;
}

std::uint8_t Block::GetColourB() const
{
	return this->colourB;
}

void Block::ColourAsArray(std::uint8_t * colour) const
{
	
}

void Block::SetXPosition(std::uint16_t xPosArg)
{
	this->xPos = xPosArg;
}

void Block::SetYPosition(std::uint16_t yPosArg)
{
	this->yPos = yPosArg;

}

void Block::SetValue(std::uint16_t startValueArg)
{
	this->startValue = startValueArg;
}

void Block::SetColourR(std::uint8_t colourRArg)
{
	this->colourR = colourRArg;
}

void Block::SetColourG(std::uint8_t colourGArg)
{
	this->colourG = colourGArg;
}

void Block::SetColourB(std::uint8_t colourBArg)
{
	this->colourB = colourBArg;

}

void Block::SetColour(std::uint8_t * colour)
{
	// ?
}
