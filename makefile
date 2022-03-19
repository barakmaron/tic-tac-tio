all: functions.o ttt.o
	g++ functions.o ttt.o -o game

functions.o: functions.cpp functions.hpp
	g++ -c -g -Wall functions.cpp
	
ttt.o: ttt.cpp 
	g++ -c -g -Wall ttt.cpp
clean:
	rm *.o
