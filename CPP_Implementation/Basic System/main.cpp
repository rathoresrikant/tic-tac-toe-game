#include "TicTacToe.h"
#define CLS() cout<<"\033[2J\033[1;1H";

int main()
{
    TicTacToe t;
    int choice;
    char more = 'y';
    do
    {
        cout << "Choose 0(Head) or 1(Tail) : \n";
        cin >> choice;
        if(t.toss(choice))
        {
            cout << "You have won the toss : \n";
        }
        else
        {
            cout << "You have lost the toss : \n";
        }
        t.play();
        cout <<"Want to play again ? (y/n) ";
        cin >> more;

    }while(more == 'y');
    return 0;
}