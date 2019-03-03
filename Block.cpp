#include "Block.hpp"


Block::Block(std::uint16_t xPos, std::uint16_t yPos, std::uint16_t startValue, std::uint8_t colourR, std::uint8_t colourG, std::uint8_t colourB)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->startValue = startValue;
	this->colourR = colourR;
	this->colourG = colourG;
	this->colourB = colourB;
}

Block::~Block()
{
}

Block::Block(const Block &rhs)
{
	//NOTE: Behöver ingen copy konstruktor då denna skapas per automatik vid kompilering. Dock en shallow copy, så hade vi haft med t.ex. pekare med som medlemsvariabler hade en Deep Copy behövts att göra, vilket inte skapas vid kompilering.

	if (this != &rhs)
	{
		this->xPos = rhs.xPos;
		this->yPos = rhs.yPos;
		this->startValue = rhs.startValue;
		this->colourR = rhs.colourR;
		this->colourG = rhs.colourG;
		this->colourB = rhs.colourB;
	}
}

Block & Block::operator=(const Block &rhs)
{
	if (this != &rhs)
	{
		this->xPos = rhs.xPos;
		this->yPos = rhs.yPos;
		this->startValue = rhs.startValue;
		this->colourR = rhs.colourR;
		this->colourG = rhs.colourG;
		this->colourB = rhs.colourB;
	}
	return *this;
}

bool Block::operator==(const Block &rhs) const
{
	bool equal = false;
	if (this->startValue == rhs.startValue)
		equal = true;
	return equal;
}

bool Block::operator!=(const Block &rhs) const
{
	//Returns TRUE if the statement is false.
	/*bool notEqual = false;
	if (this->xPos != rhs.xPos ||
		this->yPos != rhs.yPos ||
		this->startValue != rhs.startValue ||
		this->colourR != rhs.colourR ||
		this->colourG != rhs.colourG ||
		this->colourB != rhs.colourB)
		notEqual = true;
	return notEqual;*/

	bool notEqual = false;

	if (this->startValue != rhs.startValue)
		notEqual = true;

	return notEqual;
}

std::uint16_t Block::GetXPosition() const
{
	return this->xPos;
}

std::uint16_t Block::GetYPosition() const
{
	return this->yPos;
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
	colour[0] = GetColourR();
	colour[1] = GetColourG();
	colour[2] = GetColourB();
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
	this->colourR = colour[0];
	this->colourG = colour[1];
	this->colourB = colour[2];
}
