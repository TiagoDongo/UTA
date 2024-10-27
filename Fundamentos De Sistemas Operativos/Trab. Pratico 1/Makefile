main: main.o header.o
	gcc -o main  main.o header.o

main.o: main.c header.h
	gcc -g -c main.c

header.o: header.c header.h
	gcc -g -c header.c

clean:
	rm -f *.o main
