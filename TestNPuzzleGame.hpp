#ifndef TEST_N_PUZZLE_GAME_HPP
#define TEST_N_PUZZLE_GAME_HPP
/*******************************************************************
*						Here be Dragons
********************************************************************/
#include <string>
#include <iostream>
#include <exception>
#include <cstdint>
#include "TestingBase.hpp"

#if __has_include("NPuzzleGame.hpp")
#include "NPuzzleGame.hpp"
namespace UnitTests::N_PUZZLE_GAME
{
	/*
	*
	* Operator and constructors
	*
	*/
	static constexpr bool NPuzzleGame_has_constructor = std::is_constructible<NPuzzleGame, std::uint8_t, std::uint16_t>::value;
	static constexpr bool NPuzzleGame_has_default_constructor = std::is_default_constructible<NPuzzleGame>::value;
	static constexpr bool NPuzzleGame_has_copy_constructor = std::is_copy_constructible<NPuzzleGame>::value;
	static constexpr bool NPuzzleGame_has_copy_assignment_constructor = std::is_copy_assignable<NPuzzleGame>::value;
	static constexpr bool NPuzzleGame_is_abstract = std::is_abstract<NPuzzleGame>::value;
	static constexpr bool NPuzzleGame_is_derived_from_BlockBasedGame = std::is_base_of<BlockBasedGame, NPuzzleGame>::value;

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
		GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(SetBoardState)

		static constexpr bool NPuzzleGame_has_MoveUp = has_MoveUp<NPuzzleGame, void>::value;
	static constexpr bool NPuzzleGame_has_MoveDown = has_MoveDown<NPuzzleGame, void>::value;
	static constexpr bool NPuzzleGame_has_MoveLeft = has_MoveLeft<NPuzzleGame, void>::value;
	static constexpr bool NPuzzleGame_has_MoveRight = has_MoveRight<NPuzzleGame, void>::value;
	static constexpr bool NPuzzleGame_has_GameStatus = has_const_GameStatus<NPuzzleGame, int>::value;
	static constexpr bool NPuzzleGame_has_UpdateScore = has_UpdateScore<NPuzzleGame, void>::value;
	static constexpr bool NPuzzleGame_has_SetBoardState = has_SetBoardState<BlockBasedGame, void, const std::vector<Block*> &>::value;

	constexpr bool ControlNPuzzleGameignatures()
	{
		return !NPuzzleGame_is_abstract && NPuzzleGame_is_derived_from_BlockBasedGame
			&& NPuzzleGame_has_constructor && !NPuzzleGame_has_default_constructor
			&& !NPuzzleGame_has_copy_constructor && !NPuzzleGame_has_copy_assignment_constructor
			&& NPuzzleGame_has_MoveUp && NPuzzleGame_has_MoveDown && NPuzzleGame_has_MoveLeft
			&& NPuzzleGame_has_MoveRight && NPuzzleGame_has_GameStatus && NPuzzleGame_has_UpdateScore
			&& NPuzzleGame_has_SetBoardState;
	}
	void NPuzzleGameUnitTestingPrintErrors()
	{
		if constexpr (NPuzzleGame_is_abstract)
			std::cout << "\tNPuzzleGame does not define all virtual functions" << std::endl;
		if constexpr (!NPuzzleGame_is_derived_from_BlockBasedGame)
			std::cout << "\tNPuzzleGame is not derived from the class BlockBaseGame" << std::endl;
		if constexpr (!NPuzzleGame_has_constructor)
			std::cout << "\tNPuzzleGame's constructor either non-existent or does not follow the signature given." << std::endl;
		if constexpr (NPuzzleGame_has_default_constructor)
			std::cout << "\tNPuzzleGame is default initializable, although the description specifies that this should not be the case." << std::endl;
		if constexpr (NPuzzleGame_has_copy_constructor || NPuzzleGame_has_copy_assignment_constructor)
			std::cout << "\tNPuzzleGame is copyable, although the description specifies that this should not be the case." << std::endl;
		if constexpr (!NPuzzleGame_has_MoveUp)
			std::cout << "\tNPuzzleGame's MoveUp-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_MoveDown)
			std::cout << "\tNPuzzleGame's MoveDown-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_MoveLeft)
			std::cout << "\tNPuzzleGame's MoveLeft-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_MoveRight)
			std::cout << "\tNPuzzleGame's MoveRight-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_GameStatus)
			std::cout << "\tNPuzzleGame's GameStatus-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_UpdateScore)
			std::cout << "\tNPuzzleGame's UpdateScore-function either missing or does not follow the signature given." << std::endl;
		if constexpr (!NPuzzleGame_has_SetBoardState)
			std::cout << "\tNPuzzleGame's SetBoardState-function either missing or does not follow the signature given." << std::endl;

	}

