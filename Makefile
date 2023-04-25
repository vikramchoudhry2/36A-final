paint.out: addDelete.o board.o eraseResize.o inputValidation.o main.o quitHelpWrite.o saveandload.o
	gcc -g -Wall -Werror -o paint.out addDelete.o board.o eraseResize.o inputValidation.o main.o quitHelpWrite.o saveandload.o
addDelete.o: addDelete.c addDelete.h
	gcc -g -Wall -Werror -c addDelete.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
eraseResize.o: eraseResize.c eraseResize.h
	gcc -g -Wall -Werror -c eraseResize.c
inputValidation.o: inputValidation.c inputValidation.h board.h quitHelpWrite.h eraseResize.h addDelete.h saveandload.h
	gcc -g -Wall -Werror -c inputValidation.c
main.o: main.c inputValidation.h board.h
	gcc -g -Wall -Werror -c main.c
quitHelpWrite.o: quitHelpWrite.c quitHelpWrite.h
	gcc -g -Wall -Werror -c quitHelpWrite.c
saveandload.o: saveandload.c saveandload.h
	gcc -g -Wall -Werror -c saveandload.c
clean:
	rm -rf *.o *.out
