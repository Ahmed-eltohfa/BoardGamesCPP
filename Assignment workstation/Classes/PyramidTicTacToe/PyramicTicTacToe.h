#ifndef PYRAMICTICTACTOE_H
#define PYRAMICTICTACTOE_H

#include "../../BoardGame_Classes.h"

#pragma once

template <typename T>
class PyramidBoard : public Board<T>
{
public:
    PyramidBoard();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template <typename T>
class PyramidPlayer : public Player<T>
{
public:
    PyramidPlayer() {};
    PyramidPlayer(string n, T symbol);

    void getmove(int &x, int &y);
};

template <typename T>
class PyramidRandPlayer : public RandomPlayer<T>
{
public:
    PyramidRandPlayer() {};
    PyramidRandPlayer(T symbol);

    void getmove(int &x, int &y);
};

#endif