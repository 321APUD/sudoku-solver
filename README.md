# sudoku-solver
c++ console application that solves sudokus. It reads puzzles from file and have an option to write the answears to a file.

# How to use

Program takes 1-2 arguments. First is a path to file with usolved sudokus and the second is optional path to file where the answears will be written.
Syntax:
```bash
sudoku-solver.exe <input-file> [<output-file>]
```
input-file format:
  1. sudokus are only lines that star with a number.
  2. each row is written in one line where empty cells are zeros.\n
ex: \n
003020600\n
900305001\n
001806400\n
008102900\n
700000008\n
006708200\n
002609500\n
800203009n\
005010300n\
more examples in sudokus.txt file.
