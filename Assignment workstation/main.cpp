#include <iostream>
#include "BoardGame_Classes.h"
#include "Classes/PyramidTicTacToe/PyramicTicTacToe.h"
#include "Classes/PyramidTicTacToe/PyramicTicTacToe.cpp"
#include "Classes/PyramidTicTacToe/PyramidAi.h"
#include "Classes/FourInRow/FourInRow.h"
#include "Classes/FourInRow/FourInRow.cpp"
#include "Classes/FiveXFive/FiveXFive.h"
#include "Classes/FiveXFive/FiveXFive.cpp"
#include "Classes/WordsTicTacToe/WordsTicTacToe.h"
#include "Classes/WordsTicTacToe/WordsTicTacToe.cpp"
#include "Classes/WordsTicTacToe/WordsAi.h"
#include "Classes/NumericalTicTacToe/NumericalTicTacToe.h"
#include "Classes/NumericalTicTacToe/NumericalTicTacToe.cpp"
#include "Classes/sus/sus.h"
#include "Classes/sus/sus.cpp"
#include "Classes/UltimateX_O/UltimateX_O.h"
#include "Classes/UltimateX_O/UltimateX_O.cpp"

#include "Classes/Misere_tic_tac_toe/misere.h"
#include "Classes/Misere_tic_tac_toe/misere.cpp"
#include "Classes/Misere_tic_tac_toe/misereAI.h"
#include <algorithm>

