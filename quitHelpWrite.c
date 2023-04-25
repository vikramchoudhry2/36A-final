#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "quitHelpWrite.h"



void quit(char*** board, int r, int c){
	/* This is the quit function which exits the program when called after freeing the memory associated with the board we used. It then sets board to null.  
	@board: this is a pointer to the board that we have to free all the memory for.
	@r: the current number of rows that the board has
	@c: the current number of columns that the board has 
	@returns: nothing as it as void type 
	@modifies: board
	*/
	for(int i = 0; i < r; i++){
			free((*board)[i]);
	}
	free(*board);
	*board = NULL;
	exit(0);
}

int slope(int start_row, int start_column, int end_row, int end_column){
	/* This function gets two coordinate pairs and returns the slope between them.
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the x coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@returns: the slope as an integer
	*/
  int slope = (end_column - start_column)/(end_row - start_row); //slope formula
  return slope;
}

bool isFilled(char*** board, int r, int c){
	/* This function checks if a certain element on the board is filled or empty. It returns true if the spot is filled, false if empty.
	@board: this is a pointer to the board and we will use it to check a certain element in the board
	@r: the row number of the selected point
	@c: the column number of the selected point
	@returns: true if the element at the specificed row and column number is filled
	*/
  if((*board)[r][c] != '*'){
    return true;
  }
  return false;
}

