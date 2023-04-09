//
// Created by igo-j on 31.03.2023.
//

#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H
#include <iostream>
using std::ostream;

class cell {
    short val;
    bool given;
public:
    cell();
    cell& operator=(int n);
    cell& operator=(char ch);
    cell operator++(int);
    explicit cell(char ch);
    short getVal() const;
    friend ostream& operator<<(ostream& out, const cell& c);
    friend class sudoku;
};


#endif //SUDOKU_CELL_H
