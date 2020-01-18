## Algortihm for this project: ##

step 1: Check file if contains valid tetros as requirement.

step 2: If step 1 is true then determine how many tetros it contains. Return the number of tetrominos

step 3: Depending on number of tetros allocates the memory

step 4: Create 4*4 matrices and fill them up using dots '.'

step 5: Place the tetrminos into our created matrix and converts '#' to letters. Here we also checked the valid tetro based on connections.

step 7: Removed the row from matrix which row basically we don't need. '....'

step 8: clean_single_column() function Removed single dot '.' which we don't need.

step 9: Depending on number of tetros, generate row in order to place all of the tetros, number_of_tetro*4

step 10: Depending on min_size generating row with dots.

step 11: We used Backtracking algorithm in order to solve the tetrominos within minimum possible square.

## RUN ##

1. make
2. ./fillit test.txt
