
autocounter: main.o
	g++ main.o -o autocounter

main.o: main.cpp
	g++ -c main.cpp

target: dependencies
	action
	
clean:
	rm *.o autocounter