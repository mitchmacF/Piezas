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

TEST(PiezasTest, check_reset)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);

    game.dropPiece(1);
    game.dropPiece(1);
    game.dropPiece(1);

    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);

    game.dropPiece(3);
    game.dropPiece(3);
    game.dropPiece(3);

    game.reset();

    char piece = (char)game.pieceAt(1, 0);
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_dropPiece_blank1)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);

    char piece = (char)game.dropPiece(0);
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_dropPiece_blank2)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(1);

    char piece = (char)game.dropPiece(0);
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_dropPiece_invalid1)
{
    Piezas game;
    
    char piece = (char)game.dropPiece(5);
    
    ASSERT_EQ(piece, '?');
}

TEST(PiezasTest, check_dropPiece_invalid2)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);

    char piece = (char)game.dropPiece(-1);
    
    ASSERT_EQ(piece, '?');
}

TEST(PiezasTest, check_dropPiece_X)
{
    Piezas game;
    
    game.dropPiece(0);

    char piece = (char)game.pieceAt(0, 0);
    
    ASSERT_EQ(piece, 'X');
}

TEST(PiezasTest, check_dropPiece_O)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);

    char piece = (char)game.pieceAt(1, 0);
    
    ASSERT_EQ(piece, 'O');
}

TEST(PiezasTest, check_pieceAt_valid)
{
    Piezas game;
    
    game.dropPiece(0);

    char piece = (char)game.pieceAt(0, 0);
    
    ASSERT_EQ(piece, 'X');
}

TEST(PiezasTest, check_pieceAt_invalid1)
{
    Piezas game;
    
    game.dropPiece(0);

    char piece = (char)game.pieceAt(4, 0);
    
    ASSERT_EQ(piece, '?');
}

TEST(PiezasTest, check_pieceAt_invalid2)
{
    Piezas game;
    
    game.dropPiece(0);

    char piece = (char)game.pieceAt(0, 5);
    
    ASSERT_EQ(piece, '?');
}

TEST(PiezasTest, check_pieceAt_blank)
{
    Piezas game;
    
    game.dropPiece(0);

    char piece = (char)game.pieceAt(1, 0);
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_gameState_invalid)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);
    
    char piece = (char)game.gameState();
    
    ASSERT_EQ(piece, '?');
}

TEST(PiezasTest, check_gameState_every_other_tie)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(0);

    game.dropPiece(1);
    game.dropPiece(1);
    game.dropPiece(1);

    game.dropPiece(2);
    game.dropPiece(2);
    game.dropPiece(2);

    game.dropPiece(3);
    game.dropPiece(3);
    game.dropPiece(3);

    char piece = (char)game.gameState();
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_gameState_X_vert_O_horiz_tie)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(2);
    game.dropPiece(0);

    game.dropPiece(1);
    game.dropPiece(0);
    game.dropPiece(2);

    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(1);

    game.dropPiece(3);
    game.dropPiece(3);
    game.dropPiece(3);

    char piece = (char)game.gameState();
    
    ASSERT_EQ(piece, ' ');
}

TEST(PiezasTest, check_gameState_X_wins)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(2);
    game.dropPiece(0);

    game.dropPiece(2);
    game.dropPiece(0);
    game.dropPiece(1);

    game.dropPiece(3);
    game.dropPiece(3);
    game.dropPiece(1);

    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(3);

    char piece = (char)game.gameState();
    
    ASSERT_EQ(piece, 'X');
}

TEST(PiezasTest, check_gameState_O_wins)
{
    Piezas game;
    
    game.dropPiece(0);
    game.dropPiece(0);
    game.dropPiece(1);

    game.dropPiece(1);
    game.dropPiece(3);
    game.dropPiece(3);

    game.dropPiece(3);
    game.dropPiece(2);
    game.dropPiece(0);

    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(0);

    char piece = (char)game.gameState();
    
    ASSERT_EQ(piece, 'X');
}


