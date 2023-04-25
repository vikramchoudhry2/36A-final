#ifndef INPUTVALIDATION_H
	#define INPUTVALIDATION_H
	#include <stdbool.h>
	//call all the functions in inputValidation.c
	char* append(char v, char* s, int* size);
	char* read_any_len_line();
	bool getValidMove(char*** paintBoard, int* rows, int* cols, bool* ifQEntered);
#endif