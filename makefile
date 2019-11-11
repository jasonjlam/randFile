all:  random.o main.o
	gcc -o program random.o main.o

main.o: random.h main.c
	gcc -c -g main.c

random.o: random.c
	gcc -c -g random.c

run:
	./program

clean:
	rm *.o
