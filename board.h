#ifndef BOARD_H
	#define BOARD_H
	#include <stdio.h>
	typedef struct Board_struct{ //board struct that has rows, cols, and a 2d board
		int rows;
		int cols;
		char** board;
	}Board;
	//call all functions in board
	char** makeBoard(int rows, int cols);
	void boardSetup(int rows, int cols, char*** b);
	void printBoard(char** b, int rows, int cols);
#endif