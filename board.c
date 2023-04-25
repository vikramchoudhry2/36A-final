#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char** makeBoard(int r, int c){
	/* This function creates a board of characters and sets each element to the asterisk character which is the blankSpace for this project
	@r: this is a parameter of type int for the rows that the user inputs for the size of the canvas
	@c: this is a parameter of type int for the columns the user inputs for the size of the canvas.
	returns: a char** board of size r x c
	*/
	char** board = (char**) calloc(r, sizeof(char*));
  for(int i = 0; i < r; i++){
    board[i] = (char*)calloc(c, sizeof(char));
    for(int j = 0; j < c; j++){
      board[i][j] = '*'; //set each element in the board to '*'
    }
  }
  return board;
}

void boardSetup(int rows, int cols, char*** paintBoard){
	/* This function setups the board by calling the makeBoard function and setting the pointer to board created in main to be initialized to a board of size rows x cols.
	@rows: This parameter takes in the number of rows the user inputs for the size of the canvas.
	@cols: This parameter takes in the number of columns that the user inputs for the size of the canvas. 
	@paintBoard: this parameter is a pointer to the board that we will dereference to initialize the first canvas.
	@returns: void type so nothing is returned
	@modifies: paintBoard is modified
	*/
	*paintBoard = makeBoard(rows, cols);
}

void printBoard(char** board, int r, int c){
	/* This function will print out the board in the correct format with corresponding row and column numbers for each element. 
	@board: This is the board that we want to print out, so we take it in as a parameter and use it to print every element.
	@r: this is the number of rows that the board has and we need to print out
	@c: this is the number of columns that the board has and we need to print out 
	@returns: nothing as it is a void type */
  for(int i = 0; i < r; i++){
    printf("%d ", r - i - 1); //print the row numbers
    for(int j = 0; j < c ; j++){
      printf("%c ", board[i][j]); //print the board
    }
    printf("\n");
  }
  printf("  ");
  //print the column numbers
  for(int k = 0; k < c; k++){
    printf("%d ",k);
  }
	printf("\n"); 
}