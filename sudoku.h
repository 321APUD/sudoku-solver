//
// Created by igo-j on 31.03.2023.
//
#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include "block.h"
#include "line.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class sudoku {
    cell *wholeSudoku[9][9];
    block blocks[3][3];
    line rows[9];
    line cols[9];

    ifstream in;
    ofstream out;

    void del();
    bool isSolved();
    bool checkOne(int i, int j);
    bool solveOne(int i);
public:
    sudoku();
    explicit sudoku(int tab[9][9]);
    ~sudoku();

    bool changeSourceFile(char *txt);
    bool changeOutFile(char *txt);

    bool solve();
    void fill(int tab[9][9]);
    void restart();

    bool loadFromFile();
    void solveWholeFile();

    friend ostream& operator<<(ostream& out, const sudoku& s);
};


#endif //SUDOKU_SUDOKU_H
