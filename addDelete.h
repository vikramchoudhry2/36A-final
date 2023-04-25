#ifndef ADDDELETE_H
	#define ADDDELETE_H
	//calls all the functions in the addDelete.c
	char** addedRow(char** b, int rowAdd, int* rows, int cols);
	char** addedCol(char** b, int colAdd, int rows, int* cols);
	char** deleteRow(char** b, int rowRemove, int* rows, int cols);
	char** deleteCol(char** b, int colRemove, int rows, int* cols;);
#endif
	
	