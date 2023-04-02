#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;
 string s , s1;
//function of display of gaming board

void display_board(){
    
    // LAYOUT of the GAME
    cout<<"       |     |     "<<endl;
    cout<<"    "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" "<<endl;
    cout<<"  _____|_____|_____"<<endl;
    cout<<"       |     |     "<<endl;
    cout<<"    "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" "<<endl;
    cout<<"  _____|_____|_____"<<endl;
    cout<<"       |     |     "<<endl;
    cout<<"    "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" "<<endl;
    cout<<"       |     |     "<<endl;
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<< s <<" - [X]  turn : ";
    }
    else if(turn == 'O'){
       cout<< s1 <<" - [O]  turn : "  ;
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another!!nnkjj";
        player_turn();
    }
    /* Ends */
    
}

//Game status function

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++){
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
         return false;
    }
    }
   //Diagonal checking
 if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
         return false;
    }
    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++){ 
        for(int j=0; j<3; j++){
        if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;
    }
    }
   //Checking the if game already draw
    draw = true;
    return false;
}

// Main function program

int main()
{
    cout<<"<-------- T I C K -- T A C -- T O E -- G A M E ----------->"<<endl;
    cout<<"<-------- FOR 2 PLAYERS ------------>"<<endl;
    // Taking player name input by user
    cout<<"   Enter player 1 Name : ";
    cin>>s;
     cout<<"   Enter player 2 Name : ";
    cin>>s1;
    cout<< s <<" - [X]  " << s1 << " - [O]"<<endl;
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
         display_board();
        cout<<"Congratulations! " << s1 <<"  with 'O' has won the game";
    }
    else if(turn == 'O' && draw == false){
         display_board();
        cout<<"Congratulations! " << s<<"  with 'X' has won the game";
    }
    else{
         display_board();
    cout<<"<--- GAME DRAW!!!  --->"<<endl;
    }
} 
