#ifndef QUITHELPWRITE_H
	#define QUITHELPWRITE_H
	#include <stdbool.h>
	//calls all function in quitHelpWrite.c
	void quit(char*** b, int r, int c);
	int slope(int startRow, int startColumn, int endRow, int endColumn);
	bool isFilled(char*** b, int r, int c);
	void print_help();
	void vertical(char*** b, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
	void horizontal(char*** b, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
	void onePoint(char*** b, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
	void right_diagonal(char*** b, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
	void left_diagonal(char*** b, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
	void typeOfLine(char** board, int startRow, int startColumn, int endRow, int endColumn, int rows, int cols);
#endif