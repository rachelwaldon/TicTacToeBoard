/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, outofBounds)
{
	TicTacToeBoard obj;
	Piece outcome = obj.getPiece(-5,3);
	ASSERT_EQ(outcome, Invalid);
}

TEST(TicTacToeBoardTest, firstToggle) 
{
	TicTacToeBoard obj;
	Piece nextTurn = obj.toggleTurn();
	ASSERT_EQ(nextTurn,O);
}

TEST(TicTacToeBoardTest, toggleFromO)
{
	TicTacToeBoard obj;
	Piece nextTurn = obj.toggleTurn();   
	nextTurn = obj.toggleTurn();
	ASSERT_EQ(nextTurn,X);
}

TEST(TicTacToeBoardTest, isBlank)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(2,1),Blank);
}

TEST(TicTacToeBoardTest, isX)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	ASSERT_EQ(obj.getPiece(0,0), X);
}

TEST(TicTacToeBoard, isO)
{
	TicTacToeBoard obj;
	obj.toggleTurn();
	obj.placePiece(0,0);
	ASSERT_EQ(obj.getPiece(0,0), O);
}

TEST(TicTacToeBoard, spaceTaken)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.toggleTurn();
	ASSERT_EQ(obj.placePiece(1,1), X);
}

TEST(TicTacToeBoard, placeOutofBounds)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(1,4), Invalid);
}

TEST(TicTacToeBoard, win1)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(2,2);
	obj.placePiece(0,1);
	obj.placePiece(2,0);
	obj.placePiece(2,1);
	obj.placePiece(1,2);
	obj.placePiece(0,2);
	obj.placePiece(1,1);
	obj.placePiece(1,0);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoard, gameNotOver)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,2);
	ASSERT_EQ(obj.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, catsGame)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(2,2);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(1,0);
	obj.placePiece(1,2);
	obj.placePiece(2,1);
	obj.placePiece(0,1);
	ASSERT_EQ(obj.getWinner(),Blank);
}

TEST(TicTacToeBoardTest, win2)
{
	TicTacToeBoard obj;
	obj.placePiece(1,0);
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(1,2);
	ASSERT_EQ(obj.getWinner(), X);
}
