#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "inputValidation.h"
#include "board.h"
#include "quitHelpWrite.h"
#include "eraseResize.h"
#include "addDelete.h"
#include "saveandload.h"


char* append(char val, char* str, int* size){
	/* This function is from Professor Butner's code in the read_any_len folder on the google drive for pointers. This is used in the read_any_len_line() function to add a character
	to the end of a string 
	@val: is the character we want to add
	@str: is the str we want to add to
	@size: is the size of the string that we want to add 1 to since we increased its size
	@returns: the string*/
	(*size)++;
	str = (char*)realloc(str, *size * sizeof(char));
	str[*size - 1] = val;
	return str;
}

char* read_any_len_line() {
	/* This function is also from Professor Butner's code in the read_any_len folder on the google drive for pointers, but I changed it so it reads the whole line, not just a string
	There are no parameters and it returns the string which is the line the user entered.
	*/
	char cur_char;
	char* str = NULL;
	int cur_size = 0;

//####hello
	//skip leading whitespace
	do{
		scanf("%c", &cur_char);
	}while(isspace(cur_char));

	do{
		str = append(cur_char, str, &cur_size);
		scanf("%c", &cur_char);
	}while(cur_char != '\n'); //checks for the whole line(only change in function)

	//add the null character
	str = append('\0', str, &cur_size);
	return str;
}

