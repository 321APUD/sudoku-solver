//
// Created by igo-j on 31.03.2023.
//

#ifndef SUDOKU_LINE_H
#define SUDOKU_LINE_H
#include "cell.h"

class line {
    cell* cells[9];
public:
    line();
    bool hasDuplicate(cell *c);
    cell* &operator[](int i);
    friend class sudoku;
};


#endif //SUDOKU_LINE_H
