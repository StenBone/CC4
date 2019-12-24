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

void Board::drawBoard() {
    // todo print numbers of cols
    // Print top to bottom, so print the last row with the last index in the array first
    for (int row = BOARD_ROWS - 1; row >= 0; row--) {
        std::cout << row << " ";
        for (int col = 0; col < BOARD_COLS; col++) {
            std::cout << (char) board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Adds Chip to board
 * @param playerSymbol
 * @param col 0 to BOARD_COLS - 1
 * @return is move valid?
 */
bool Board::addChip(const char playerSymbol, const int col) {

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

/**
 * Search for a line(sequence of 4 repeating items) @ start coord
 * Notes: Rows ^/v up/down, Cols <-> left-right
 * @param start_row
 * @param start_col
 * @param delta_direction_row
 * @param delta_direction_col
 * @param line_symbol
 * @return true if line exist
 */
bool Board::FoundLine2D(unsigned int start_row, unsigned int start_col, int delta_direction_row, int delta_direction_col, const char line_symbol)
{
    int chip_count = 0;

    // for (init; continue condition; delta)
    for (int row = start_row, col = start_col; (row >= 0 && row < BOARD_ROWS) && (col >= 0 && col < BOARD_COLS); row += delta_direction_row, col += delta_direction_col)
    {
        if (board[row][col] == line_symbol) {
            chip_count++; //count chip

            if (chip_count >= 4) {
                return true;
            }
        }
        else
        {
            chip_count = 0;
        }
    }
    return false;
}

bool Board::isWinner(const char playerSymbol)
{
    // todo optimize idea: if there is less than 4 spaces to count and chipCount is 0 quit, couldn't win

    // check horizontal -
    // check each row if there are 4 cols with the same symbol
    for (int row = 0; row < BOARD_ROWS; row++) {
        if (FoundLine2D(row, 0, 0, 1, playerSymbol))
        {
            return true;
        }
    }

    // check vertical |
    // check each column  for 4 chips of the same symbol
    for (int col = 0; col < BOARD_COLS; col++) {
        if (FoundLine2D(0, col, 1, 0, playerSymbol))
        {
            return true;
        }
    }

    // todo check diagonal / ^>
    // start along the side where col is 0
    for (int row = 0; row < BOARD_ROWS; row++) {
        if (FoundLine2D(row, 0, 1, 1, playerSymbol))
        {
            return true;
        }
    }
    // start along bottom where row is 0
    // can skip one since it was already looked at
    for (int col = 1; col < BOARD_COLS; col++)
    {
        if (FoundLine2D(0, col, 1, 1, playerSymbol)) {
            return true;
        }
    }

    // todo check diagonal \ ^<
    // start along the side where col is 0
    for (int row = 0; row < BOARD_ROWS; row++) {
        if (FoundLine2D(row, 0, 1, -1, playerSymbol))
        {
            return true;
        }
    }
    // start along bottom where row is 0
    // can skip one since it was already looked at
    for (int col = BOARD_COLS - 1; col >= 0; col--)
    {
        if (FoundLine2D(0, col, 1, -1, playerSymbol)) {
            return true;
        }
    }

    // todo what parts of this check can I put into functions to reduce it's size and make it less error prone,
    // what is the minimum number of lines you can get this code down to using reusability
    // todo recursive solution that looks at next neighbor keeping chipCount and direction of next chip
    return false;
}