void pyramidGameMainRun()
{
    int choice;
    Player<char> *players[2];
    PyramidBoard<char> *B = new PyramidBoard<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Pyramid Tic Tac Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new PyramidPlayer<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new PyramidRandPlayer<char>('X');
        break;
    case 3:
        players[0] = new PyramidAi<char>('X');
        players[0]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new PyramidPlayer<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new PyramidRandPlayer<char>('O');
        break;
    case 3:
        players[1] = new PyramidAi<char>('O');
        players[1]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> pyramidGame(B, players);
    pyramidGame.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void WordsGameMainRun()
{
    int choice;
    Player<char> *players[2];
    WordsBoard<char> *B = new WordsBoard<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Words Tic Tac Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new WordsPlayer<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new WordsRandPlayer<char>('X');
        break;
    case 3:
        players[0] = new WordsAi<char>('X');
        players[0]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new WordsPlayer<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new WordsRandPlayer<char>('O');
        break;
    case 3:
        players[1] = new WordsAi<char>('O');
        players[1]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> wordsGame(B, players);
    // cout << "output " << B->is_draw();
    // cout << "output " << B->game_is_over();
    wordsGame.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
};

void FourInRowGame()
{

    int choice;
    string player1Name, player2Name;
    Player<char> *players[2];
    Four_In_Row_Board<char> *B = new Four_In_Row_Board<char>();

    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 1
        cout << "Enter Player X name: ";
        cin >> player1Name;
        players[0] = new Four_In_Row_Player<char>(player1Name, 'X');
    }
    else if (choice == 2)
    {
        players[0] = new Four_In_Row_Random_Player<char>('X');
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        players[1] = new Four_In_Row_Player<char>(player1Name, 'O');
    }
    else if (choice == 2)
    {
        players[1] = new Four_In_Row_Random_Player<char>('O');
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    GameManager<char> FourInRowGameManager(B, players);
    FourInRowGameManager.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
};

void FiveXFive()
{
    int choice;
    Player<char> *players[2];
    FiveXFive_board<char> *B = new FiveXFive_board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI FiveXFive Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new FiveXFive_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new FiveXFive_Random_Player<char>('X');
        break;
    // case 3:
    //     players[0] = new X_O_MinMax_Player<char>('X');
    //     players[0]->setBoard(B);
    //     break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new FiveXFive_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new FiveXFive_Random_Player<char>('O');
        break;
    // case 3:
    //     players[1] = new X_O_MinMax_Player<char>('O');
    //     players[1]->setBoard(B);
    //     break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> FiveXFive(B, players);
    // cout << "output " << B->is_draw();
    // cout << "output " << B->game_is_over();
    FiveXFive.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void misere()
{
    int choice;
    Player<char> *players[2];
    Misere_board<char> *B = new Misere_board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Misere tic tac toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> player2Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    cout << "Enter Player 2 name: ";
    cin >> playerXName;
    switch (choice)
    {
    case 1:
        players[0] = new Misere_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new Misere_Random_Player<char>(playerXName, 'X');
        break;
    case 3:
        players[0] = new MISERE_MinMax_Player<char>(playerXName, 'X');
        players[0]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new Misere_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new Misere_Random_Player<char>(player2Name, 'O');
        break;
    case 3:
        players[1] = new MISERE_MinMax_Player<char>(player2Name, 'O');
        players[1]->setBoard(B);
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }
    // Create the game manager and run the game
    GameManager<char> misereGame(B, players);
    // cout << "output " << B->is_draw();
    // cout << "output " << B->game_is_over();
    misereGame.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void NumericalTicTacToeGame()
{
    int choice;
    string player1Name, player2Name;
    Player<int> *players[2];
    Numerical_Tic_Tac_Toe_Board<int> *B = new Numerical_Tic_Tac_Toe_Board<int>();

    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 1
        cout << "Enter Player X name: ";
        cin >> player1Name;
        players[0] = new Numerical_Tic_Tac_Toe_Player<int>(player1Name, 1);
    }
    else if (choice == 2)
    {
        players[0] = new Numerical_Tic_Tac_Toe_Random_Player<int>(1);
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        players[1] = new Numerical_Tic_Tac_Toe_Player<int>(player2Name, 1);
    }
    else if (choice == 2)
    {
        players[1] = new Numerical_Tic_Tac_Toe_Random_Player<int>(1);
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    GameManager<int> NumericalTicTacToeGameManager(B, players);
    NumericalTicTacToeGameManager.run();
}

void Sus()
{

    int choice;
    string player1Name, player2Name;
    Player<char> *players[2];
    Sus_Board<char> *B = new Sus_Board<char>();
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 1
        cout << "Enter Player X name: ";
        cin >> player1Name;
        B->name1 = player1Name;
        players[0] = new Sus_Player<char>("", 'S');
    }
    else if (choice == 2)
    {
        players[0] = new Sus_Random_Player<char>('S');
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    if (choice == 1)
    {
        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        B->name1 = player1Name;
        players[1] = new Sus_Player<char>("", 'U');
    }
    else if (choice == 2)
    {
        players[1] = new Sus_Random_Player<char>('U');
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    GameManager<char> SusGameManager(B, players);
    SusGameManager.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void ultimateX_OGameMainRun()
{
    int choice;
    Player<char> *players[2];
    UltimateX_OBoard<char> *B = new UltimateX_OBoard<char>(true);
    string playerXName, player2Name;

    cout << "Welcome to FCAI Ultimate Tic Tac Toe Game. :)\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new UltimateX_OPlayer<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new UltimateX_ORandPlayer<char>('X');
        break;
    // case 3:
    //     players[0] = new UltimateX_OAi<char>('X');
    //     players[0]->setBoard(B);
    //     break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        return;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new UltimateX_OPlayer<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new UltimateX_ORandPlayer<char>('O');
        break;
    // case 3:
    //     players[1] = new UltimateX_OAi<char>('O');
    //     players[1]->setBoard(B);
    //     break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        return;
    }

    // Create the game manager and run the game
    GameManager<char> pyramidGame(B, players);
    pyramidGame.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

using namespace std;
int main()
{
    ultimateX_OGameMainRun();
    // UltimateX_OBoard<char> *b = new UltimateX_OBoard<char>(true);
    // b->update_board(0, 0, 'X');
    // b->update_board(0, 8, 'o');
    // b->update_board(1, 7, 'o');
    // b->update_board(2, 6, 'o');
    // b->update_board(2, 6, 'o');
    // b->update_board(2, 6, 'o');
    // b->update_board(2, 6, 'o');
    // b->update_board(2, 6, 'o');
    // b->update_board(2, 6, 'o');
    // b->display_board();
    // b->update_board(2, 6, ' ');
    // b->display_board();
    // cout << b.is_win();
    // cout << "tamam bitch\n";
    // WordsBoard<char> b;
    // b.display_board();
    // WordsGameMainRun();
    // cout << "g";
    // int z;
    // cin >> z;
    // WordsBoard<char> *b = new WordsBoard<char>();
    // b->display_board();
    // b->update_board(0, 0, 'x');
    // b->update_board(0, 2, 'x');
    // b->update_board(1, 1, 'o');
    // b->update_board(1, 0, 'o');
    // b->display_board();
    // // b->update_board(1, 1, ' ');
    // // b->display_board();

    // delete b;

    // WordsAi<char> p('a');
    // p.setBoard(b);
    // int x, y;
    // p.getmove(x, y);
    // cout << x << " " << y << " " << p.getsymbol() << "\n";
    return 0;
}