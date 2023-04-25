#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "saveandload.h"



void save(char*** board, char* destination, int r, int c){
		/* This function writes to a file, and stores the board into a txt file. It can be accessed later in the program if the users calls load.
		@board: a pointer to the board that we will dereference to write each element to the txt file
		@destination: the filename the user enters
		@r: the number of current rows in the board
		@c: the number of current columns in the board
		@returns: nothing as it is a void type */
  	FILE* dest = fopen(destination, "w"); //open a file with the user entered name
		fprintf(dest, "%d %d \n", r, c); //print the current rows and columns so we can read it when we call load
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c ; j++){
        fprintf(dest, "%c ", (*board)[i][j]); //print each character to the file
      }
      fprintf(dest, "\n");
    }
    fprintf(dest, "  ");
  	fprintf(dest, "\n");
    fclose(dest);		
}

void load(char*** board, char* filename, int* rows, int* cols){
		/* This function loads the txt file and sets each element of the board to what was in the txt file. We want to make the current board represent what was saved.
		@board: a pointer to the board that we will dereference to set each element to the corresponding element in the txt file
		@filename: the filename we want to read from
		@rows: the number of rows that we currently have in the board (pointer)
		@cols: the number of columns that we currently have in the board (pointer)
		@modifies: rows and cols will be set to the rows and columns that were read from the txt file, which is the size of the saved board, board is also modified to be the saved board
		@returns: */
    FILE *dest = NULL;
    // Open file
    dest = fopen(filename, "r");
    if (dest == NULL)
    {
        printf("Improper load command or file could not be opened.\n");
    }
		int savedRows;
		int savedCols;
		fscanf(dest, "%d %d", &savedRows, &savedCols); //save the new dimensions into these two variables
		(*board) = (char**)malloc(*rows * sizeof(char*));
		for(int x = 0; x < *rows; x++){
			(*board)[x] = (char*)malloc(*cols * sizeof(char)); //size the board to the original size
		}
		(*board) = (char**)realloc((*board), savedRows * sizeof(char*));
		for(int x = 0; x < savedRows; x++){
			(*board)[x] = (char*)realloc((*board)[x], savedCols * sizeof(char)); //reallocate the size of the board to be the size of the saved txt file board
		}
		char ch;
		fscanf(dest, "%c", &ch);
		while(ch != '\n'){
			fscanf(dest, "%c", &ch);
		}
		for(int i = 0; i < savedRows; i++){
			for(int j = 0; j < savedCols; j++){
				fscanf(dest, "%c", &ch);
				while(isspace(ch)){
					fscanf(dest, "%c", &ch);
				}
				(*board)[i][j] = ch; //set each element to what was in the txt file
			}
		}
		*rows = savedRows;
		*cols = savedCols;
    fclose(dest);
}
bool doesFileExist(char* filename){
	/* This function checks if a file exists. If it doesn't false is returned, otherwise true is returned.
	@filename: The filename of the file we want to check
	@returns: a bool based on if the file exists or not */
	FILE* valid = fopen(filename, "r"); //will be null if there is no file
	if(valid == NULL){
		return false;
	}else{
		fclose(valid);
		return true;
	}
}