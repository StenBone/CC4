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

    void drawBoard();
    bool addChip(const char playerSymbol, const int col);
    bool isFull();
    bool isWinner(const char playerSymbol);

private:
    const char EMPTY_CELL = '_';
    int chip_count = 0;
    char board[BOARD_ROWS][BOARD_COLS] = {};

    bool
    FoundLine2D(unsigned int start_row, unsigned int start_col, unsigned int delta_direction_row,
                unsigned int delta_direction_col,
                const char line_symbol);

    bool FoundLine2D(unsigned int start_row, unsigned int start_col, int delta_direction_row, int delta_direction_col,
                     const char line_symbol);

};

#endif //CC4_BOARD_H
