all: alls
alls: main.o geometry.o
main.o: main.c
	gcc -Wall -Werror -o main main.c
geometry.o: geometry.c
	gcc -Wall -Werror -o geometry geometry.c
