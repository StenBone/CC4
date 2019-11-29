//
// Created by sten_bone on 11/28/19.
//

#include "Board.h"

Board::Board() {
    for(int row = 0; row < BOARD_ROWS; row++){
        for(int col = 0; col < BOARD_COLS; col++){
            board[row][col] = EMPTY_CELL;
        }
    }
}

Board::~Board() {

}