void print_help(){
	/* This function prints out all of the help commands when the user enters 'h'. It helps the user know what is valid input and what is not. 
	@returns: nothing as it is a void type and there are no parameters. 
	 */
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

void vertical(char*** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
	/* This function is called when the user wants to write a vertical line and fills the line with the correct character which is |, unless there is intersection with a non | character then it becomes +.
	@board: this is a pointer to board and we will modify board to the correct character for a vertical line.
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the y coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@rows: the number of rows of the current board
	@cols: the number of columns of the current board
	@modifies: board
	@returns: nothing as it is a void type */
  for(int i = rows - start_row - 1; i >= rows - end_row - 1; i--){ //start from the bottom left of the board 
      if(isFilled(board, i, start_column) && (*board)[i][start_column] == '|'){ 
        (*board)[i][start_column] = '|';
      }
      else if(isFilled(board, i, start_column) && (*board)[i][start_column] != '|'){ //if there is intersection
        (*board)[i][start_column] = '+';
      }
      else{
        (*board)[i][start_column] = '|';
    }
  }
}

  
void horizontal(char*** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
		/* This function is called when the user wants to write a horizontal line and fills the line with the correct character which is -, unless there is intersection with a non - character then it becomes +.
		@board: this is a pointer to board and we will modify board to the correct character for a horizontal line.
		@start_row: this is the x coordinate of the first coordinate pair
		@start_column: this is the y coordinate of the first coordinate pair
		@end_row: this is the y coordinate of the last coordinate pair
		@end_column: this is the y coordinate of the last coordinate pair
		@rows: the number of rows of the current board
		@cols: the number of columns of the current board
		@modifies: board
		@returns: nothing as it is a void type */
		for(int j = start_column; j <= end_column; j++){
			if(isFilled(board, rows - start_row - 1, j) && (*board)[rows - start_row - 1][j] == '-'){
				(*board)[rows - start_row - 1][j] = '-';
			}else if(isFilled(board, rows - start_row - 1, j) && (*board)[rows - start_row - 1][j] != '-'){ // if there is intersection
				(*board)[rows - start_row - 1][j] = '+';
			}else{
				(*board)[rows - start_row - 1][j] = '-';
			}
		}
}

	
	
void onePoint(char*** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
	/* This function is called when the user enters only one point to write and it will be a '-' character if there is no intersection, otherwise it will be a '+'
	@board: this is a pointer to board and we will modify board to the correct character for a vertical line.
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the y coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@rows: the number of rows of the current board
	@cols: the number of columns of the current board
	@modifies: board
	@returns: nothing as it is a void type */
	if(isFilled(board, rows - start_row - 1, start_column)){ //if the element is filled then make it a +
		(*board)[rows - start_row - 1][start_column] = '+';
	}else{
		(*board)[rows - start_row - 1][start_column] = '-';
	}
}	
	


void right_diagonal(char*** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
	/* This function is called when the user wants to write a right diagonal line and fills the line with the correct character which is /, unless there is intersection with a non / character then it becomes +.
	@board: this is a pointer to board and we will modify board to the correct character for a vertical line.
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the y coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@rows: the number of rows of the current board
	@cols: the number of columns of the current board
	@modifies: board
	@returns: nothing as it is a void type */
	int i = rows - start_row - 1; //start from the bottom left of the board
	int j = start_column;
	while(i >= rows - end_row - 1 && j <= end_column){
			if(isFilled(board, i, j) && (*board)[i][j] == '/'){
				(*board)[i][j] = '/';
				i--;
				j++;
			}else if(isFilled(board, i, j) && (*board)[i][j] != '/'){
				(*board)[i][j] = '+';
				i--;
				j++;
			}else{
				(*board)[i][j] = '/';
				i--;
				j++;
			}
	}
}

void left_diagonal(char*** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
	/* This function is called when the user wants to write a left diagonal line and fills the line with the correct character which is \, unless there is intersection with a non \ character then it becomes +.
	@board: this is a pointer to board and we will modify board to the correct character for a vertical line.
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the y coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@rows: the number of rows of the current board
	@cols: the number of columns of the current board
	@modifies: board
	@returns: nothing as it is a void type */
	int i = rows - start_row - 1;
	int j = start_column;
	while(i <= rows - end_row - 1 && j <= end_column){
			if(isFilled(board, i, j) && (*board)[i][j] == '\\'){
				(*board)[i][j] = '\\';
				i++;
				j++;
			}else if(isFilled(board, i, j) && (*board)[i][j] != '\\'){
				(*board)[i][j] = '+';
				i++;
				j++;
			}else{
				(*board)[i][j] = '\\';
				i++;
				j++;
			}
	}

}
void typeOfLine(char** board, int start_row, int start_column, int end_row, int end_column, int rows, int cols){
	/* This function is called when the user wants to write, and we have to decide what type of line the user inputted. If the start row = end row and start column = end column then it is one point. 
	If the start column = end column it is a vertical line, and if start row = start column it is a horizontal line. if the slope equals -1 it is a left diagonal line, and if the slope equals 1 it is a right diagonal line.
	@board: this is the board and we will use it to call one of the above functions
	@start_row: this is the x coordinate of the first coordinate pair
	@start_column: this is the y coordinate of the first coordinate pair
	@end_row: this is the y coordinate of the last coordinate pair
	@end_column: this is the y coordinate of the last coordinate pair
	@rows: the number of rows of the current board
	@cols: the number of columns of the current board
	@returns: nothing as it is a void type */
	if(start_row == end_row && start_column == end_column){
		onePoint(&board, start_row, start_column, end_row, end_column, rows, cols);
	}else if(start_row == end_row){
		if(start_column > end_column){ //flip parameters so order doesn't matter
			horizontal(&board, start_row, end_column, end_row, start_column, rows, cols);
		}else{
			horizontal(&board, start_row, start_column, end_row, end_column, rows, cols);
		}	
	}else if(start_column == end_column){
		if(start_row > end_row){ //flip parameters so order doesn't matter
			vertical(&board, end_row, start_column, start_row, end_column, rows, cols);
		}else{
			vertical(&board, start_row, start_column, end_row, end_column, rows, cols);
		}
	}else if(slope(start_row, start_column, end_row, end_column) == -1){
		if(end_row > start_row && start_column > end_column){ //flip parameters so order doesn't matter
			left_diagonal(&board, end_row, end_column, start_row, start_column, rows, cols);
		}else{
			left_diagonal(&board, start_row, start_column, end_row, end_column, rows, cols);
		}
	}else if(slope(start_row, start_column, end_row, end_column) == 1){
		if(start_row < end_row && start_column < end_column){ //flip parameters so order doesn't matter
			right_diagonal(&board, start_row, start_column, end_row, end_column, rows, cols);
		}else{
			right_diagonal(&board, end_row, end_column, start_row, start_column, rows, cols);
		}
	}else{
		printf("Improper draw command.\n");
	}
}