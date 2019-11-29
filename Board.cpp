//
// Created by sten_bone on 11/28/19.
//

#include "Board.h"
#include <iostream>

Board::Board() {
    for (int row = 0; row < BOARD_ROWS; row++) {
        for (int col = 0; col < BOARD_COLS; col++) {
            board[row][col] = EMPTY_CELL;
        }
    }
}

Board::~Board() {

}

void Board::DrawBoard() {
    // todo print numbers of cols
    // Print top to bottom, so print the last row with the last index in the array first
    for (int row = BOARD_ROWS - 1; row >= 0; row--) {
        std::cout << row;
        for (int col = 0; col < BOARD_COLS; col++) {
            std::cout << (char) board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Adds Chip to board
 * @param playerSymbol
 * @param col
 * @return is move valid?
 */
bool Board::AddChip(const char playerSymbol, const int col) {

    // 0 <= col < rows and top element not already full
    if (col >= 0 && col < BOARD_COLS &&
        board[BOARD_ROWS - 1][col] == EMPTY_CELL &&
        !isFull())
    {
        // go down the rows in the same column from bottom to top until you find an empty cell
        // check bottom row up
        for (int row = 0; row < BOARD_ROWS; row++) {
            if (board[row][col] == EMPTY_CELL) {
                board[row][col] = playerSymbol;
                chip_count++;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

bool Board::isFull() {
    return chip_count >= (BOARD_ROWS * BOARD_COLS);
}
