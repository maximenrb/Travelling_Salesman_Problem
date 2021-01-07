OBJS	= main.o grasp.o generalFuncs.o Graph.o localSearchHeuristic.o
SOURCE	= main.cpp grasp.cpp ../../generalFuncs.cpp ../../Graph.cpp ../../Local_search/Source/localSearchHeuristic.cpp
HEADER	= grasp.h ../../generalFuncs.h ../../Graph.h ../../Local_search/Source/localSearchHeuristic.h
OUT	= grasp_algorithm
CC	 = g++
FLAGS	 = -O3 -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
	rm -f $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

grasp.o: grasp.cpp
	$(CC) $(FLAGS) grasp.cpp -std=c++14

generalFuncs.o: ../../generalFuncs.cpp
	$(CC) $(FLAGS) ../../generalFuncs.cpp -std=c++14

Graph.o: ../../Graph.cpp
	$(CC) $(FLAGS) ../../Graph.cpp -std=c++14

localSearchHeuristic.o : ../../Local_search/Source/localSearchHeuristic.cpp
	$(CC) $(FLAGS) ../../Local_search/Source/localSearchHeuristic.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)
