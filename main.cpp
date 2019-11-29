//Ben Stone, started 08 Nov 2019
//lazy coding convention. as few keystrokes as possible. little caps as possible. '-' seperating variable names.
#include <iostream>

using namespace std;

const int BOARD_ROWS = 6, BOARD_COLS = 7;
const char EMPTY_CELL = '_';
const char PLAYER1_CHIP = 'X';
const char PLAYER2_CHIP = 'O';

void DrawBoard(const char board[BOARD_ROWS][BOARD_COLS]){
    // Print top to bottom, so print the last row with the last index in the array first
    for(int row = BOARD_ROWS - 1; row >= 0; row--){
        cout << row;
        for(int col = 0; col < BOARD_COLS; col++){
            cout << (char)board[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Console Connect 4 START" << endl;
    char board[BOARD_ROWS][BOARD_COLS] = {};

    for(int row = 0; row < BOARD_ROWS; row++){
        for(int col = 0; col < BOARD_COLS; col++){
            board[row][col] = EMPTY_CELL;
        }
    }

    //What's left
    //Get user input on where to add chip
    //Loop asking for players turns
    //Player1 input
    //Player2 input
    //Win check
    //Turn check
    //End message

    //Check inputs for valid move

    int chip_count = 0;

    // Player makes their move
    // board updates
    // check for win condition
    // todo check for places where game_over is set
    // todo go back and forth with players
    bool game_over = false;
    int player = 1;
    do {
        int move = -1;

        //Draw board



        cout << "Player 1, make your move. Col " << 1 << " - " << BOARD_COLS << endl;
        cin >> move; //CHECK

        move--;


        // TODO while(row < BOARD_ROWS -1 and fin!= true
        //go down the rows in the same column from bottom to top until you find an empty cell
        // check bottom row up, 0 ->

        for (int row = 0; row < BOARD_ROWS; row++){
            if(board[row][move] == EMPTY_CELL){
                board[row][move] = PLAYER1_CHIP;
                break;
            }
        }

        //TODO check for when board is full WIP
        if (board[BOARD_ROWS - 1][move] == EMPTY_CELL)
        {

        }

        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
        chip_count++;


    } while(!game_over && chip_count <= (BOARD_ROWS * BOARD_COLS));



}
