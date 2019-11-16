CC = g++
CPPFLAGS  = -g -Wall -Werror
default: sortedverification consistentresultverification timealgorithms

sortedverification:		sortedverification.o
	g++ -o sortedverification sortedverification.o
sortedverification.o:	sortedverification.cxx
	g++ -c sortedverification.cxx
consistentresultverification:                consistentresultverification.o
	g++ -o consistentresultverification consistentresultverification.o
consistentresultverification.o:	consistentresultverification.cxx
	g++ -c consistentresultverification.cxx
timealgorithms: timealgorithms.o insertionsort.o mergesort.o quicksort.o
	g++ -o timealgorithms timealgorithms.o insertionsort.o mergesort.o quicksort.o
timealgorithms.o: timealgorithms.cxx
	g++ -c timealgorithms.cxx
insertionsort.o: insertionsort.cpp insertionsort.h
	g++ -c insertionsort.cpp
mergesort.o: mergesort.cpp mergesort.h
	g++ -c mergesort.cpp
quicksort.o: quicksort.cpp quicksort.h
	g++ -c quicksort.cpp

clean:
	rm -f core sortedverification consistentresultverification insertionsort mergesort quicksort timealgorithms *.o *~