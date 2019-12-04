//Ben Stone, started 08 Nov 2019
//lazy coding convention. as few keystrokes as possible. little caps as possible. '-' seperating variable names.
#include <iostream>
#include "Board.h"

using namespace std;

const char PLAYER1_CHIP = 'X';
const char PLAYER2_CHIP = 'O';

int main() {
    cout << "Console Connect 4 START" << endl;

    Board* c4_board = new Board();

    //What's left
    //Get user input on where to add chip
    //Loop asking for players turns
    //Player1 input
    //Player2 input
    //Win check
    //Turn check
    //End message

    //Check inputs for valid move

    // Player makes their move
    // board updates
    // check for win condition
    // todo check for places where game_over is set
    // todo go back and forth with players
    bool game_over = false;
    int player = 1;
    int move = -1;
    do {
        c4_board->drawBoard();

        cout << "Player 1, make your move. Col " << 1 << " - " << c4_board->BOARD_COLS << endl;
        cin >> move; //todo verify input is number

        move--; // minus 1 to reveal index

        // todo react to when addChip is false
        player == 1 ? c4_board->addChip(PLAYER1_CHIP, move) : c4_board->addChip(PLAYER2_CHIP, move);

        player == 1 ? player = 2 : player = 1;


    } while (!game_over && !c4_board->isFull());

    delete c4_board;
    return 0;
}
