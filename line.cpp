//
// Created by igo-j on 31.03.2023.
//

#include "line.h"

line::line(): cells{nullptr} {}

cell* &line::operator[](int i) {
    return cells[i];
}

bool line::hasDuplicate(cell *c) {
    for (int i = 0; i < 9; i++){
        if(cells[i] != c && cells[i]->getVal() == c->getVal()){
            return true;
        }
    }
    return false;
}
