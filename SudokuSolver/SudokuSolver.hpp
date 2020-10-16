/* ********************************************************
        Header file for the Sudoku Solving program
   ********************************************************
*/ 

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void showBoard(int board[81]);
void bruteForce(int orig[81], int board[81], bool lastCheck);
bool checkBoard(int board[81]);
bool isDone(int board[81]);