	template <typename T = NPuzzleGame>
	bool NPuzzleGameUnitTesting()
	{
		std::cout << "\t----------Start of unit testing for class NPuzzleGame--------\n"
			<< std::endl;
		constexpr bool result = ControlNPuzzleGameignatures();
		if constexpr (result)
		{
			bool testPassed = true;
			try
			{
				T game(3, 100);
				try
				{
					bool nullptrFound = false;
					for (std::uint8_t index = 0; index != 9; ++index)
					{
						if (game[index])
							continue;
						nullptrFound = true;
						break;
					}
					if (!nullptrFound)
					{
						std::cout << "\tError: Expected a nullptr to be returned from the subscript operator." << std::endl;
						std::cout << "\t Unit test on NPuzzleGame cannot continue." << std::endl;
						std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
							<< std::endl;
						std::cout << '\n'
							<< std::endl;
						return false;
					}
				}
				catch (const std::exception *e)
				{
					std::cout << "\tError: Exception when testing subscript operator. Information: " << e->what() << std::endl;
					std::cout << "\t Unit test on NPuzzleGame cannot continue." << std::endl;
					std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
						<< std::endl;
					std::cout << '\n'
						<< std::endl;
					return false;
				}
			}
			catch (const std::exception *e)
			{
				std::cout << "\tError: Exception when testing constructor. Information: " << e->what() << std::endl;
				std::cout << "\t Unit test on NPuzzleGame cannot continue." << std::endl;
				std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
					<< std::endl;
				std::cout << '\n'
					<< std::endl;
				return false;
			}
			try {
				for (std::uint16_t iteration = 0; testPassed && iteration != 10000; ++iteration)
				{
					T game(3, 100);
					std::uint64_t inversions = 0;
					for (std::uint8_t index = 0; index != 9; ++index)
					{
						if (!game[index])
							continue;
						std::uint16_t indexValue = game[index]->GetValue();
						for (std::uint8_t indexAfter = index; indexAfter != 9; ++indexAfter)
						{
							if (!game[indexAfter])
								continue;
							if (game[indexAfter]->GetValue() < indexValue)
								++inversions;
						}
					}
					if ((inversions % 2) != 0)
					{
						testPassed = false;
						std::cout << "\tSolvability not guaranteed." << std::endl;
					}
				}
				if (testPassed)
					std::cout << "\tSolvability probable, but not guaranteed." << std::endl;

				testPassed = true;
				T game(3, 100);
				std::vector<Block*> blocks;
				std::vector<Block*> originalBlocks;
				for (std::uint8_t i = 0; i != 8; ++i)
				{
					blocks.push_back(new Block((i % 3) * 100, (i / 3) * 100, i + 1, 0, 0, 0));
					if (game[i])
						originalBlocks.push_back(new Block(*game[i]));
					else
						originalBlocks.push_back(nullptr);
				}
				if (game[8])
					originalBlocks.push_back(new Block(*game[8]));
				else
					originalBlocks.push_back(nullptr);
				game.SetBoardState(blocks);
				for (std::uint8_t i = 0; i != 9; ++i)
				{
					if (!game[i] && !originalBlocks[i])
						continue;
					else if ((!game[i] && originalBlocks[i]) || (game[i] && !originalBlocks[i]))
					{
						std::cout << "\tError: SetBoardState changed when called with vector smaller than expected." << std::endl;
						testPassed = false;

						game.SetBoardState(originalBlocks);
						break;
					}
					if (*game[i] != *originalBlocks[i])
					{
						std::cout << "\tError: SetBoardState changed when called with vector smaller than expected." << std::endl;
						testPassed = false;

						game.SetBoardState(originalBlocks);
						break;
					}
				}
				blocks.push_back(nullptr);
				game.SetBoardState(blocks);
				for (std::uint8_t i = 0; i != 9; ++i)
				{
					for (std::uint8_t u = 0; u != 9; u++)
					{
						std::cout << "game[" << unsigned(u) << "] : " << game[u] << std::endl;
						std::cout << "blocks[" << unsigned(u) << "] : " << blocks[u] << std::endl;
					}
					

					//printish?
					if (!game[i] && !blocks[i])
						continue;
					if ((!game[i] && blocks[i]) || (game[i] && !blocks[i]))
					{
						std::cout << "\tError: SetBoardState did not change the board as expected." << std::endl;
						std::cout << "\t Unit test on NPuzzleGame cannot continue." << std::endl;
						for (auto toDelete : blocks)
							delete toDelete;
						for (auto toDelete : originalBlocks)
							delete toDelete;
						std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
							<< std::endl;
						std::cout << '\n'
							<< std::endl;
						return false;
					}
					else if (*game[i] != *blocks[i])
					{
						std::cout << "\tError: SetBoardState did not change the board as expected." << std::endl;
						std::cout << "\t Unit test on NPuzzleGame cannot continue." << std::endl;
						for (auto toDelete : blocks)
							delete toDelete;
						for (auto toDelete : originalBlocks)
							delete toDelete;
						std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
							<< std::endl;
						std::cout << '\n'
							<< std::endl;
						return false;
					}
				}
				if (!game.GameStatus())
				{
					std::cout << "\tError: GameStatus indicates failure on finished board." << std::endl;
					testPassed = false;
				}

				for (auto toDelete : blocks)
					delete toDelete;
				game.SetBoardState(originalBlocks);
				for (auto toDelete : originalBlocks)
					delete toDelete;

				blocks.clear();
				blocks = { new Block(0, 0, 4, 0, 0, 0), new Block(100, 0, 5, 0, 0, 0), new Block(200, 0, 6, 0, 0, 0),
						new Block(0, 100, 1, 0, 0, 0), nullptr, new Block(200, 100, 2, 0, 0, 0),
						new Block(0, 200, 3, 0, 0, 0), new Block(100, 200, 7, 0, 0, 0), new Block(200, 200, 8, 0, 0, 0) };

				game.SetBoardState(blocks);
				if (game.GameStatus())
				{
					std::cout << "\tError: GameStatus indicates success on non-finished board." << std::endl;
					testPassed = false;
				}
				game.UpdateScore();
				if (game.CurrentScore() != 0)
				{
					std::cout << "\tError: Indicating that the score has increased without a move." << std::endl;
					testPassed = false;
				}

				game.MoveUp();
				if (!game[4])
				{
					std::cout << "\tError: MoveUp not done correctly." << std::endl;
					testPassed = false;
				}
				else if (game[4]->GetValue() != 7)
				{
					std::cout << "\tError: MoveUp not done correctly." << std::endl;
					testPassed = false;
				}

				game.SetBoardState(blocks);
				game.MoveDown();
				if (!game[4])
				{
					std::cout << "\tError: MoveDown not done correctly." << std::endl;
					testPassed = false;
				}
				else if (game[4]->GetValue() != 5)
				{
					std::cout << "\tError: MoveDown not done correctly." << std::endl;
					testPassed = false;
				}

				game.SetBoardState(blocks);
				game.MoveLeft();
				if (!game[4])
				{
					std::cout << "\tError: MoveLeft not done correctly." << std::endl;
					testPassed = false;
				}
				else if (game[4]->GetValue() != 2)
				{
					std::cout << "\tError: MoveLeft not done correctly." << std::endl;
					testPassed = false;
				}

				game.SetBoardState(blocks);
				game.MoveRight();
				if (!game[4])
				{
					std::cout << "\tError: MoveRight not done correctly." << std::endl;
					testPassed = false;
				}
				else if (game[4]->GetValue() != 1)
				{
					std::cout << "\tError: MoveRight not done correctly." << std::endl;
					testPassed = false;
				}

				game.UpdateScore();
				if (game.CurrentScore() != 4)
				{
					std::cout << "\tError: Score does not represent four moves after four moves." << std::endl;
					testPassed = false;
				}

				for (auto deletePtr : blocks)
					delete deletePtr;
			}
			catch (std::exception *e)
			{
				std::cout << "\tError: Unspecified error occured. Information: " << e->what() << std::endl;
				std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
					<< std::endl;
				std::cout << '\n'
					<< std::endl;
				return false;
			}
			std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
				<< std::endl;
			std::cout << '\n'
				<< std::endl;
			return testPassed;
		}
		else
		{
			NPuzzleGameUnitTestingPrintErrors();
		}
		std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
			<< std::endl;
		std::cout << '\n'
			<< std::endl;
		return result;
	}
} // namespace UnitTests::NPuzzleGame_GAME
#else
namespace UnitTests::N_PUZZLE_GAME
{
	constexpr bool ControlNPuzzleGameignatures()
	{
		return false;
	}
	void NPuzzleGameUnitTestingPrintErrors()
	{
		std::cout << "\t----------Start of unit testing for class NPuzzleGame--------\n"
			<< std::endl;
		std::cout << "\tFile NPuzzleGame.hpp non-existent." << std::endl;
		std::cout << "\t-----------End of unit testing for class NPuzzleGame---------\n"
			<< std::endl;
		std::cout << '\n'
			<< std::endl;
	}

	bool NPuzzleGameUnitTesting()
	{
		NPuzzleGameUnitTestingPrintErrors();
		return false;
	}
} // namespace UnitTests::NPuzzleGame_GAME
#endif

#endif