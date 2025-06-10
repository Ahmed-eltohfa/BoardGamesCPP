#include "../../BoardGame_Classes.h"
#include <bits/stdc++.h>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

template <typename T>
class FIVEXFIVE_AI_Player : public Player<T>
{
public:
    FIVEXFIVE_AI_Player(string name, T symbol);

    void getmove(int &x, int &y) override;

private:
    pair<int, int> getBestMove();
};

// ======================== //
template <typename T>
FIVEXFIVE_AI_Player<T>::FIVEXFIVE_AI_Player(string name, T symbol) : Player<T>(symbol)
{
    // this->name = " (AI Player)";
    srand(static_cast<unsigned int>(time(0)));
}

// Method to get the best move for the player
template <typename T>
void FIVEXFIVE_AI_Player<T>::getmove(int &x, int &y)
{
    pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}

template <typename T>
pair<int, int> FIVEXFIVE_AI_Player<T>::getBestMove()
{
    pair<int, int> bestMove = {-1, -1};
    T opSymbol = this->symbol == 'X' ? 'O' : 'X';
    if (opSymbol == 'X')
    {
        AIisX = false;
    }
    // Check if the AI can win or block a loss (first priority)
    map<pair<int, int>, int> mp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int difBefore = dif1;
            if (this->boardPtr->update_board(i, j, this->symbol))
            {
                mp[{i, j}] = dif1 - difBefore;
                this->boardPtr->update_board(i, j, ' ');
            }
        }
    }

    // Block the opponent from winning
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int dif2Before = -dif1;
            if (this->boardPtr->update_board(i, j, opSymbol))
            {
                if (-dif1 > dif2Before)
                {
                    int res = -dif1 - dif2Before;
                    mp[{i, j}] += res;
                }
                this->boardPtr->update_board(i, j, ' ');
            }
        }
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << i << " " << j << " -->" << mp[{i, j}] << "\n";
    //     }
    // }

    int high_score = 0;
    int lasti = -1, lastj = -1;
    for (auto c : mp)
    {
        if (high_score < c.second)
        {
            lasti = c.first.first;
            lastj = c.first.second;
            high_score = c.second;
        }
    }

    if (lasti != -1 && lastj != -1)
    {
        return {lasti, lastj};
    }

    int x = rand() % 5;
    int y = rand() % 5;

    return {x, y};
}
