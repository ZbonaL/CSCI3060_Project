output: main.o Transaction.o User.o Ticket.o
	g++ -std=c++11 main.o Transaction.o User.o Ticket.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Transaction.o:	Transaction.cpp Transaction.h
	g++ -std=c++11 -c Transaction.cpp 

User.o: User.cpp User.h
	g++ -std=c++11 -c User.cpp

Ticket.o: Ticket.cpp Ticket.h
	g++ -std=c++11 -c Ticket.cpp

clean:
	rm *.o output