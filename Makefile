CC=gcc

output: main.o Task.o Commands.o 
	g++ main.o Task.o Commands.o -o output

main.o: main.cpp
	g++ -c main.cpp

Task.o: Task.cpp Task.hpp
	g++ -c Task.cpp

Commands.o: Commands.cpp Commands.hpp
	g++ -c Commands.cpp

clean:
	rm *.o output
