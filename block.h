//
// Created by igo-j on 31.03.2023.
//
#ifndef SUDOKU_BLOCK_H
#define SUDOKU_BLOCK_H
#include "cell.h"
class block {
    cell *cells[3][3];
public:
    block();
    bool hasDuplicate(cell *c);
    cell* &operator()(int i, int j);
    friend class sudoku;
};


#endif //SUDOKU_BLOCK_H
