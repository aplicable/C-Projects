##Start of the Makefile
main: main.o list.o schedulers.o graphics.o
	gcc -o main main.o list.o schedulers.o graphics.o

main.o: main.c defs.h 
	gcc -Wall -g -c main.c

graphics.o: graphics.c defs.h 
	gcc -Wall -g -c graphics.c

list.o: list.c defs.h 
	gcc -Wall -g -c list.c
	
schedulers.o: schedulers.c defs.h 
	gcc -Wall -g -c schedulers.c

clean:
	rm *.o
##End of the Makefile
