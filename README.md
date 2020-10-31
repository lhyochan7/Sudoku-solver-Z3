# SudokuX-solver-Z3

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
