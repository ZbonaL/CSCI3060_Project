/*
This is a program that holds the definitions of the methods and classes defined in Ticket.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/
#include "Ticket.h" //Includes the declaration of the Ticket class and its methods.
#include <string>

using std::string;


Ticket::Ticket(){}

//Method: Ticket
Ticket::Ticket(string EventTitle, string EventSeller, int TicketQuantity, double TicketPrice){
    this->EventTitle = EventTitle;
    this->EventSeller = EventSeller;
    this->TicketQuantity = TicketQuantity;
    this->TicketPrice = TicketPrice;
}

//Method: getEventTitle
string Ticket::getEventTitle(){ return EventTitle; }

//Method: getEventTitle
string Ticket::getEventSeller(){ return EventSeller; }

//Method: getTicketQuantity
int Ticket::getTicketQuantity(){ return TicketQuantity; }

//Method: getTicketPrice
double Ticket::getTicketPrice(){ return TicketPrice; }

void Ticket::setEventTitle(string EventName){EventTitle = EventName;}
void Ticket::setEventSeller(string SellerName){EventSeller = SellerName; }
void Ticket::setEventPrice(double EventPrice){TicketPrice = EventPrice;}
void Ticket::setEventQuantity(int EventTickets){TicketQuantity = EventTickets;}