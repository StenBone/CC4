//Ben Stone, started 08 Nov 2019
//lazy coding convention. as few keystrokes as possible. little caps as possible. '-' seperating variable names.
#include <iostream>
#include "Board.h"

using namespace std;

const char PLAYER1_CHIP = 'X';
const char PLAYER2_CHIP = 'O';

int main() {
    cout << "Connect 4 START" << endl;

    // What's left
    // Get user input on where to add chip
    // Loop asking for players turns
    // Player1 input
    // Player2 input
    // Win check
    // Turn check
    // End message
    // banner over the top of the game board
    // click on the col to add chip
    // annimated chip falling
    // console refresh

    //Check inputs for valid move

    // Player makes their move
    // board updates
    // check for win condition
    // todo check for places where game_over is set
    // todo go back and forth with players

    /**
    bool debug_checks = false;
    // Horizontal
    Board* horizontal_test = new Board();
    horizontal_test->addChip(PLAYER1_CHIP, 0);
    horizontal_test->addChip(PLAYER1_CHIP, 1);
    horizontal_test->addChip(PLAYER1_CHIP, 2);
    horizontal_test->addChip(PLAYER1_CHIP, 3);
    debug_checks = horizontal_test->isWinner(PLAYER1_CHIP);
    cout << "Horizontal Check: " << debug_checks << endl;


    // Vertical
    Board* vertical_test = new Board();
    vertical_test->addChip(PLAYER1_CHIP, 3);
    vertical_test->addChip(PLAYER1_CHIP, 3);
    vertical_test->addChip(PLAYER1_CHIP, 3);
    vertical_test->addChip(PLAYER1_CHIP, 3);
    debug_checks = vertical_test->isWinner(PLAYER1_CHIP);
    cout << "Vertical Check: " << debug_checks << endl;

    // Diagonal ^>
    Board* pos_pos_diag_test = new Board();

    pos_pos_diag_test->addChip(PLAYER1_CHIP, 0);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 1);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 2);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 3);


    pos_pos_diag_test->addChip(PLAYER1_CHIP, 1);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 2);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 3);

    pos_pos_diag_test->addChip(PLAYER1_CHIP, 2);
    pos_pos_diag_test->addChip(PLAYER2_CHIP, 3);


    pos_pos_diag_test->addChip(PLAYER1_CHIP, 3);
    debug_checks = pos_pos_diag_test->isWinner(PLAYER1_CHIP);
    cout << "Diagonal Pos Pos Check: " << debug_checks << endl;

    // Diagonal ^<
    Board* pos_neg_diag_test = new Board();

    pos_neg_diag_test->addChip(PLAYER2_CHIP, 0);
    pos_neg_diag_test->addChip(PLAYER2_CHIP, 1);
    pos_neg_diag_test->addChip(PLAYER2_CHIP, 2);
    pos_neg_diag_test->addChip(PLAYER1_CHIP, 3);

    pos_neg_diag_test->addChip(PLAYER2_CHIP, 0);
    pos_neg_diag_test->addChip(PLAYER2_CHIP, 1);
    pos_neg_diag_test->addChip(PLAYER1_CHIP, 2);

    pos_neg_diag_test->addChip(PLAYER2_CHIP, 0);
    pos_neg_diag_test->addChip(PLAYER1_CHIP, 1);

    pos_neg_diag_test->addChip(PLAYER1_CHIP, 0);
    debug_checks = pos_pos_diag_test->isWinner(PLAYER1_CHIP);
    cout << "Diagonal Pos Pos Check: " << debug_checks << endl;
    */

    Board* c4_board = new Board();
    bool game_over = false;
    int player = 1;
    char player_symbol = '\0';
    int move = -1;
    do {
        c4_board->drawBoard();

        cout << "Player " << player << ", make your move. Col " << 1 << " - " << c4_board->BOARD_COLS << endl;
        cin >> move; //todo verify input is number

        move--; // minus 1 because addChip is 0 based

        // todo react to when addChip is false
        // choose symbol based on player
        player == 1 ? player_symbol = PLAYER1_CHIP : player_symbol = PLAYER2_CHIP;
        c4_board->addChip(player_symbol, move);

        if(c4_board->isWinner(player_symbol))
        {
            cout << "Player " << player << " Won!" << endl;
            game_over = true;
        }

        // swap player
        player == 1 ? player = 2 : player = 1;

    } while (!game_over && !c4_board->isFull());

    cout << "GAME OVER" << endl;

    delete c4_board;
    return 0;
}
