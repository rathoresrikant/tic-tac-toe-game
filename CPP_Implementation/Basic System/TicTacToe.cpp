#include "TicTacToe.h"

void TicTacToe :: printBoard()
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << board[i][j] <<" ";
        }
        cout << "\n";
    }
}

void TicTacToe :: initialize()
{
    checkRows.resize(rows, 0);
    checkCols.resize(cols, 0);
    diag = 0;
    secDiag = 0;
    x = -1;
    y = -1;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            board[i][j] = '-';
        }
    }
}

bool TicTacToe :: toss(int choice)
{
    srand(time(0));
	int random = rand()%2;
    return turn = (random == choice);
}

void TicTacToe :: play()
{
    initialize();
    bool status = false;

    int empty_cells = rows*cols;
    while(empty_cells--)
    {
        printBoard();
        if(turn)
        {
            cout <<"Its your turn ! \n";
            status = playPlayer();
        }
        else
        {
            cout <<"It is System's turn ! \n";
            status = playSystem();
        }
        if(status)
        {
            printWinner(turn);
            return;
        }
        turn = !turn;
    }
    cout << "It is a tie.";
}

bool TicTacToe :: playPlayer()
{
    int r, c;
    cout <<"Enter the position (0-indexed):  \n";
    bool valid = false;
    while(!valid)
    {
        cin >> r >> c;            
        valid = checkValidMove(r, c);
        if(!valid)
        {
            cout <<"Please enter a valid move\n";
        }
    }
    board[r][c] = 'x';
    return checkWinner(r, c);
}

bool TicTacToe :: playSystem()
{
    pair<int,int> pos = getGoodMove(-1);
    if(pos == make_pair(-1, -1))
        pos = getGoodMove(1);
    if(pos == make_pair(-1, -1))
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                if(board[i][j] == '-')
                {
                    pos = make_pair(i, j);
                    i = SIZE;
                    j = SIZE;
                }
            }
        }
    }
    board[pos.first][pos.second] = 'o';
    return checkWinner(pos.first, pos.second);
}

bool TicTacToe :: checkValidMove(int r, int c)
{
  return ((r >= 0 && c >= 0 && r < rows  && c < cols) && board[r][c] == '-');
}

bool TicTacToe :: checkWinner(int r, int c)
{
    checkRows[r] += turn ? 1 : -1;
    checkCols[c] += turn ? 1 : -1;
    if(abs(checkRows[r]) == rows || abs(checkCols[c]) == cols)
    {
        return true;
    }
    if(r == c)
    {
        diag += turn ? 1 : -1;
    }
    if(r + c == SIZE -1)
    {
        secDiag += turn ? 1 : -1;
    }
    return (abs(diag) == SIZE || abs(secDiag) == SIZE);
}

void TicTacToe :: printWinner(bool turn)
{
    printBoard();
    if(turn)
        cout <<"Congrats ! You won.\n";
    else
        cout <<"Sorry ! You lost. \n";
}

pair<int,int> TicTacToe :: getGoodMove(int sign)
{
    for(int i=0; i<SIZE; i++)
    {
        if(checkRows[i] == sign*2)
        {
            if(board[i][0] == '-')
                return {i, 0};
            else
            if(board[i][0] == '-')
                return {i, 1};
            else
                return {i, 2};
        }
        if(checkCols[i] == sign*2)
        {
            if(board[0][i] == '-')
                return {0, i};
            else
            if(board[1][i] == '-')
                return {1, i};
            else
                return {2, i};
        }
        if(diag == sign*2)
        {
            if(board[i][i] == '-')
                return {i, i};
        }
        if(secDiag == sign*2)
        {
            if(board[i][2-i] == '-')
                return {1, 2-i};
        }
    }
    return {-1, -1};
}