#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    Piece blank_piece = Blank;
    vector<vector<Pieces> > temp(3, vector<Pieces>(4, blank_piece));
    board = temp;
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    Piece blank_piece = Blank;
    for(auto vec : board) 
        for(Piece : vec) 
            Piece = Blank;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(board[2][column] != Blank) {
        if(turn == X)
            turn = O;
        else 
            turn = X;
        return Blank;
    }

    if(!(0 <= column <= 2)) {
        if(turn == X)
            turn = O;
        else 
            turn = X;
        return Invalid;
    }

    if(board[0][column] == Blank) 
        board[0][column] = turn;
    else if(board[1][column] == Blank) 
        board[1][column] = turn;
    else 
        board[2][column] = turn;
    

    if(turn == X) {
        turn = O;
        return X;
    } else {
        turn = X;
        return O;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    bool game_over = true;

    Piece blank_piece = Blank;
    for(auto vec : board) {
        for(Piece : vec) {
            if(Piece == Blank)
                game_over = false; 
                break;
        }
    }

    if(game_over)
        return Invalid;
   
    int countX = 0;
    vector<int> countRowX(4,0);

    for(int i=0; i<3; i++) {
        countX=0;
        for(int j=0; j<4; j++) {
           if(board[i][j] == X) {
               countX++;
               if(countX > countRowX[i])
                    countRowX[i] = countX;
           } else {
               countX = 0;
           }
       }
       if(countX == 3)
           break;
    }

    countX = 0;
    vector<int> countColX(4,0);

    for(int i=0; i<4; i++) {
        countX=0;
        for(int j=0; j<3; j++) {
           if(board[j][i] == X) {
               countX++;
               if(countX > countColX[i])
                    countColX[i] = countX;
           } else {
               countX = 0;
           }
       }
       if(countX == 3)
           break;
    }
    
    int countO = 0;
    vector<int> countRowO(4,0);

    for(int i=0; i<3; i++) {
        countO=0;
        for(int j=0; j<4; j++) {
           if(board[i][j] == X) {
               countO++;
               if(countO > countRowO[i])
                    countRowO[i] = countO;
           } else {
               countO = 0;
           }
       }
       if(countO == 3)
           break;
    }

    countO = 0;
    vector<int> countColO(4,0);

    for(int i=0; i<4; i++) {
        countO=0;
        for(int j=0; j<3; j++) {
           if(board[j][i] == O) {
               countO++;
               if(countO > countColO[i])
                    countColO[i] = countO;
           } else {
               countO = 0;
           }
       }
       if(countO == 3)
           break;
    }

    // now countO and countX will signify greatest number of adjacent pieces
    countO = 0
    countX = 0;

    for(int i=0; i<(int)countColO.size(); i++) {
       if(countColO[i] > countO)
           countO = countColO[i];
       if(countColX[i] > countX)
           countX = countColX[i];
    }
    
    for(int i=0; i<(int)countRowO.size(); i++) {
       if(countRowO[i] > countO)
           countO = countRowO[i];
       if(countRowX[i] > countX)
           countX = countRowX[i];
    }

    if(countO == countX)
        return Blank;
    else if(countO > countX)
        return O;
    else
        return X;

}
