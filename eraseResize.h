#ifndef ERASERESIZE_H
	#define ERASERESIZE_H
	//calls functions in eraseResize.c
	void erase(char*** board, int enterRow, int enterCol, int rows, int cols);
	char** resizeBoard(char** board, int r, int c, int* rows, int* cols);
#endif