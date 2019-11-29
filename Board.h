//
// Created by sten_bone on 11/28/19.
//

#ifndef CC4_BOARD_H
#define CC4_BOARD_H

#include <cstddef>

class Board {
public:
    Board();
    ~Board();

    static const int BOARD_COLS = 7;
    static const int BOARD_ROWS = 6;

    void DrawBoard();
    bool AddChip(const char playerSymbol, const int col);
    bool isFull();

private:
    const char EMPTY_CELL = '_';
    int chip_count = 0;
    char board[BOARD_ROWS][BOARD_COLS] = {};
};

#endif //CC4_BOARD_H
