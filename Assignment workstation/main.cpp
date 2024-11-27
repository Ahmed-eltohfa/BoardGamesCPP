#include <iostream>
#include "BoardGame_Classes.h"
#include "Classes/PyramidTicTacToe/PyramicTicTacToe.h"
#include "Classes/PyramidTicTacToe/PyramicTicTacToe.cpp"
#include "Classes/FourInRow/FourInRow.h"
#include "Classes/FourInRow/FourInRow.cpp"
#include "Classes/FiveXFive/FiveXFive.h"
#include "Classes/FiveXFive/FiveXFive.cpp"

using namespace std;
int main()
{
    cout << "hello\n";
    PyramidBoard<char> board;
    PyramidRandPlayer<char> p1('X');
    cout << p1.getsymbol() << "\n";
    board.display_board();
    return 0;
}