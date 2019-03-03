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
	std::string EventSeller;
        int TicketQuantity;
        double TicketPrice;

/* 
	This function is called when a Ticket object is created
	@params: string EventTitle: the name of the Event on the ticket
			 int TicketQuantity: the number of available tickets for the event.
			 double TicketPrice: the price of the ticket.
	@returns: Constructs the Ticket object.

*/	
	Ticket();
        Ticket(std::string EventTitle, std::string EventSeller, int TicketQuantity, double TicketPrice);

/*		
	This function is for getting the EventTitle from a Ticket object
	@params: None
	@returns: The event title on the Ticket object.
*/
        std::string getEventTitle();

/*	
	This function returns the number of tickets available for this Ticket object
	@params: None
	@returns: The ticket quantity on the Ticket object

*/
	std::string getEventSeller();


/*	
	This function returns the number of tickets available for this Ticket object
	@params: None
	@returns: The ticket quantity on the Ticket object
*/
        int getTicketQuantity();

/*		
	This function returns the price of 1 ticket available for this Ticket object
	@params: None
	@returns: The ticket price on the Ticket object
*/
        double getTicketPrice(); 


	void setEventTitle(std::string EventName);

	void setEventPrice(double EventPrice);

	void setEventQuantity(int EventTickets);
	
	void setEventSeller(std::string SellerName);
};
#endif // Ends the ifndef condition