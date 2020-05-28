/**
    main.cpp
    Purpose: The driver function to create an instance of TicTacToe Game and play it.

    @author Srikant Singh
    @version 1.1 17/04/2020 
*/

#include "TicTacToe.h"
#define CLS() cout<<"\033[2J\033[1;1H";

int main() 
{
    int n, turn, rowNum, colNum;
    char more = 'n';
    cout <<"Enter the board size : \n";
    cin >> n;
    TicTacToe t(n);
    do
    {
        turn = 0;
        bool tie = true;
        t.initialize();
        while(turn < n*n)
        {
            CLS()  
            if(turn%2 == 0)
            {
                cout <<"First Player's turn : \n";
            }
            else
            {
                cout <<"Second Player's turn : \n";
            }
            t.printBoard();
            cout<<"Enter the position (row, col) :\n";
            bool valid = false;
            while(!valid)
            {
                cin >> rowNum >> colNum;
                valid = t.checkValidMove(rowNum, colNum);
                if(!valid)
                {
                cout <<"Please enter a valid move\n";
                }
            }
            bool status = t.play(turn%2, rowNum, colNum);
            if(status)
            {
                cout<<"Congrats you have won !\n";
                tie = false;
                break;
            }
            turn++;
        }
        if(tie)
        {
            cout <<"It is a tie.\n";
        }
        cout<<"Want to play again (y/n) ?\n";
        cin >> more;
    }while(more == 'y');
    return 0;
}