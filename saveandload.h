#ifndef SAVEANDLOAD_H
	#define SAVEANDLOAD_H
	#include <stdbool.h>
	//call all files in saveandload.c
	void save(char*** board, char* fileName, int rows, int cols);
	void load(char*** board, char* filename, int* rows, int* cols);
	bool doesFileExist(char* fileName);
#endif