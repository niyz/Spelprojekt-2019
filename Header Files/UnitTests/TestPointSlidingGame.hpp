#ifndef TEST_POINT_SLIDING_GAME_HPP
#define TEST_POINT_SLIDING_GAME_HPP
/*******************************************************************
*						Here be Dragons
********************************************************************/
#include <string>
#include <iostream>
#include <cstdint>
#include <exception>
#include "TestingBase.hpp"

#if __has_include("PointSlidingGame.hpp")
#include "PointSlidingGame.hpp"
namespace UnitTests::POINT_SLIDING_GAME
{
/*
* 
* Operator and constructors
* 
*/
static constexpr bool PointSlidingGame_has_constructor = std::is_constructible<PointSlidingGame, std::uint8_t, std::uint16_t, std::uint16_t>::value;
static constexpr bool PointSlidingGame_has_default_constructor = std::is_default_constructible<PointSlidingGame>::value;
static constexpr bool PointSlidingGame_has_copy_constructor = std::is_copy_constructible<PointSlidingGame>::value;
static constexpr bool PointSlidingGame_has_copy_assignment_constructor = std::is_copy_assignable<PointSlidingGame>::value;
static constexpr bool PointSlidingGame_is_abstract = std::is_abstract<PointSlidingGame>::value;
static constexpr bool PointSlidingGame_is_derived_from_BlockBasedGame = std::is_base_of<BlockBasedGame, PointSlidingGame>::value;

/*
*
*   Functions
*
*/
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveUp)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveDown)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveLeft)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(MoveRight)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(GameStatus)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(UpdateScore)

static constexpr bool PointSlidingGame_has_MoveUp = has_MoveUp<PointSlidingGame, void>::value;
static constexpr bool PointSlidingGame_has_MoveDown = has_MoveDown<PointSlidingGame, void>::value;
static constexpr bool PointSlidingGame_has_MoveLeft = has_MoveLeft<PointSlidingGame, void>::value;
static constexpr bool PointSlidingGame_has_MoveRight = has_MoveRight<PointSlidingGame, void>::value;
static constexpr bool PointSlidingGame_has_GameStatus = has_const_GameStatus<PointSlidingGame, int>::value;
static constexpr bool PointSlidingGame_has_UpdateScore = has_UpdateScore<PointSlidingGame, void>::value;

constexpr bool ControlPointSlidingGameSignatures()
{
    return !PointSlidingGame_is_abstract && PointSlidingGame_is_derived_from_BlockBasedGame
            && PointSlidingGame_has_constructor && !PointSlidingGame_has_default_constructor 
            && !PointSlidingGame_has_copy_constructor && !PointSlidingGame_has_copy_assignment_constructor 
            && PointSlidingGame_has_MoveUp && PointSlidingGame_has_MoveDown && PointSlidingGame_has_MoveLeft 
            && PointSlidingGame_has_MoveRight && PointSlidingGame_has_GameStatus && PointSlidingGame_has_UpdateScore;
}
void PointSlidingGameUnitTestingPrintErrors()
{
    if constexpr(PointSlidingGame_is_abstract)
        std::cout << "\tPointSlidingGame does not define all virtual functions" << std::endl;
    if constexpr(!PointSlidingGame_is_derived_from_BlockBasedGame)
        std::cout << "\tPointSlidingGame is not derived from the class BlockBaseGame" << std::endl;
    if constexpr (!PointSlidingGame_has_constructor)
        std::cout << "\tPointSlidingGame's constructor either non-existent or does not follow the signature given." << std::endl;
    if constexpr (PointSlidingGame_has_default_constructor)
        std::cout << "\tPointSlidingGame is default initializable, although the description specifies that this should not be the case." << std::endl;
    if constexpr (PointSlidingGame_has_copy_constructor || PointSlidingGame_has_copy_assignment_constructor)
        std::cout << "\tPointSlidingGame is copyable, although the description specifies that this should not be the case." << std::endl;
    if constexpr (!PointSlidingGame_has_MoveUp)
        std::cout << "\tPointSlidingGame's MoveUp-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!PointSlidingGame_has_MoveDown)
        std::cout << "\tPointSlidingGame's MoveDown-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!PointSlidingGame_has_MoveLeft)
        std::cout << "\tPointSlidingGame's MoveLeft-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!PointSlidingGame_has_MoveRight)
        std::cout << "\tPointSlidingGame's MoveRight-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!PointSlidingGame_has_GameStatus)
        std::cout << "\tPointSlidingGame's GameStatus-function either missing or does not follow the signature given." << std::endl;
    if constexpr (!PointSlidingGame_has_UpdateScore)
        std::cout << "\tPointSlidingGame's UpdateScore-function either missing or does not follow the signature given." << std::endl;
}

