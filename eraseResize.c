#include <stdio.h>
#include <stdlib.h>
#include "eraseResize.h"

void erase(char*** board, int enteredRow, int enteredCol, int row, int col){
	/* This function erases a point on the board, which sets it back to '*'.
	@board: pointer to the board as we will change an element on the board to '*'
	@enteredRow: the row number of what we want to erase
	@enteredCol: the column number of what we want to erase
	@row: the rows of the board currently
	@col: the columns of the board currently
	@returns: nothing as it is a void type
	@modifies: board
	*/
	(*board)[row - enteredRow - 1][enteredCol] = '*';
}


char** resizeBoard(char** board, int r, int c, int* rows, int* cols){	
	/* This function resizes a board into a smaller or larger size. It creates a new 2d array and copies the old 2d array into the new one.
	@board: the current board that we will need to resize
	@r: the number of rows to resize the board to
	@c: the number of columns to resize the board to
	@rows: the number of rows in the original board
	@cols: the number of columns in the original board
	@modifies: rows will be set to r, which is the resized board number of rows and cols will be set to c, which is the resized board number of columns.
	@returns: the new resized board is returned
	*/
	if(r == *rows && c == *cols){ //no resize needed
		*rows = r;
		*cols = c;
		return board;
	}
	
	char** resized = (char**)calloc(r, sizeof(char*));
	for(int i = 0; i < r; i++){
		resized[i] = (char*)calloc(c, sizeof(char));
		for(int j = 0; j < c; j++){
			resized[i][j] = '*';
		}
	}
	if(r > *rows){ //resize to a larger row
		for(int i = r - 1; i >= r - *rows; i--){
			for(int j = 0; j < *cols; j++){
				resized[i][j] = board[i - (r - *rows)][j];
			}
		}
		*rows = r;
		*cols = c;
		return resized;
	}else if(c > *cols){ //resize to a larger column
		for(int i = r - 1; i >= 0; i--){
			for(int j = 0; j < *cols; j++){
				resized[i][j] = board[i + (*rows - r)][j];
			}
		}
		*rows = r;
		*cols = c;
		return resized;
	}else{ //for smaller resizing
		int index = r - 1;
		for(int i = *rows - 1; i > *rows - r - 1; i--){
			for(int j = 0; j < c; j++){
				resized[index][j] = board[i][j];
			}
			index--;
		}
		*rows = r;
		*cols = c;
		return resized;
	}
}