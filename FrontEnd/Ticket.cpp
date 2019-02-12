/*
This is a program that holds the definitions of the methods and classes defined in Ticket.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/
#include "Ticket.h" //Includes the declaration of the Ticket class and its methods.
#include <string>

using std::string;

//Method: Ticket
Ticket::Ticket(string EventTitle, int TicketQuantity, double TicketPrice){
    this->EventTitle = EventTitle;
    this->TicketQuantity = TicketQuantity;
    this->TicketPrice = TicketPrice;
}

//Method: getEventTitle
string Ticket::getEventTitle(){ return EventTitle; }

//Method: getTicketQuantity
int Ticket::getTicketQuantity(){ return TicketQuantity; }

//Method: getTicketPrice
double Ticket::getTicketPrice(){ return TicketPrice; }