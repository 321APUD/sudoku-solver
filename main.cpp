#include <iostream>
#include "sudoku.h"

int main(int argc, char** argv) {
    sudoku s;
    switch (argc) {
        case 3:
            if( !s.changeOutFile(argv[2]) ){
                cout << "wrong second (out) argument" << endl;
                return 1;
            }
        case 2:
            if(!s.changeSourceFile(argv[1])){
                cout << "wrong first (in) argument" << endl;
                return 1;
            }
            break;
        default:
            cout << "wrong argument number" << endl;
            return 1;
    }
    cout << "solving ..." << endl;
    s.solveWholeFile();
    cout << endl << "solving finished" << endl;
    return 0;
}
