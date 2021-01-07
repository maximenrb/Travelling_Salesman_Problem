OBJS	= main.o localSearchHeuristic.o generalFuncs.o Graph.o constructiveHeuristic.o
SOURCE	= main.cpp localSearchHeuristic.cpp ../../generalFuncs.cpp ../../Graph.cpp ../../Constructive/Source/constructiveHeuristic.cpp
HEADER	= localSearchHeuristic.h ../../generalFuncs.h ../../Graph.h ../../Constructive/Source/constructiveHeuristic.h
OUT	= localSearch_algorithm
CC	 = g++
FLAGS	 = -O3 -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
	rm -f $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

localSearchHeuristic.o: localSearchHeuristic.cpp
	$(CC) $(FLAGS) localSearchHeuristic.cpp -std=c++14

generalFuncs.o: ../../generalFuncs.cpp
	$(CC) $(FLAGS) ../../generalFuncs.cpp -std=c++14

Graph.o: ../../Graph.cpp
	$(CC) $(FLAGS) ../../Graph.cpp -std=c++14

constructiveHeuristic.o : ../../Constructive/Source/constructiveHeuristic.cpp
	$(CC) $(FLAGS) ../../Constructive/Source/constructiveHeuristic.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
