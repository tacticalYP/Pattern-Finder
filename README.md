# PATTERN FINDER #

# Description
* Pattern finder finds the pattern (in matrix form) given by user in big and complex matrix (considered as motif).
* It provides the positions of required pattern in complex/big matrix(motif) in (i,j) format where i->index of row and j->index of column.
* It also shows where is the pattern in given motif.

# How to Run
1. A GCC C compiler with header files "stdio.h","stdbool.h","windows.h" and Source Code (b23cs1051.c) are required for running the code.
2. Compile the code using C compiler ( you can use this command -> gcc PatternFinder.c -o PatternFinder )
3. Run the executable file ( you can use this command -> ./PatternFinder )

# Instructions
1. Input matrices of size : mxn (m,n>0) with elements in range 1-9.If you enter element <0 or >9 quality of final result will reduce.
2. Only pattern matrix can contain 0 element. 
3. 1-9 numbers represent tiles of different colors and 0 represents empty tile (this means 0 can be considered as any number in motif ).
4. Always, dimensions of motif should be greater than pattern matrix.
5. Use a compiler which supports initial for loop declarations (e.g. for(int i=0, ...)).
6. It is prefered that window in which you are running the code (e.g. Terminal) should be of black/dark background.

# Input and Output
* This program first shows necessary instructions then takes inputs for size of pattern matrix, elements in pattern matrix, size of motif, elements in motif.
* After that it shows entered pattern, motif then total number and positions of pattern occurrences.

# Improvement Areas
* This program can be improved by reducing its complexity and by adding a feature so that it will give better output for 2 or more digit elements.
