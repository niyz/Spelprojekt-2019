#include "..\..\Header Files\UnitTests\TestBlock.hpp"
#include "..\..\Header Files\UnitTests\TestBlockBasedGame.hpp"
#include "..\..\Header Files\UnitTests\TestNPuzzleGame.hpp"
#include "..\..\Header Files\UnitTests\TestPointSlidingGame.hpp"
#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    bool unitTestsPassed = true;
    unitTestsPassed = UnitTests::BLOCK::BlockUnitTests();
    if(!unitTestsPassed)
    {
        std::cout << "\t----------Unit tests failed on class: Block----------" << std::endl;
        std::cout << "\t-----------------Unit tests stopped------------------" << std::endl;
        return -1;
    }
    unitTestsPassed = UnitTests::BLOCK_BASED_GAMES::BlockBasedGameUnitTesting();
    if(!unitTestsPassed)
    {
        std::cout << "\t------Unit tests failed on class: BlockBasedGame-----" << std::endl;
        return -1;
    }
    unitTestsPassed = UnitTests::N_PUZZLE_GAME::NPuzzleGameUnitTesting();
    if(!unitTestsPassed)
    {
        std::cout << "\t-------Unit tests failed on class: NPuzzleGame-------" << std::endl;
    }
    unitTestsPassed = UnitTests::POINT_SLIDING_GAME::PointSlidingGameUnitTesting();
    if(!unitTestsPassed)
    {
        std::cout << "\t----Unit tests failed on class: PointSlidingGame----" << std::endl;
    }


    return 0;
}