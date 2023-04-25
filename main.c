#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "inputValidation.h"
#include "board.h"

/* This program creates a text based game of paint, that allows the user to create a canvas with a size of their choice. There are 9 commands the user can call,
the quit which ends the program, help which prints out all possible commands with their valid input, write which actually draws onto the canvas, add which adds a row/column at the selected row/column,
delete which deletes a row/column at the selected row/column, resize which resizes the board to a size of the user's choosing, erase which removes an element that is drawn on the canvas, save which saves progress, 
and load which loads the saved file so the user can continue their progress. Input needs to be validated for each of the commands and based on the command the corresponding command function will be called. It will keep running
until the users calls the quit command. 

*/ 









int main(int argc, char** argv){
	/* The main initializes the board struct and the 2d array that it contains. It checks if command line input is valid. It also calls the main function which will prompt the user to enter a
	command till they quit. 
	@argc: the total number of command line arguments
	@argv: each command line input, argv[1] is the first rows, argv[2] is the first columns
	@returns: 0 so the program is successful.
	*/
	Board b; //create a Board type struct called b.
	b.board = NULL; //set the board to null
	if(argc == 1){ //no command line arguments has to default size to 10 x 10
		b.rows = 10;
		b.cols = 10;
		boardSetup(b.rows, b.cols, &(b.board));
	}else if(argc == 3){
		char shouldNotBeRead;
    int numReadRows = sscanf(argv[1], "%d %c", &(b.rows), &shouldNotBeRead);
    int numReadCols = sscanf(argv[2], "%d %c", &(b.cols), &shouldNotBeRead);
		if(numReadRows != 1 || numReadCols != 1 || (b.rows > 0 && b.cols > 0)){ //checks if user enters a word for row or column field then initializes the board
			boardSetup(b.rows, b.cols, &(b.board));
		}else if(numReadRows != 1){ //rows aren't an integer
			printf("The number of rows is not an integer.\n");
			printf("Making default board of 10 X 10.\n");
			b.rows = 10;
			b.cols = 10;
			boardSetup(b.rows, b.cols, &(b.board));
		}else if(numReadCols != 1){ //rows aren't an column
			printf("The number of columns is not an integer.\n");
			printf("Making default board of 10 X 10.\n");
			b.rows = 10;
			b.cols = 10;
			boardSetup(b.rows, b.cols, &(b.board));
		}else if(atoi(argv[1]) < 1){ //negative rows aren't possible
			printf("The number of rows is less than 1.\n");
			printf("Making default board of 10 X 10.\n");
			b.rows = 10;
			b.cols = 10;
			boardSetup(b.rows, b.cols, &(b.board));
		}else if(atoi(argv[2]) < 1){ //negative columns aren't possible
			printf("The number of columns is less than 1.\n");
			printf("Making default board of 10 X 10.\n");
			b.rows = 10;
			b.cols = 10;
			boardSetup(b.rows, b.cols, &(b.board));
		}else{ //valid input
			boardSetup(b.rows, b.cols, &(b.board));
		}
	}else{ //if invalid then default board to 10 x 10
		printf("Wrong number of command line arguments entered.\n");
		printf("Usage: ./paint.out [num_rows num_cols]\n");
		printf("Making default board of 10 X 10.\n");
		b.rows = 10;
		b.cols = 10;
		boardSetup(b.rows, b.cols, &(b.board));		
	}
	printBoard(b.board, b.rows, b.cols); //print the starting board
	bool ifUserEntersQ = false;
	//loop will keep asking user for their command until ifUserEntersQ == true, which is only true when 'q' is typed
	while(!ifUserEntersQ){
		getValidMove(&b.board, &b.rows, &b.cols, &ifUserEntersQ);
	}
	return 0;
}