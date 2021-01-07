OBJS	= main.o constructiveHeuristic.o generalFuncs.o Graph.o
SOURCE	= main.cpp constructiveHeuristic.cpp ../../generalFuncs.cpp ../../Graph.cpp
HEADER	= constructiveHeuristic.h ../../generalFuncs.h ../../Graph.h
OUT	= constructive_algorithm
CC	 = g++
FLAGS	 = -O3 -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
	rm -f $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

constructiveHeuristic.o: constructiveHeuristic.cpp
	$(CC) $(FLAGS) exact.cpp -std=c++14

generalFuncs.o: ../../generalFuncs.cpp
	$(CC) $(FLAGS) ../../generalFuncs.cpp -std=c++14

Graph.o: ../../Graph.cpp
	$(CC) $(FLAGS) ../../Graph.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
