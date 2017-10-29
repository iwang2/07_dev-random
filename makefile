all: rand.c
	gcc -o things rand.c

clean:
	rm array.txt
	rm things
	rm rand.o
	rm *~

run: all
	./things
