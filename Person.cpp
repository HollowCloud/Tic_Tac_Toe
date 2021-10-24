#include <iostream>
#include "Person.h"
#include <ctime>


using namespace std;
string gameboard[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int number = 0;




void Person::define_turn()
{
    while(!Tic_Tac_Toe_Master() && !check_duplicates())
    {
        //This is a basically a centre from where all the functions are operating~
        set_numbers();
        assigning_board();
        change_player();
        Lines();
    }
}


bool Person::Tic_Tac_Toe_Master()
{
    bool victory = false;
    //rows
    if((gameboard[0]==gameboard[1]) && (gameboard[1]==gameboard[2]) && gameboard[0] != " ")
    {
        victory = true;
    }
    else if ((gameboard[3] == gameboard[4]) && (gameboard[4] == gameboard[5]) && gameboard[3] != " ")
    {
        victory = true;
    }

    else if ((gameboard[6] == gameboard[7]) && (gameboard[7] == gameboard[8]) && gameboard[6] != " ")
    {
        victory = true;
    }

        //columns

    else if((gameboard[0]==gameboard[3]) && (gameboard[3]==gameboard[6]) && gameboard[0] != " ")
    {
        victory = true;
    }

    else if ((gameboard[1] == gameboard[4]) && (gameboard[4] == gameboard[7]) && gameboard[1] != " ")
    {
        victory = true;
    }

    else if ((gameboard[2] == gameboard[5]) && (gameboard[5] == gameboard[8]) && gameboard[2] != " ")
    {
        victory = true;
    }

        //diagonals

    else if ((gameboard[0]==gameboard[4]) && (gameboard[4]==gameboard[8]) && gameboard[0] != " ")
    {
        victory = true;
    }

    else if ((gameboard[2]==gameboard[4]) && (gameboard[4]==gameboard[6]) && gameboard[2] != " ")
    {
        victory = true;
    }

    return victory;

}

bool Person::check_duplicates()
{
    bool duplicate = true;

    for(int i = 0; i<9; i++)
    {
        if(gameboard[i]==" ")
        {
            duplicate = false;
        }
    }

    return duplicate;
}




void Person::Lines()
{
    cout<<  "     |     |      \n";
    cout << "  " << gameboard[0] << "  |  " << gameboard[1] << "  |  " << gameboard[2] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << gameboard[3] << "  |  " << gameboard[4] << "  |  " << gameboard[5] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "  " << gameboard[6] << "  |  " << gameboard[7] << "  |  " << gameboard[8] << "\n";
    cout << "     |     |      \n";
    cout << "\n";

}



void Person::set_numbers()
{
    cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
    while(!(cin>>number))
    {
        cout<<"Please enter a valid number between (1-9)"<<endl;
        cin.clear();  //flushing the buffer
        cin.ignore();
    }
    cout<<endl;

    while (gameboard[number -1] != " "){
        cout<<"Oops, that position is already filled\nTry again\n";
        cout << "Player " << player << "'s Turn (Enter 1-9): ";
        cin>>number;
        cout<<"\n";


    }

}

//This implementation was for "Bot" or 2nd Player with a random feature, but I could not implement it properly...

//void Person::set_position_bot()
//{
//    srand(time(0));
//    int n = rand() % 10;
//    cout << n << endl;
//    cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
//    while(!(n))
//    {
//        cout<<"Please enter a valid number between (1-9)"<<endl;
//        cin.clear();  //flushing the buffer
//        cin.ignore();
//    }
//    cout<<endl;
//
//    while (board[position -1] != " "){
//        cout<<"Oops, that position is already filled\nTry again\n";
//        cout << "Player " << player << "'s Turn (Enter 1-9): ";
//        cin>>position;
//        cout<<"\n";
//
//
//    }
//
//}


void Person::assigning_board()
{

    if (player % 2 == 1){
        gameboard[number - 1] = "X";   //1-9        0-8
    }
    else
    {
        gameboard[number - 1] = "O";
    }
}


void Person::change_player() {
    if (player == 1){
        player++;
    }
    else{
        player--;
    }
}




void Person::exit()
{
    if(Tic_Tac_Toe_Master())
    {
        bool victory = false;
        //rows
        if((gameboard[0] == "X" && gameboard[1] == "X") && (gameboard[1] == "X" && gameboard[2] == "X") && gameboard[0] != " ")
        {
            victory = true;
        }
        else if ((gameboard[3] == "X" && gameboard[4] == "X") && (gameboard[4] == "X" && gameboard[5] == "X") && gameboard[3] != " ")
        {
            victory = true;
        }

        else if ((gameboard[6] == "X"  &&  gameboard[7] == "X") && (gameboard[7] == "X" && gameboard[8] ==  "X") && gameboard[6] != " ")
        {
            victory = true;
        }

            //columns

        else if((gameboard[0] == "X"  && gameboard[3] == "X") && (gameboard[3] == "X" && gameboard[6] == "X") && gameboard[0] != " ")
        {
            victory = true;
        }

        else if ((gameboard[1] == "X" &&  gameboard[4] == "X") && (gameboard[4] == "X" && gameboard[7] == "X") && gameboard[1] != " ")
        {
            victory = true;
        }

        else if ((gameboard[2] == "X" &&  gameboard[5] == "X") && (gameboard[5] == "X" && gameboard[8] == "X") && gameboard[2] != " ")
        {
            victory = true;
        }

            //diagonals

        else if ((gameboard[0] == "X"  && gameboard[4] == "X") && (gameboard[4] == "X" && gameboard[8] == "X") && gameboard[0] != " ")
        {
            victory = true;
        }

        else if ((gameboard[2] == "X" && gameboard[4] == "X") && (gameboard[4] == "X" && gameboard[6] == "X") && gameboard[2] != " ")
        {
            victory = true;
        }
        cout << " YOU HAVE WON!!!!!" << endl;

    }
    //This is for O :
    else if(Tic_Tac_Toe_Master())
    {
        bool victory = false;
        //rows
        if((gameboard[0] == "O" && gameboard[1] == "O") && (gameboard[1] == "O" && gameboard[2] == "O") && gameboard[0] != " ")
        {
            victory = true;
        }
        else if ((gameboard[3] == "O" && gameboard[4] == "O") && (gameboard[4] == "O" && gameboard[5] == "O") && gameboard[3] != " ")
        {
            victory = true;
        }

        else if ((gameboard[6] == "O"  &&  gameboard[7] == "O") && (gameboard[7] == "O" && gameboard[8] ==  "O") && gameboard[6] != " ")
        {
            victory = true;
        }

            //columns

        else if((gameboard[0] == "O"  && gameboard[3] == "O") && (gameboard[3] == "O" && gameboard[6] == "O") && gameboard[0] != " ")
        {
            victory = true;
        }

        else if ((gameboard[1] == "O" &&  gameboard[4] == "O") && (gameboard[4] == "O" && gameboard[7] == "O") && gameboard[1] != " ")
        {
            victory = true;
        }

        else if ((gameboard[2] == "O" &&  gameboard[5] == "O") && (gameboard[5] == "O" && gameboard[8] == "O") && gameboard[2] != " ")
        {
            victory = true;
        }

            //diagonals

        else if ((gameboard[0] == "O"  && gameboard[4] == "O") && (gameboard[4] == "O" && gameboard[8] == "O") && gameboard[0] != " ")
        {
            victory = true;
        }

        else if ((gameboard[2] == "O" && gameboard[4] == "O") && (gameboard[4] == "O" && gameboard[6] == "O") && gameboard[2] != " ")
        {
            victory = true;
        }
        cout << " PLAYER 2 HAS WON!!!!!" << endl;

    }

    else if(check_duplicates())
    {
        cout<<"There is a tie!"<<endl;
    }
}
