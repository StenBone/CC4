//
// Created by sten_bone on 11/28/19.
//

#ifndef CC4_BOARD_H
#define CC4_BOARD_H

#include <cstddef>

class Board {

    int rows = 2, cols = 2;
    const char EMPTY_CELL = '_';
    char** board;
public:
    Board() : board(new char*[rows]) {
        for(int i = 0; i < rows; ++i)
            board[i] = new char[cols];


        adr: -> adr: -> adr:char
        * -> * -> char
    };
    ~Board();
};

#endif //CC4_BOARD_H
