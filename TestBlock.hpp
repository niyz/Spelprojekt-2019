#ifndef TEST_BLOCK_HPP
#define TEST_BLOCK_HPP

/*******************************************************************
*						Here be Dragons
********************************************************************/

#include "TestingBase.hpp"
#include <cstdint>
#include <iostream>

#if __has_include("Block.hpp")
#include "Block.hpp"
namespace UnitTests::BLOCK
{
/*
*
*   Operator and Constructors
*
*/
GENERATE_HAS_MEMBER_FUNCTION(BlockAssignment, operator=)
GENERATE_HAS_CONST_MEMBER_FUNCTION(BlockEquality, operator==)
GENERATE_HAS_CONST_MEMBER_FUNCTION(BlockInequality, operator!=)

static constexpr bool Block_has_constructor = std::is_constructible<Block, std::uint16_t, std::uint16_t, std::uint16_t, std::uint8_t, std::uint8_t, std::uint8_t>::value;
static constexpr bool Block_has_copy_constructor = std::is_constructible<Block, const Block>::value;
static constexpr bool Block_has_assignment_operator = has_BlockAssignment<Block, Block &, const Block &>::value;
static constexpr bool Block_has_equality_operator = has_const_BlockEquality<Block, bool, const Block &>::value;
static constexpr bool Block_has_inequality_operator = has_const_BlockInequality<Block, bool, const Block&>::value;

/*
* 
* 
*   Get functions 
* 
* 
*/
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetXPosition)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetYPosition)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetValue)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetColourR)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetColourG)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetColourB)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(ColourAsArray)

static constexpr bool Block_has_GetXPosition = has_const_GetXPosition<Block, std::uint16_t>::value;
static constexpr bool Block_has_GetYPosition = has_const_GetYPosition<Block, std::uint16_t>::value;
static constexpr bool Block_has_GetValue = has_const_GetValue<Block, std::uint16_t>::value;
static constexpr bool Block_has_GetColourR = has_const_GetColourR<Block, std::uint8_t>::value;
static constexpr bool Block_has_GetColourG = has_const_GetColourG<Block, std::uint8_t>::value;
static constexpr bool Block_has_GetColourB = has_const_GetColourB<Block, std::uint8_t>::value;
static constexpr bool Block_has_GetColourAsArray = has_const_ColourAsArray<Block, void, std::uint8_t *>::value;

/*
* 
* 
*   Set functions 
* 
* 
*/
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetXPosition)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetYPosition)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetValue)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetColourR)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetColourG)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetColourB)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetColour)

static constexpr bool Block_has_SetXPosition = has_SetXPosition<Block, void, std::uint16_t>::value;
static constexpr bool Block_has_SetYPosition = has_SetYPosition<Block, void, std::uint16_t>::value;
static constexpr bool Block_has_SetValue = has_SetValue<Block, void, std::uint16_t>::value;
static constexpr bool Block_has_SetColourR = has_SetColourR<Block, void, std::uint8_t>::value;
static constexpr bool Block_has_SetColourG = has_SetColourG<Block, void, std::uint8_t>::value;
static constexpr bool Block_has_SetColourB = has_SetColourB<Block, void, std::uint8_t>::value;
static constexpr bool Block_has_SetColour = has_SetColour<Block, void, std::uint8_t *>::value;

constexpr bool ControlBlockSignatures()
{
    return Block_has_constructor && Block_has_copy_constructor && Block_has_assignment_operator && Block_has_equality_operator && Block_has_inequality_operator && Block_has_GetXPosition && Block_has_GetYPosition && Block_has_GetValue && Block_has_GetColourR && Block_has_GetColourG && Block_has_GetColourB && Block_has_GetColourAsArray && Block_has_SetXPosition && Block_has_SetYPosition && Block_has_SetValue && Block_has_SetColourR && Block_has_SetColourG && Block_has_SetColourB && Block_has_SetColour;
}

void BlockUnitTestingPrintErrorMessages()
{
    if constexpr (!Block_has_constructor)
        std::cout << "\tBlock's constructor either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_copy_constructor)
        std::cout << "\tBlock's copy constructor either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_assignment_operator)
        std::cout << "\tBlock's assignment operator either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_equality_operator)
        std::cout << "\tBlock's equality operator either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_inequality_operator)
        std::cout << "\tBlock's not equal to operator either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetXPosition)
        std::cout << "\tBlock's GetXPosition-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetYPosition)
        std::cout << "\tBlock's GetYPosition-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetColourR)
        std::cout << "\tBlock's GetColourR-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetColourG)
        std::cout << "\tBlock's GetColourG-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetColourB)
        std::cout << "\tBlock's GetColourB-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_GetColourAsArray)
        std::cout << "\tBlock's GetColourAsArray-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetXPosition)
        std::cout << "\tBlock's SetXPosition-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetYPosition)
        std::cout << "\tBlock's SetYPosition-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetValue)
        std::cout << "\tBlock's SetValue-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetColourR)
        std::cout << "\tBlock's SetColourR-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetColourG)
        std::cout << "Block's SetColourG-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetColourB)
        std::cout << "\tBlock's SetColourB-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!Block_has_SetColour)
        std::cout << "\tBlock's SetColour-function either missing or does not follow the signature given." << std::endl;
}

template <typename T = Block>
bool BlockUnitTests()
{
    constexpr bool result = ControlBlockSignatures();
    std::cout << "\t----------Start of unit testing for class Block----------\n"
              << std::endl;
    
    if constexpr (result)
    {
        T blockOne(100, 100, 250, 250, 0, 0);
        T blockTwo(10, 10, 250, 0, 0, 0);
        if (blockOne == blockTwo)
            std::cout << "\tEquality operator correctly implemented." << std::endl;
        else
            std::cout << "\tEquality operator not implemented as described in the documentation." << std::endl;

        uint8_t colourArray[3];
        blockOne.ColourAsArray(colourArray);
        if (colourArray[0] == 250 && colourArray[1] == 0 && colourArray[2] == 0)
            std::cout << "\tColourAsArray implemented correctly." << std::endl;
        else
            std::cout << "\tColourAsArray not implemented as described in the documentation." << std::endl;
        blockTwo.SetColour(colourArray);
        if (blockTwo.GetColourR() == colourArray[0] && blockTwo.GetColourG() == colourArray[1] && blockTwo.GetColourB() == colourArray[2])
            std::cout << "\tSetColour implemented correctly." << std::endl;
        else
            std::cout << "\tSetColour not implemented as described in the documentation." << std::endl;
    }
    else
    {
        BlockUnitTestingPrintErrorMessages();
    }
	std::cout << "\t-----------End of unit testing for class Block-----------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
    return result;
}
} // namespace UnitTests::BLOCK
#else
namespace UnitTests::BLOCK
{
constexpr bool ControlBlockSignatures()
{
    return false;
}

void BlockUnitTestingPrintErrorMessages()
{
    std::cout << "File Block.hpp non-existent." << std::endl;
}

bool BlockUnitTests()
{
    std::cout << "\t----------Start of unit testing for class Block----------\n"
              << std::endl;
    std::cout << "\tFile Block.hpp non-existent." << std::endl;
	std::cout << "\t-----------End of unit testing for class Block-----------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
    return false;
}
} // namespace UnitTests::Block
#endif

#endif