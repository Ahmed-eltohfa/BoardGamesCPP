#include "PyramicTicTacToe.h"
#include <cctype>
// -------------- Board --------------- //

template <typename T>
PyramidBoard<T>::PyramidBoard()
{
    this->rows = 3;
    this->columns = 5;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            if ((i == 0 && j != 2) || (i == 1 && j != 1 && j != 2 && j != 3))
            {
                this->board[i][j] = '-';
            }
            else
            {
                this->board[i][j] = ' ';
            }
        }
    }
}

template <typename T>
bool PyramidBoard<T>::update_board(int x, int y, T symbol)
{
    return false;
}

template <typename T>
void PyramidBoard<T>::display_board()
{
    T **temp = this->board;
    for (int i = 0; i < this->rows; i++)
    {
        cout << "| ";
        for (int j = 0; j < this->columns; j++)
        {
            cout << " " << (char)toupper(temp[i][j]) << " ";
        }
        cout << " |\n";
    }
}

template <typename T>
bool PyramidBoard<T>::is_win()
{
    T **temp = this->board;

    return false;
}

template <typename T>
bool PyramidBoard<T>::is_draw()
{
    return false;
}

template <typename T>
bool PyramidBoard<T>::game_is_over()
{
    return false;
}

// -------------- Player --------------- //

template <typename T>
PyramidPlayer<T>::PyramidPlayer(string name, T symbol) : Player<T>(name, symbol)
{
}

template <typename T>
void PyramidPlayer<T>::getmove(int &x, int &y)
{
}

// -------------- Rand Player --------------- //

template <typename T>
PyramidRandPlayer<T>::PyramidRandPlayer(T symbol) : RandomPlayer<T>(symbol)
{
}

template <typename T>
void PyramidRandPlayer<T>::getmove(int &x, int &y)
{
}
