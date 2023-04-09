//
// Created by igo-j on 31.03.2023.
//

#include "block.h"


block::block(): cells{nullptr} {}

cell* &block::operator()(int i, int j) {
    return cells[i][j];
}

bool block::hasDuplicate(cell *c) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (cells[i][j] != c && cells[i][j]->getVal() == c->getVal()){
                return true;
            }
        }
    }
    return false;
}
