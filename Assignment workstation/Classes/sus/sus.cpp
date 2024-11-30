#include "sus.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cctype> // for toupper()


using namespace std;



//////////////////////////////////// start BoardPtr IMPLEMENTATION
template <typename T>
Sus_Board<T>::Sus_Board()
{
    
    this->rows = this->columns = 3;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Sus_Board<T>::update_board(int x, int y, T mark){
    if(this->board[x][y]==0){
        this->board[x][y]=toupper(mark);
        this->n_moves++;
        lastplayer=!lastplayer;
        return true;
    }
    return false;
}

template <typename T>
void Sus_Board<T>::display_board(){
    // Print column numbers at the top
    cout << "   ";
    for (int j = 0; j < this->columns; j++) {
        cout << setw(3) << j << " ";
    }
    cout << "\n";

    // Print the boardptr with horizontal and vertical borders
    for (int i = 0; i < this->rows; i++) {
        // Print the top border of each row
        cout << "   ";
        for (int j = 0; j < this->columns; j++) {
            cout << "----";
        }
        cout << "-\n";

        // Print the row content
        cout << setw(2) << i << " "; // Print row number
        for (int j = 0; j < this->columns; j++) {
            if(this->board[i][j]==0){
                cout << "| " << " "<< " ";
            }else{
                cout << "| " << this->board[i][j] << " ";
            }
            
        }
        cout << "|\n";
    }

    // Print the bottom border
    cout << "   ";
    for (int j = 0; j < this->columns; j++) {
        cout << "----";
    }
    cout << "-\n";
    cout<<endl;

}


template <typename T>
bool Sus_Board<T>::is_win(){
    
    for(int i=0;i<3;i++){
        if( string({this->board[i][0],this->board[i][1],this->board[i][2]}) == "SUS" ||  // check horizontal
            string({this->board[0][i],this->board[1][i],this->board[2][i]}) == "SUS")      //check vertical
        {
            
            if(!this->lastplayer){
                this->counterp1++;
                cout<< "player 1 did "<< this->counterp1 <<" SUS";
            }else{
                this->counterp2++;
                cout<< "player 2 did "<< this->counterp2 <<" SUS";
            }
            
        }
    }   

    if( string({this->board[0][0],this->board[1][1],this->board[2][2]}) == "SUS" || //check diagonal
        string({this->board[0][2],this->board[1][1],this->board[2][0]}) == "SUS")   //check inverse diagonal
    {
        if(!this->lastplayer){
            this->counterp1++;
            cout<< "player 1 did "<< this->counterp1 <<" SUS";
        }else{
            this->counterp2++;
            cout<< "player 2 did "<< this->counterp2 <<" SUS";
        }
        
        
    }
    
    
    if(counterp1>counterp2 && this->n_moves==9)
    {
        cout<< "player 1 wins";
        return true;
    }else if(counterp1>counterp2 && this->n_moves==9)
    {
        cout<< "player 2 wins";
        return true;
    }

    return false;
}

template <typename T>
bool Sus_Board<T>::is_draw(){
    return this->n_moves==9 && counterp1 == counterp2 ;
}

template <typename T>
bool Sus_Board<T>::game_is_over(){
    return is_win() || is_draw();
}
//////////////////////////////////// end BoardPtr IMPLEMENTATION



//////////////////////////////////// start player IMPLEMENTATION
// Constructor for Sus_Player
template <typename T>
Sus_Player<T>::Sus_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Sus_Player<T>::getmove(int &x, int &y){
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;


}
//////////////////////////////////// end player IMPLEMENTATION





//////////////////////////////////// start Random player IMPLEMENTATION
// Constructor for Sus_Random_Player
template <typename T>
Sus_Random_Player<T>::Sus_Random_Player(T symbol) : RandomPlayer<T>(symbol){
    this->name= "Random Computer Player";
}

template <typename T>
void Sus_Random_Player<T>::getmove(int &x, int &y){
    cout<<"yes";
}
//////////////////////////////////// end Random player IMPLEMENTATION