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
  2. each row is written in one line where empty cells are zeros.<br />
ex: <br />
003020600<br />
900305001<br />
001806400<br />
008102900<br />
700000008<br />
006708200<br />
002609500<br />
800203009<br />
005010300<br />
more examples in sudokus.txt file.
