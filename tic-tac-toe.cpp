#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn = 'X';
int ScoreOne = 0;
int ScoreTwo = 0;
bool draw = false;

void display_board()
{
    system("cls");
    cout<<"\t\t\tT I C  -- T A C -- T O E -- G A M E\t\t\t"<<"\tSCORE :\t\t\t"<<endl;
    cout<<"\t\t\t\tFOR 2 PLAYERS\t\t\t\t\t\t"<<"PLAYER - 1 [X] : "<< ScoreOne<<endl;
        cout<<"\t\t\t     Made by Minhajul Islam"<<"\t\t\t\t\tPLAYER - 2 [O] : " << ScoreTwo<<"\n\n\t\t\t";

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t\t\t     |     |     \n";
}

void player_turn()
{
    if(turn == 'X')
    {
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O')
    {
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }

    cin>>choice;

    switch(choice)
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;
        break;
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;
    default:
        cout<<"\tInvalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {

        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {

        cout<<"\tBox already filled!\n\tPlease choose another!!\n"<<endl;
        player_turn();
    }
    display_board();
}

bool gameover()
{

    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;


    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

//Program Main Method

int main()
{
    int play;

playGame :
    {

    while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false)
    {
        cout<<"\n\n\tCongratulations! Player 2 [0] has won the game";
        ScoreTwo++;
    }
    else if(turn == 'O' && draw == false)
    {
        cout<<"\n\n\tCongratulations! Player 1 [X] has won the game";
        ScoreOne++;

    }
    else
        cout<<"\n\n\tGAME DRAW!!!\n\n";

    }
    char c = '1';

    cout<<"\n\n\tDo you Want to play again !!!!" <<endl;
    cout<<"\tPress 1 for Yes or press 2 for No : ";
    cin>>play;
    if(play == 1)
    {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = c;
                c++;
             }
        }
        turn = 'X';
        goto playGame;
    }
    else {
        display_board();
    }


    return 0;
}
