CC = g++
CPPFLAGS  = -g -Wall -Werror
default: sortedverification consistentresultverification

sortedverification:		sortedverification.o
	g++ -o sortedverification sortedverification.o
sortedverification.o:	sortedverification.cxx
	g++ -c sortedverification.cxx
consistentresultverification:                consistentresultverification.o
	g++ -o consistentresultverification consistentresultverification.o
consistentresultverification.o:	consistentresultverification.cxx
	g++ -c consistentresultverification.cxx
clean:
	rm -f core sortedverification *.o *~