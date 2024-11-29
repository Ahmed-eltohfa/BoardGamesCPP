#ifndef MISERE_H
#define MISERE_H

#include "../../BoardGame_Classes.h"

#pragma once

bool winRRev=false;

template <typename T>
class Misere_board : public Board<T>
{
public:
    Misere_board();
    bool last = false;
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool reverse();
    bool is_draw();
    bool game_is_over();
    ~Misere_board();

private:
};

template <typename T>
class Misere_Player : public Player<T>
{
public:
    Misere_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class Misere_Random_Player : public RandomPlayer<T>
{
public:
    Misere_Random_Player(T symbol);
    void getmove(int &x, int &y);
};

#endif