bool getValidMove(char*** board, int* rows, int* cols, bool* isQ){
		/* This is the function where all the commands are called and the user input is validated. It returns true or false depending on if the user entered a valid input. If a proper command is entered, then the corresponding function will be called.
		@board: a pointer to the current board
		@rows: the current rows in the board
		@cols: the current columns in the board
		@isQ: this is a pointer to a bool that will only be set to the true when the user enters the q command
		@modifies: board, rows, cols, isQ
		@returns: a bool, either true or false depending on the users input*/
		bool isValidInput = false;
		printf("Enter your command: ");
		char* str;
		str = read_any_len_line(); //read the line of input
		if(str[0] == 'q'){ 
			char c;
			char n;
			int num_args_read = 0;
			num_args_read = sscanf(str, "%c %c", &c, &n);
			if(num_args_read == 1){ //means it is a valid q input
				isValidInput = true;
				*isQ = true; //set isQ to true
				quit((board), *rows, *cols); //call quit
			}else{
				printf("Unrecognized command. Type h for help.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'h'){ 
			char c;
			char n;
			int num_args_read = 0;
			num_args_read = sscanf(str, "%c %c", &c, &n);
			if(num_args_read == 1){ //if user enters valid h command
				isValidInput = true;
				print_help();
				printBoard(*board, *rows, *cols);
			}else{
				printf("Unrecognized command. Type h for help.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'w'){//to check if it is a valid write
			char c;
			int x1;
			int y1;
			int x2;
			int y2;
			int num_args_read = 0;
			char shouldNotBeRead;
			num_args_read = sscanf(str, "%c %d %d %d %d %c", &c, &x1, &y1, &x2, &y2, &shouldNotBeRead);
			if(num_args_read == 5 && x1 < *rows && y1 < *cols && x2 < *rows && y2 < *cols && x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0){
				isValidInput = true;
				typeOfLine(*board, x1, y1, x2, y2, *rows, *cols); //call typeOfLine then print board
				printBoard(*board, *rows, *cols);
			}else{
				printf("Improper draw command.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'e'){ //to check if it is a valid erase
			char c;
			int x;
			int y;
			int num_args_read = 0;
			char shouldNotBeRead;
			num_args_read = sscanf(str, "%c %d %d %c", &c, &x, &y, &shouldNotBeRead);
			if(num_args_read == 3 && x < *rows && y < *cols && x >=0 && y >= 0){
				isValidInput = true;
				erase(board, x, y, *rows, *cols);
				printBoard(*board, *rows, *cols);
			}else{
				printf("Improper erase command.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'r'){ //check if the resize is valid
			char c;
			int x;
			int y;
			char shouldNotBeRead;
			int num_args_read = 0;
			num_args_read = sscanf(str, "%c %d %d %c", &c, &x, &y, &shouldNotBeRead);
			if(num_args_read == 3 && x >= 0 && y >= 0){
				isValidInput = true;
				*board = resizeBoard(*board, x, y, rows, cols);
				printBoard(*board, *rows, *cols);
			}else{
				printf("Improper resize command.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'a'){ //check if the add is valid
			char c;
			char rowOrColumn;
			int num;
			char shouldNotBeRead;
			int num_args_read = 0;
			num_args_read = sscanf(str, "%c %c %d %c", &c, &rowOrColumn, &num, &shouldNotBeRead);
			if(num_args_read == 3){
				if(rowOrColumn == 'r' && num >= 0 && num <= *rows){ //if it is to add row
					isValidInput = true;
					*board = addedRow(*board, num, rows, *cols);
					printBoard(*board, *rows, *cols);
				}else if(rowOrColumn == 'c' && num >= 0 && num <= *cols){//if it is to add column
					isValidInput = true;
					*board = addedCol(*board, num, *rows, cols);
					printBoard(*board, *rows, *cols);
				}else{
					printf("Improper add command.\n");
					printBoard(*board, *rows, *cols);
					isValidInput = false;
				}
			}else{
				printf("Improper add command.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'd'){ //check if delete command is valid
			char c;
			char rowOrColumn;
			int num;
			char shouldNotBeRead;
			int num_args_read = 0;
			num_args_read = sscanf(str, "%c %c %d %c", &c, &rowOrColumn, &num, &shouldNotBeRead);
			if(num_args_read == 3){
				if(rowOrColumn == 'r' && num >= 0 && num < *rows){ //if to remove row
					isValidInput = true;
					*board = deleteRow(*board, num, rows, *cols);
					printBoard(*board, *rows, *cols);
				}else if(rowOrColumn == 'c' && num >= 0 && num < *cols){ //if to remove column
					isValidInput = true;
					*board = deleteCol(*board, num, *rows, cols);
					printBoard(*board, *rows, *cols);
				}else{
					printf("Improper delete command.\n");
					printBoard(*board, *rows, *cols);
					isValidInput = false;
				}
			}else{
				printf("Improper delete command.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 's'){ //check if it is a valid save command
			char c;
			char s[strlen(str)]; //create a new string to check if the filename is a valid .txt file
			char shouldNotBeRead;
			int num_args_read = sscanf(str, "%c %s %c", &c, s, &shouldNotBeRead);
			char* period = strrchr(str, '.'); //points to the last period in the line
			int index = (period - str); //will give the index of the last period
			if(num_args_read == 2 && str[index] == '.' && str[index + 1] == 't' && str[index + 2] == 'x' && str[index + 3] == 't'){ //check if it is a .txt file
				isValidInput = true;
				save(board, s, *rows, *cols);
				printBoard(*board, *rows, *cols);	
			}else{
				printf("Improper save command or file could not be created.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else if(str[0] == 'l'){ //check if it is a valid load command
			char c;
			char s[strlen(str)]; //to make sure the filename is a .txt file
			char shouldNotBeRead;
			int num_args_read = sscanf(str, "%c %s %c", &c, s, &shouldNotBeRead);
			char* period = strrchr(str, '.');
			int index = (period - str);
			if(num_args_read == 2 && str[index] == '.' && str[index + 1] == 't' && str[index + 2] == 'x' && str[index + 3] == 't' && doesFileExist(s)){ //checks if the file exists and if it ends with .txt
				isValidInput = true;
				load(board, s, rows, cols);
				printBoard(*board, *rows, *cols);
			}else{
				printf("Improper load command or file could not be opened.\n");
				printBoard(*board, *rows, *cols);
				isValidInput = false;
			}
		}else{ //not a valid command
			printf("Unrecognized command. Type h for help.\n");
			printBoard(*board, *rows, *cols);
			isValidInput = false;
		}
		free(str); //free the memory for the line
		return isValidInput;
}
