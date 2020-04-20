/**
    TicTacToe.cpp
    Purpose: This file contains the implementation of the functions belonging to class TicTacToe declared in TicTacToe.h

    @author Srikant Singh
    @version 1.1 17/04/2020 
*/

#include "TicTacToe.h"

/**
Initializes the two dimensional board of dimension N filled with '-'
Resized the two vectors for storing current status for rows and columns
*/
void TicTacToe :: initialize()
{
    checkRows.resize(N, 0);
    checkCols.resize(N, 0);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            board[i][j] = '-';
        }
    }
}

/*
Displays to the player the current status to game before he makes a move*/
void TicTacToe :: printBoard()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << board[i][j] <<"  ";
        }
        cout <<"\n";
    }
}

/**
The actual play funtion which updates the board and returns true if the current moves results in win. The winner is checked in O(1) time.
*/
bool TicTacToe :: play(int turn, int row, int col)
{
    char curr = symbols[turn];
    board[row][col] = curr;
    checkRows[row] += (turn == 0) ? 1 : -1;
    checkCols[col] += (turn == 0) ? 1 : -1;
    if(abs(checkRows[row]) == N || abs(checkCols[col]) == N)
    {
        return true;
    }
    if(row == col)
    {
        diag += (turn == 0) ? 1 : -1;
    }
    if(row + col == N - 1)
    {
        secDiag += (turn == 0) ? 1 : -1;
    }
    if(abs(diag) == N || abs(secDiag) == N)
    {
        return true;
    }
    else
    { 
        return false;
    }
}

/**
Checks for the bounds and filled cell before every move
*/
bool TicTacToe :: checkValidMove(int row, int col)
{
  return ((row >= 0 && col >= 0 && row < N && col < N) && board[row][col] == '-');
}