#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

class TicTacToe
{
    private:
    vector <vector<char>> board;
    int N;
    const string symbols = "XO";
    vector <int> checkRows, checkCols;
    int diag, secDiag;

    public :

    /**
    Constructor to create the TicTacToe board of given size.
    @param N is dimension of the TicTacToe
    */
    TicTacToe(int N)
    {
        this->N = N;
        board.resize(N, vector <char>(N,'-'));
    }
  
    /**
    Initializes the TicTacToe with '-'. This function is called 
    everytime a new game is started.

    @param None
    @return void
    */
    void initialize();

    /**
    Prints the current status of the board. It is displayed to a player before he makes a move.

    @param None
    @return void
    */
    void printBoard();

    /**
    It is called when the player enters a valid position. It updates the board with current symbol.

    @param turn which corresponds to a particular player 
    @param row is the row number of current move
    @param col is the column number of current move
    @return true if the current move results in win, else false
    */
    bool play(int turn, int row, int col);

    /**
    It checks if the current input by the player is valid or not.
    @param row is the row number of current move
    @param col is the column number of current move
    @return true is valid move, else false
    */
    bool checkValidMove(int row, int col);
};