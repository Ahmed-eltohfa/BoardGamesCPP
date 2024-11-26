#include "PyramicTicTacToe.h"

// -------------- Board --------------- //

template <typename T>
PyramidBoard<T>::PyramidBoard()
{
    this->rows = 3;
    this->columns = 5;
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
bool PyramidBoard<T>::update_board(int x, int y, T symbol)
{
    return false;
}

template <typename T>
void PyramidBoard<T>::display_board()
{
}

template <typename T>
bool PyramidBoard<T>::is_win()
{
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
PyramidPlayer<T>::PyramidPlayer(string n, T symbol)
{
}

template <typename T>
void PyramidPlayer<T>::getmove(int &x, int &y)
{
}

// -------------- Rand Player --------------- //

template <typename T>
PyramidRandPlayer<T>::PyramidRandPlayer(T symbol)
{
}

template <typename T>
void PyramidRandPlayer<T>::getmove(int &x, int &y)
{
}