template <typename T = PointSlidingGame>
bool PointSlidingGameUnitTesting()
{
    std::cout << "\t----------Start of unit testing for class PointSlidingGame--------\n"
              << std::endl;
    constexpr bool result = ControlPointSlidingGameSignatures();
    if constexpr (result)
    {
        bool testPassed = true;
        try
        {
            T game(4, 100, 1024);
            try
            {
                std::uint8_t numberOf2 = 0;
                for(std::uint8_t index = 0; index != 16; ++index)
                {
                    if(!game[index])
                        continue;
                    if(game[index]->GetValue() == 2)
                        ++numberOf2;
                }
                if(numberOf2 != 2)
                {
                    std::cout << "\tError: Expected to find 2 bricks with the value 2." << std::endl;
                    std::cout << "\t Unit test on PointSlidingGame cannot continue." << std::endl;
					std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
						<< std::endl;
					std::cout << '\n'
						<< std::endl;
                    return false;
                }
            }
            catch(const std::exception *e)
            {
                std::cout << "\tError: Exception when testing subscript operator. Information: " << e->what() << std::endl;
                std::cout << "\t Unit test on PointSlidingGame cannot continue." << std::endl;
				std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
					<< std::endl;
				std::cout << '\n'
					<< std::endl;
                return false;
            }
        }
        catch(const std::exception *e)
        {
            std::cout << "\tError: Exception when testing constructor. Information: " << e->what() << std::endl;
            std::cout << "\t Unit test on PointSlidingGame cannot continue." << std::endl;
			std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
				<< std::endl;
			std::cout << '\n'
				<< std::endl;
            return false;
        }
        try
        {
            T game(4, 100, 1024);
            std::vector<Block*> blocks;
            for(std::uint8_t index = 0; index != 16; ++index)
            {
                if(game[index])
                {
                    game[index]->SetValue(1024);
                    break;
                }
            }

            if(game.GameStatus() != 1)
            {
                std::cout << "\tError: Game indicates failure on finished board." << std::endl;
				std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
					<< std::endl;
				std::cout << '\n'
					<< std::endl;
                testPassed = false;
            }
            blocks.push_back(new Block(0, 0, 2, 0, 0, 0));
            blocks.push_back(new Block(100, 0, 2, 0, 0, 0));
            for(std::uint8_t i = 0; i != 14; ++i)
                blocks.push_back(nullptr);
            game.SetBoardState(blocks);
			for (std::uint8_t index = 0; index != 16; ++index)
			{
				if (!game[index] && !blocks[index])
					continue;
				if ((!game[index] && blocks[index]) || (game[index] && !blocks[index]))
				{
					std::cout << "\tError: SetBoardState did not change the board as expected." << std::endl;
					std::cout << "\t Unit test on PointSlidingGameGame cannot continue." << std::endl;
					for (auto toDelete : blocks)
						delete toDelete;
					std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
						<< std::endl;
					std::cout << '\n'
						<< std::endl;
					return false;
				}
				if (*game[index] != *blocks[index])
				{
					std::cout << "\tError: SetBoardState did not change the board as expected." << std::endl;
					std::cout << "\t Unit test on PointSlidingGameGame cannot continue." << std::endl;
					for (auto toDelete : blocks)
						delete toDelete;
					std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
						<< std::endl;
					std::cout << '\n'
						<< std::endl;
					return false;
				}
			}
            game.MoveLeft();
            if(!game[0] || game[0]->GetValue() != 4)
            {
                std::cout << "\tError: MoveLeft not done correctly." << std::endl;
                testPassed = false;
            }
            std::uint8_t numberOfBlocks = 0;
            for(std::uint8_t index = 0; index != 16; ++index)
            {
                if(game[index])
                    numberOfBlocks++;
            }
            if(numberOfBlocks != 2)
            {
                std::cout << "\tError: Wrong amount of blocks after MoveLeft operation." << std::endl;
                testPassed = false;
            }
            
            blocks[3] = new Block(300, 0, 4, 0,0,0);
            game.SetBoardState(blocks);
            game.MoveRight();
            if(!game[3] || game[3]->GetValue() != 4 || !game[2] || game[2]->GetValue() != 4)
            {
                std::cout << "\tError: MoveRight not done correctly." << std::endl;
                testPassed = false;
            }
            numberOfBlocks = 0;
            for(std::uint8_t index = 0; index != 16; ++index)
            {
                if(game[index])
                    numberOfBlocks++;
            }
            if(numberOfBlocks != 3)
            {
                std::cout << "\tError: Wrong amount of blocks after MoveRight operation." << std::endl;
                testPassed = false;
            }
            
            blocks[4] = new Block(0, 100, 2, 0, 0, 0);
            game.SetBoardState(blocks);
            game.MoveUp();
            if(!game[0] || game[0]->GetValue() != 4 || !game[3] || game[3]->GetValue() != 4 || !game[1] || game[1]->GetValue() != 2)
            {
                std::cout << "\tError: MoveUp not done correctly." << std::endl;
                testPassed = false;
            }
            numberOfBlocks = 0;
            for(std::uint8_t index = 0; index != 16; ++index)
            {
                if(game[index])
                    numberOfBlocks++;
            }
            if(numberOfBlocks != 4)
            {
                std::cout << "\tError: Wrong amount of blocks after MoveUp operation." << std::endl;
                testPassed = false;
            }
            game.SetBoardState(blocks);
            game.MoveDown();
            if(!game[12] || game[12]->GetValue() != 4 || !game[15] || game[15]->GetValue() != 4 || !game[13] || game[13]->GetValue() != 2)
            {
                std::cout << "\tError: MoveDown not done correctly." << std::endl;
                testPassed = false;
            }
            numberOfBlocks = 0;
            for(std::uint8_t index = 0; index != 16; ++index)
            {
                if(game[index])
                    numberOfBlocks++;
            }
            if(numberOfBlocks != 4)
            {
                std::cout << "\tError: Wrong amount of blocks after MoveDown operation." << std::endl;
                testPassed = false;
            }

            game.SetBoardState(blocks);
            game.UpdateScore();
            if(game.CurrentScore() != 10)
            {
                std::cout << "\tError: Score was not calculated correctly." << std::endl;   
                testPassed = false;
            }
			for (auto ptr : blocks)
				delete ptr;

        }
        catch(const std::exception *e)
        {
            std::cout << "\tError: Unspecified error occured. Information: " << e->what() << std::endl;
			std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
				<< std::endl;
			std::cout << '\n'
				<< std::endl;
            return false;
        }
		std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
			<< std::endl;
		std::cout << '\n'
			<< std::endl;
        return testPassed;
    }
    else
    {
        PointSlidingGameUnitTestingPrintErrors();
    }
	std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
    return result;
}
} // namespace UnitTests::EIGHT_GAME
#else
namespace UnitTests::POINT_SLIDING_GAME
{
constexpr bool ControlPointSlidingGameSignatures()
{
    return false;
}
void PointSlidingGameUnitTestingPrintErrors()
{
    std::cout << "\t----------Start of unit testing for class PointSlidingGame--------\n"
              << std::endl;
    std::cout << "\tFile PointSlidingGame.hpp non-existent." << std::endl;
	std::cout << "\t-----------End of unit testing for class PointSlidingGame---------\n"
		<< std::endl;
    std::cout << '\n'
              << std::endl;
}

bool PointSlidingGameUnitTesting()
{
    PointSlidingGameUnitTestingPrintErrors();
    return false;
}
} // namespace UnitTests::EIGHT_GAME
#endif

#endif