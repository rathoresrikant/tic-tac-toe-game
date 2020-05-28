#include <bits/stdc++.h>
using namespace std;

#define SIZE 3

class TicTacToe
{
    private :
    const int rows = SIZE;
    const int cols = SIZE;
    vector <vector<char>> board;
    vector <int> checkRows, checkCols;
    int diag, secDiag;
    bool turn;
    int x, y;

    bool playPlayer();

    bool playSystem();

    bool checkValidMove(int r, int c);

    bool checkWinner(int r, int c);

    void printWinner(bool turn);

    pair<int,int> getGoodMove(int sign);
    
    public:
    TicTacToe()
    {
        board.resize(rows, vector <char> (cols, '-'));
    }

    bool toss(int choice);

    void initialize();

    void printBoard();

    void play();
};