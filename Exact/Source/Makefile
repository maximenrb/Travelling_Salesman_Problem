OBJS	= main.o exact.o generalFuncs.o Graph.o
SOURCE	= main.cpp exact.cpp ../../generalFuncs.cpp ../../Graph.cpp
HEADER	= exact.h ../../generalFuncs.h ../../Graph.h
OUT	= exact_algorithm
CC	 = g++
FLAGS	 = -O3 -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
	rm -f $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

exact.o: exact.cpp
	$(CC) $(FLAGS) exact.cpp -std=c++14

generalFuncs.o: ../../generalFuncs.cpp
	$(CC) $(FLAGS) ../../generalFuncs.cpp -std=c++14

Graph.o: ../../Graph.cpp
	$(CC) $(FLAGS) ../../Graph.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
