/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(PiezasTest, Piezas)
{
  Piezas game;
  bool value = true;
  for(int i = 0; i <BOARD_ROWS; i++){
    for(int j = 0; j <BOARD_COLS; j++ ){
      if(game.pieceAt(i,j) != Blank){
        value = false;
      }
    }
  }
  ASSERT_TRUE(value);
}
TEST(PiezasTest, reset)
{
  Piezas game;
  bool value = true;
  for(int i = 0; i <BOARD_ROWS; i++){
    for(int j = 0; j <BOARD_COLS; j++ ){
      if(game.pieceAt(i,j) != Blank){
        value = false;
      }
    }
  }
  ASSERT_TRUE(value);
}
TEST(PiezasTest, dropPiece_Valid)
{
  Piezas game;
  Piece value  = game.dropPiece(0);
  EXPECT_EQ(X, value);
  value  = game.dropPiece(0);
  EXPECT_EQ(0, value);
  value  = game.dropPiece(0);
  EXPECT_EQ(X, value);
}
TEST(PiezasTest, dropPiece_InValid)
{
  Piezas game;
  Piece value = game.dropPiece(-1);
  EXPECT_EQ(Invalid, value);
  value = game.dropPiece(4);
  EXPECT_EQ(Invalid, value);
}
TEST(PiezasTest, dropPiece_No_Room)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  Piece value  = game.dropPiece(0);
  EXPECT_EQ(Blank, value);
}
TEST(PiezasTest, pieceAt)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  EXPECT_EQ(X,game.pieceAt(0,0));
  EXPECT_EQ(O,game.pieceAt(0,1));
  EXPECT_EQ(X,game.pieceAt(1,0));
}
TEST(PiezasTest, pieceAt_Reset)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.reset();
  EXPECT_EQ(Blank, game.pieceAt(0,0));
}
TEST(PiezasTest, pieceAt_Invalid)
{
  Piezas game;
  EXPECT_EQ(Invalid, game.pieceAt(-1,2));
  EXPECT_EQ(Invalid, game.pieceAt(5,2));
  EXPECT_EQ(Invalid, game.pieceAt(1,-2));
  EXPECT_EQ(Invalid, game.pieceAt(1,20));
}
TEST(PiezasTest, gameState_Tie)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  EXPECT_EQ(Blank, game.gameState());
}
TEST(PiezasTest, gameState_Invalid)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  EXPECT_EQ(Invalid, game.gameState());
}
TEST(PiezasTest, gameState_X_win)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(3);
  EXPECT_EQ(X, game.gameState());
}
TEST(PiezasTest, gameState_O_win)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(2);
  EXPECT_EQ(O, game.gameState());
}
