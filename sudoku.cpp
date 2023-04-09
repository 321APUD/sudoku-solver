//
// Created by igo-j on 31.03.2023.
//

#include "sudoku.h"

ostream &operator<<(ostream &out, const sudoku &s) {
    for(int i = 0; i < 9; i++){
        if(i > 0 && i % 3 == 0){
            out << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++ ){
            if (j > 0 && j % 3 == 0)
                out << "| ";
            out << *s.wholeSudoku[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}

sudoku::sudoku(): wholeSudoku{nullptr} {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            wholeSudoku[i][j] = new (std::nothrow) cell;
            if (!wholeSudoku[i][j]){
                del();
                cout << "memory problem"<<endl;
                exit(1);
            }
            rows[i][j] = wholeSudoku[i][j];
            cols[j][i] = wholeSudoku[i][j];
            blocks[i/3][j/3](i%3,j%3) = wholeSudoku[i][j];
        }
    }
}

void sudoku::del() {
    for(int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (wholeSudoku[i][j])
                delete wholeSudoku[i][j];
}

void sudoku::fill(int tab[9][9]) {
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            *wholeSudoku[i][j] = tab[i][j];
            wholeSudoku[i][j]->given = tab[i][j] != 0 ;
        }
    }
}

sudoku::~sudoku() { del(); }

bool sudoku::solve() {
    if( isSolved() )
        return true;
    for ( int i = 0; i < 81; i++){
        if(!wholeSudoku[i/9][i%9]->given)
            if(!solveOne(i)) return false;
    }
    return true;
}

bool sudoku::isSolved() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if(!checkOne(i,j)) return false;
        }
    }
    return true;
}

bool sudoku::solveOne(int i) {
    if (i < 0) return false;
    if(wholeSudoku[i/9][i%9]->given){
        if(!solveOne(i - 1)) return false;
        return true;
    }
    do {
        do {
            (*wholeSudoku[i / 9][i % 9])++;
        } while (!checkOne(i / 9, i % 9) && wholeSudoku[i / 9][i % 9]->getVal() <= 9);
        if (wholeSudoku[i / 9][i % 9]->getVal() == 10) {
            wholeSudoku[i / 9][i % 9]->val = 0;
            if(!solveOne(i - 1)) return false;
        }
    }while(wholeSudoku[i/9][i%9]->getVal() == 0);
    return true;
}

bool sudoku::checkOne(int i, int j) {
    if ( wholeSudoku[i][j]->getVal() < 1 || wholeSudoku[i][j]->getVal() > 9 ) return false;
    if ( blocks[i/3][j/3].hasDuplicate(wholeSudoku[i][j]) ) return false;
    if ( rows[i].hasDuplicate(wholeSudoku[i][j]) ) return false;
    if ( cols[j].hasDuplicate(wholeSudoku[i][j]) ) return false;
    return true;
}

sudoku::sudoku(int tab[9][9]): sudoku() {
    fill(tab);
}

void sudoku::solveWholeFile() {
    string line;
    while(loadFromFile()){
        if( solve() )
            ( out.is_open() ? out : cout ) << *this << endl;
        else {
            restart();
            (out.is_open() ? out : cout) << "unsolvable :" << endl << *this << endl;
        }
    }
}

bool sudoku::changeSourceFile(char *txt) {
    in.open(txt);
    if(in.is_open())
        return true;
    return false;
}

bool sudoku::changeOutFile(char *txt) {
    out.open(txt);
    if(out.is_open())
        return true;
    return false;
}

bool sudoku::loadFromFile() {
    string line;
    if(!in.is_open()) return false;
    if(!in.good()) return false;
    do {
        getline(in, line);
        if (line.front() == '\n') return false;
    }while(line.front() < '0' || line.front() > '9');
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            wholeSudoku[i][j]->val  = (short)(line[j] - '0');
            wholeSudoku[i][j]->given = line[j] != '0';
        }
        getline(in, line);
    }
    return true;
}

void sudoku::restart() {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if(!wholeSudoku[i][j]->given)
                *wholeSudoku[i][j] = 0;
        }
    }
}
