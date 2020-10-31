# SudokuX-solver-Z3

## Problem Definition
- Sudoku-X has a 9×9 grid which consists
of nine 3×3 subgrids. Each cell can be assigned with one integer
between one and nine such that each of the nine integers must
appear exactly once at every row, every column and every subgrid.
In addition, Sudoku-X requires that the nine cells of each diagonal
of the 9×9 grid (i.e., one from top-left to bottom-right and one from
top-right to bottom-left) must contain all nine integers.

- An input of Sudoku-X consists of nine lines each of which has nine
values separated by one or multiple whitespaces. A value can be
one of the nine integers (from ‘1’ to ‘9’) representing preassigned
values and ‘?’ indicating an unassigned cell. The following is an
input text for the puzzle instance of Figure 1:

------------------------------------------

? 3 ? 8 4 ? ? ? ?
? ? ? 9 ? ? ? ? ?
? ? 5 ? ? ? ? ? ?
2 5 ? ? ? 7 4 8 ?
? ? 1 ? ? ? ? 3 ?
? 7 3 ? ? ? ? ? 1
? 4 ? ? ? ? ? ? ?
? ? 8 6 ? ? 9 ? ?
9 ? ? ? ? ? ? ? ?

------------------------------------------


## Linux server cmd keys to know 
- clear = clear screen
- ls = load screen (files in server)
- vim  = edit file
- rm = delete file

-------- Once inside vim file--------
- i = insert to edit
- paste = right click once
- If wanting to exit file 
    press esc -> type :wq
- :wq = quit file
- gg = cursor goes to top of file
- dG = delete whole code
- dd = delete one line

--------- When multiple files with main src code ------------

type for codes wanting to run 

- gcc minesweeper.c intset.c
- make
- ./a.out

--- for wanting to send results to seperate formula file---
- ./a.out > formula
- vim formula

./test 


# Running the Program
Open the linux terminal and upload the following .c code and input txt file and Makefile by using vim.

- vim input.txt
- vim sudokuX.c

(optional way => copy and paste the .c code into the linux terminal)
- vim sudokuX.c 
- press I and copy and paste the code (paste by right click)
- press esc and type :wq to quit file

compile the code by 
- gcc sudokuX.c

To make a executable file
type
- make

Once executable file is made
type
- ./a.out

Once program is running following text will show up on the terminal
- Enter file name: 

Type in the input file text
- input.txt

The results will be stored in output.txt which can be seen through
- vim output.txt

The Z3 formula will be stored in formula file 
- vim formula
