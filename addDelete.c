#include <stdio.h>
#include <stdlib.h>
#include "addDelete.h"

char** addedRow(char** board, int rowToAdd, int* rows, int cols){
	/* This function adds a row to the board, and shifts everything above that row up one row. This function copies everything to the new add array.
	@board: this is the board that we will use as reference to copy into add
	@rowToAdd: this is the row number we have to add
	@rows: the current number of rows in the board
	@cols: the current number of columns in the board
	@modifies: rows is set to the rows + 1 because we added a row
	@returns: the new char** array with the added row
	*/
	char** add = (char**) calloc (*rows + 1, sizeof(char*));
	for(int i = 0; i < *rows + 1; i++){
    add[i] = (char*)calloc(cols, sizeof(char));
    for(int j = 0; j < cols; j++){
      add[i][j] = '*'; //set each element in the board to '*'
    }
  }
	rowToAdd = *rows - rowToAdd;
	if(rowToAdd == *rows){ //if we want to add a row to the top, just copy the original board
		for(int i = 0; i < *rows; i++){
			for(int j = 0; j < cols; j++){
				add[i][j] = board[i][j]; 
			}
		}
		*rows = *rows + 1;
		return add;
	}
	
	for(int i = 0; i < *rows ; i++){ 
		for(int j = 0; j < cols; j++){
			if(i >= rowToAdd){
				add[i + 1][j] = board[i][j]; //for every row above and equal the row to add we have to move it up by one
			}else{
				add[i][j] = board[i][j];
			}
		}
	}
	*rows = *rows + 1;
	return add;
	
}
char** addedCol(char** board, int colToAdd, int rows, int* cols){
	/* This function adds a column to the board, and shifts everything to the right of the column by one column. This function copies everything to the new add array.
	@board: this is the board that we will use as reference to copy into add
	@colToAdd: this is the column number we have to add
	@rows: the current number of rows in the board
	@cols: the current number of columns in the board
	@modifies: cols is set to the cols + 1 because we added a column
	@returns: the new char** array with the added column
	*/
	char** add = (char**)calloc(rows, sizeof(char*));
	for(int i = 0; i < rows; i++){
		add[i] = (char*)calloc(*cols + 1, sizeof(char));
		for(int j = 0; j < *cols + 1; j++){
			add[i][j] = '*'; //set each element in the board to '*'
		}
	}
	if(colToAdd == *cols){ //to add a new column to the very right
		for(int i = 0; i < *cols; i++){
			for(int j = 0; j < rows; j++){
				add[j][i] = board[j][i];
			}
		}
		*cols = *cols + 1;
		return add;
	}
	for(int i = 0; i < *cols; i++){
		for(int j = 0; j < rows; j++){
			if(i >= colToAdd){
				add[j][i + 1] = board[j][i]; //for every column to the right and equal to colToAdd we have to shift the elements one to the right.
			}else{
				add[j][i] = board[j][i];
			}
		}
	}
	*cols = *cols + 1;
	return add;
}

char** deleteRow(char** board, int rowToRemove, int* rows, int cols){
	/* This function deletes a row in the board, and shifts everything down by 1. This function copies everything to the new delete array.
	@board: this is the board that we will use as reference to copy into delete
	@rowToRemove: this is the row number we have to remove
	@rows: the current number of rows in the board
	@cols: the current number of columns in the board
	@modifies: rows is set to the rows - 1 because we deleted a row
	@returns: the new char** array with the removed row
	*/
		char** delete = (char**)calloc(*rows - 1, sizeof(char*));
		for(int i = 0; i < *rows - 1; i++){
			delete[i] = (char*)calloc(cols, sizeof(char));
			for(int j = 0; j < cols; j++){
				delete[i][j] = '*'; //set each element in the board to '*'
			}
		}
		rowToRemove = *rows - rowToRemove - 1;
		if(rowToRemove == *rows - 1){ //remove the top most row
			for(int i = 0; i < *rows - 1; i++){
				for(int j = 0; j < cols; j++){
					delete[i][j] = board[i][j];
				}
			}
			*rows = *rows - 1;
			return delete;
		}
		for(int i = 0; i < *rows - 1; i++){
			for(int j = 0; j < cols; j++){
				if(i >= rowToRemove){
					delete[i][j] = board[i + 1][j]; //everything above the rowToRemove must be shifted down
				}else{
					delete[i][j] = board[i][j];
				}
			}
		}		
		*rows = *rows - 1;
		return delete;
}

char** deleteCol(char** board, int colToRemove, int rows, int* cols){
	/* This function deletes a column in the board, and shifts everything to the left from that column that we removed. This function copies everything to the new delete array.
	@board: this is the board that we will use as reference to copy into delete
	@colToRemove: this is the column number to remove
	@rows: the current number of rows in the board
	@cols: the current number of columns in the board
	@modifies: cols is set to the cols - 1 because we deleted a column
	@returns: the new char** array with the removed column
	*/
	char** delete = (char**) calloc(rows, sizeof(char*));
	for(int i = 0; i < rows; i++){
		delete[i] = (char*) calloc(*cols - 1, sizeof(char));
		for(int j = 0; j < *cols - 1; j++){
			delete[i][j] = '*';
		}
	}
	
	if(colToRemove == *cols - 1){ //if we want to remove the right most column
		for(int i = 0; i < *cols - 1; i++){
			for(int j = 0; j < rows; j++){
				delete[j][i] = board[j][i];
			}
		}
		*cols = *cols - 1;
		return delete;
	}
	
	for(int i = 0; i < *cols - 1; i++){
		for(int j = 0; j < rows; j++){
			if(i >= colToRemove){
				delete[j][i] = board[j][i+1]; //everything to the right of colToRemove must be shifted left by 1
			}else{
				delete[j][i] = board[j][i];
			}
		}
	}
	*cols = *cols - 1;
	return delete;
}

