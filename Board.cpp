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

bool Board::FoundLine2D(unsigned int start_x, unsigned int start_y, unsigned int delta_direction_x, unsigned int delta_direction_y, const char line_symbol)
{
    int chip_count = 0;

    // for (init; continue condition; delta)
    for (int x = start_x, y = start_y; (x >= 0 && x < BOARD_ROWS) && (y >= 0 && y < BOARD_COLS); x += delta_direction_x, y += delta_direction_y)
    {
        if (board[x][y] == line_symbol) {
            chip_count++; //count chip

            if (chip_count >= 4) {
                return true;
            }
        }
    }
    return false;
}

bool Board::isWinner(const char playerSymbol) {

    //todo optimize idea: if there is less than 4 spaces to count and chipCount is 0 quit, couldn't win

    int chipCount = 0;

    //check horizontal -
    //check each row if there are 4 cols with the same symbol
    for (int row = 0; row < BOARD_ROWS; row++) {
        for (int col = 0; col < BOARD_COLS; ++col) {
            if (board[row][col] == playerSymbol) {
                chipCount++; //count chip
            }
            else {
                chipCount = 0; //reset count
            }
        }

        if (chipCount >= 4) {
            return true;
        }
        else {
            chipCount = 0; //reset count for new row
        }
    }

    //check vertical |
    //check each column  for 4 chips of the same symbol
    chipCount = 0; //reset count
    for (int col = 0; col < BOARD_COLS; col++) {
        for (int row = 0; row < BOARD_ROWS; ++row) {
            if (board[row][col] == playerSymbol) {
                chipCount++; //count chip
            }
            else {
                chipCount = 0; //reset count
            }
        }

        if (chipCount >= 4) {
            return true;
        }
        else {
            chipCount = 0; //reset count for new row
        }
    }

    //todo check diagonal /
    //center line, can only be as many checks as the smallest dimension
    chipCount = 0;
    int diagonal_length = 0;
    BOARD_ROWS < BOARD_COLS ? diagonal_length = BOARD_ROWS : diagonal_length = BOARD_COLS;
    for (int row_col = 0; row_col < diagonal_length; row_col++) {
        if (board[row_col][row_col] == playerSymbol) {
            chipCount++; //count chip
        }
        else {
            chipCount = 0; //reset count
        }
    }

    if (chipCount >= 4) {
        return true;
    }
    else {
        chipCount = 0; //reset count for new row
    }

    // All Coords where row is 0
    for (int col = 1; col < BOARD_COLS; ++col) {

        //finding the smallest dimension. cols move to the right.
        diagonal_length = 0;
        int cols_remaining = BOARD_COLS - col;
        BOARD_ROWS < cols_remaining ? diagonal_length = BOARD_ROWS : diagonal_length = cols_remaining;

        //start @ board[0][col]
        int r = 0;
        for (int c = col; c < diagonal_length; c++) {
            if (board[r][c] == playerSymbol) {
                chipCount++; //count chip
            }
            else {
                chipCount = 0; //reset count
            }
            r++;
        }

        if (chipCount >= 4) {
            return true;
        }
        else {
            chipCount = 0; //reset count for new row
        }
    }

    // All Coords where col is 0
    //research prefix and postfix at end of for loop. does it change anything? answer: no, doesn't change anything
    for (int row = 1; row < BOARD_ROWS; row++) {

        //finding the smallest dimension. cols move to the right.
        diagonal_length = 0;
        int rows_remaining = BOARD_ROWS - row;
        BOARD_ROWS < rows_remaining ? diagonal_length = BOARD_ROWS : diagonal_length = rows_remaining;

        //start @ board[row][0]
        int c = 0;
        //research if int row = row and row has an outer scope, what happens? Answer: sets it 0. Default initializer
        for (int r = row; r < diagonal_length; r++) {
            if (board[r][c] == playerSymbol) {
                chipCount++; //count chip
            }
            else {
                chipCount = 0; //reset count
            }
            c++;
        }

        if (chipCount >= 4) {
            return true;
        }
        else {
            chipCount = 0; //reset count for new row
        }
    }



    //check diagonal \
    //go up(row++) from bottom row and to the left(col--) from the right
    chipCount = 0;
    diagonal_length = 0;
    BOARD_ROWS < BOARD_COLS ? diagonal_length = BOARD_ROWS : diagonal_length = BOARD_COLS;

    // start at row 0 furthest left column, row++ col--
    // Go along the rows with new row_start positions
    // start at 4 because can't have a match less than a 4
    for (int row_start = 0; row_start < BOARD_ROWS - 4; row_start++) {
        for (int row = row_start, col = BOARD_COLS - 1; row < BOARD_ROWS && col >= 0; row ++, col--) {
            if (board[row][col] == playerSymbol) {
                chipCount++; //count chip

                if (chipCount >= 4) {
                    return true;
                }
            }
            else {
                chipCount = 0; //reset count
            }
        }
        chipCount = 0;
    }

    // Go along the bottom row with new col start positions
    for (int col_start = 4; col_start < BOARD_COLS; col_start++) {
        for (int row = 0, col = col_start; row < BOARD_ROWS && col >= 0; row ++, col--) {
            if (board[row][col] == playerSymbol) {
                chipCount++; //count chip

                if (chipCount >= 4) {
                    return true;
                }
            }
            else {
                chipCount = 0; //reset count
            }
        }
        chipCount = 0;
    }

    //todo what parts of this check can I put into functions to reduce it's size and make it less error prone,
    // what is the minimum number of lines you can get this code down to using reusability
    //todo recursive solution that looks at next neighbor keeping chipCount and direction of next chip
    return false;
}
