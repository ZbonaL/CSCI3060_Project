output: main.o Transaction.o User.o Ticket.o
	g++ main.o Transaction.o User.o Ticket.o -o output

main.o: main.cpp
	g++ -c main.cpp

Transaction.o:	Transaction.cpp Transaction.h
	g++ -c Transaction.cpp 

User.o: User.cpp User.h
	g++ -c User.cpp

Ticket.o: Ticket.cpp Ticket.h
	g++ -c Ticket.cpp

clean:
	rm *.o output