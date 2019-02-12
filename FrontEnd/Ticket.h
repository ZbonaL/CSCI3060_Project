/*
This is a header file which defines the Ticket class, and declares all classes and methods used by Ticket objects.

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/
#include <string>
#ifndef TICKET_H_ //If a Ticket.h header file is not already included:
#define TICKET_H_ //Include the Ticket.h class

//Class name: Ticket
//Definition: A Ticket class for creating Transaction objects for our ticket selling program.
class Ticket{
    public:
        std::string EventTitle;
        int TicketQuantity;
        double TicketPrice;

		//Method name: Ticket
		//Purpose: Constructs a Ticket object with an EventTitle, TicketQuantity, and TicketPrice
        Ticket(std::string EventTitle, int TicketQuantity, double TicketPrice);

		//Method name: getEventTitle
		//Purpose: Returns the EventTitle of the Ticket object.
        std::string getEventTitle();

		//Method name: getTicketQuantity
		//Purpose: Returns the TicketQuantity of the Ticket object.
        int getTicketQuantity();

		//Method name: getTicketPrice
		//Purpose: Returns the TicketPrice of the Ticket object.
        double getTicketPrice(); 
};
#endif // Ends the ifndef condition