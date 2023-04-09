//
// Created by igo-j on 31.03.2023.
//

#include "cell.h"

short cell::getVal() const {
    return val;
}

cell::cell(): val(0), given(false){}

cell::cell(char ch): val( (short)(ch - '0') ), given(true) {}

ostream &operator<<(ostream &out, const cell &c) {
    return out << c.val;
}

cell &cell::operator=(int n) {
    if(!given){
        val = (short)n;
    }
    return *this;
}

cell &cell::operator=(char ch) {
    val = (short)(ch - '0');
    return *this;
}

cell cell::operator++(int) {
    cell old = *this;
    val++;
    return old;
}
