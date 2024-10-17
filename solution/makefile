all: hw
	./hw map.txt

hw: hw.o GameBoard.o
	g++ -o hw hw.o GameBoard.o

hw.o: hw.c++ GameBoard.h
	g++ -std=c++23 -c hw.c++

GameBoard.o: GameBoard.c++ GameBoard.h
	g++ -std=c++23 -c GameBoard.c++

clean:
	rm -f *.o hw

.PHONY: all clean

