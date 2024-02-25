todoList: main.o 
	g++ main.o -o main

driver.o: main.cpp linkedlist.h node.h
	g++ -c main.cpp

clean:
	rm *.o driver
