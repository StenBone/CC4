//Ben Stone, started 08 Nov 2019
//lazy coding convention. as few keystrokes as possible. little caps as possible. '-' seperating variable names.
#include <iostream>

using namespace std;

const int BOARD_ROWS = 6, BOARD_COLS = 7;

int main() {
    cout << "Console Connect 4 START" << endl;
    char board[BOARD_ROWS][BOARD_COLS] = {};

    board[0][5] = 'A';

    cout << board[0][5] << endl;

    for(int row = 0; row < BOARD_ROWS; row++){
        for(int col = 0; col < BOARD_COLS; col++){
            board[row][col] = '_';
        }
    }

    for(int row = 0; row < BOARD_ROWS; row++){
        for(int col = 0; col < BOARD_COLS; col++){
            cout << (char)board[row][col] + " ";
        }
        cout << endl;
    }
}
