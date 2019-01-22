#ifndef TEST_BLOCK_BASED_GAME_HPP
#define TEST_BLOCK_BASED_GAME_HPP
/*******************************************************************
*						Here be Dragons
********************************************************************/
#include <string>
#include <iostream>
#include "TestingBase.hpp"

#if __has_include("BlockBasedGame.hpp")
#include "BlockBasedGame.hpp"
namespace UnitTests::BLOCK_BASED_GAMES
{
/*
* 
* Operator and constructors
* 
*/
GENERATE_HAS_MEMBER_FUNCTION(SubscriptOperator, operator[])
GENERATE_HAS_CONST_MEMBER_FUNCTION(SubscriptOperator, operator[])
static constexpr bool BlockBasedGame_is_abstract = std::is_abstract<BlockBasedGame>::value;
static constexpr bool BlockBasedGame_has_subscript_operator = has_SubscriptOperator<BlockBasedGame, Block *, std::uint8_t>::value;
static constexpr bool BlockBasedGame_has_const_subscript_operator = has_const_SubscriptOperator<BlockBasedGame, const Block *, std::uint8_t>::value;
static constexpr bool BlockBasedGame_has_virtual_destructor = std::has_virtual_destructor<BlockBasedGame>::value;

/*
*
*   Functions
*
*/
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetPuzzleSize)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GetGridSize)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(ReadHighscore)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SaveHighscore)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(Highscore)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(CurrentScore)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetBoardState)

static constexpr bool BlockBasedGame_has_GetPuzzleSize = has_const_GetPuzzleSize<BlockBasedGame, std::uint8_t>::value;
static constexpr bool BlockBasedGame_has_GetGridSize = has_const_GetGridSize<BlockBasedGame, std::uint16_t>::value;
static constexpr bool BlockBasedGame_has_ReadHighscore = has_ReadHighscore<BlockBasedGame, void, std::string>::value;
static constexpr bool BlockBasedGame_has_SaveHighscore = has_SaveHighscore<BlockBasedGame, void, std::string>::value;
static constexpr bool BlockBasedGame_has_Highscore = has_Highscore<BlockBasedGame, std::uint16_t, std::uint8_t>::value;
static constexpr bool BlockBasedGame_has_CurrentScore = has_CurrentScore<BlockBasedGame, std::uint16_t>::value;
static constexpr bool BlockBasedGame_has_SetBoardState = has_SetBoardState<BlockBasedGame, void, const std::vector<Block*> &>::value;

/*
*
*   Virtual functions
*
*/
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveUp)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveDown)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveLeft)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveRight)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GameStatus)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(UpdateScore)

static constexpr bool BlockBasedGame_has_MoveUp = has_MoveUp<BlockBasedGame, void>::value;
static constexpr bool BlockBasedGame_has_MoveDown = has_MoveDown<BlockBasedGame, void>::value;
static constexpr bool BlockBasedGame_has_MoveLeft = has_MoveLeft<BlockBasedGame, void>::value;
static constexpr bool BlockBasedGame_has_MoveRight = has_MoveRight<BlockBasedGame, void>::value;
static constexpr bool BlockBasedGame_has_GameStatus = has_const_GameStatus<BlockBasedGame, int>::value;
static constexpr bool BlockBasedGame_has_UpdateScore = has_UpdateScore<BlockBasedGame, void>::value;

constexpr bool ControlBlockBasedGameSignatures()
{
    return BlockBasedGame_is_abstract && BlockBasedGame_has_subscript_operator && BlockBasedGame_has_const_subscript_operator
        && BlockBasedGame_has_virtual_destructor && BlockBasedGame_has_GetPuzzleSize && BlockBasedGame_has_GetGridSize 
        && BlockBasedGame_has_ReadHighscore && BlockBasedGame_has_SaveHighscore && BlockBasedGame_has_Highscore 
        && BlockBasedGame_has_CurrentScore && BlockBasedGame_has_MoveUp && BlockBasedGame_has_MoveDown && BlockBasedGame_has_MoveLeft 
        && BlockBasedGame_has_MoveRight && BlockBasedGame_has_GameStatus && BlockBasedGame_has_UpdateScore && BlockBasedGame_has_SetBoardState;
}
void BlockBasedGameUnitTestingPrintErrors()
{
    if constexpr (!BlockBasedGame_is_abstract)
        std::cout << "\tBlockBasedGame is not abstract." << std::endl;
    if constexpr (!BlockBasedGame_has_subscript_operator)
        std::cout << "\tBlockBasedGame's non-const subscript operator either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_const_subscript_operator)
        std::cout << "\tBlockBasedGame's const subscript operator either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_virtual_destructor)
        std::cout << "\tBlockBasedGame does not have a virtual destructor." << std::endl;
    if constexpr (!BlockBasedGame_has_GetPuzzleSize)
        std::cout << "\tBlockBasedGame's GetPuzzleSize-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_GetGridSize)
        std::cout << "\tBlockBasedGame's GetGridSize-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_ReadHighscore)
        std::cout << "\tBlockBasedGame's ReadHighscore-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_SaveHighscore)
        std::cout << "\tBlockBasedGame's SaveHighscore-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_Highscore)
        std::cout << "\tBlockBasedGame's Highscore-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_CurrentScore)
        std::cout << "\tBlockBasedGame's CurrentScore-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_MoveUp)
        std::cout << "\tBlockBasedGame's MoveUp-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_MoveDown)
        std::cout << "\tBlockBasedGame's MoveDown-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_MoveLeft)
        std::cout << "\tBlockBasedGame's MoveLeft-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_MoveRight)
        std::cout << "\tBlockBasedGame's MoveRight-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_GameStatus)
        std::cout << "\tBlockBasedGame's GameStatus-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!BlockBasedGame_has_UpdateScore)
        std::cout << "\tBlockBasedGame's UpdateScore-function either missing or does not follow the signature given." << std::endl;
    if constexpr(!BlockBasedGame_has_SetBoardState)
        std::cout << "\tBlockBasedGame's SetBoardState-function either missing or does not follow the signature given." << std::endl;
}

template <typename T = BlockBasedGame>
bool BlockBasedGameUnitTesting()
{
    std::cout << "\t----------Start of unit testing for class BlockBasedGame--------\n"
              << std::endl;
    constexpr bool result = ControlBlockBasedGameSignatures();
    if constexpr (result)
    {
        std::cout << "\tAll functions and operators for BlockBasedGame are done according to the signature given by the project.\n"
                     "\tTests cannot be conducted on this class by itself, but the code will be tested as part of the main program."
                  << std::endl;
    }
    else
    {
        BlockBasedGameUnitTestingPrintErrors();
    }
	std::cout << "\t-----------End of unit testing for class BlockBasedGame---------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
    return result;
}
} // namespace UnitTests
#else
namespace UnitTests::BLOCK_BASED_GAMES
{
constexpr bool ControlBlockBasedGameSignatures()
{
    return false;
}
void BlockBasedGameUnitTestingPrintErrors()
{
    std::cout << "\t----------Start of unit testing for class BlockBasedGame--------\n";
    std::cout << "\tFile BlockBasedGame.hpp non-existent." << std::endl;
	std::cout << "\t-----------End of unit testing for class BlockBasedGame---------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
}

bool BlockBasedGameUnitTesting()
{
    BlockBasedGameUnitTestingPrintErrors();
    return false;
}
}
#endif

#endif