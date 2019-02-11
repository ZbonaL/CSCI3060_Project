#include "Ticket.h"
#include <string>

using std::string;

Ticket::Ticket(string EventTitle, int TicketQuantity, double TicketPrice){
    this->EventTitle = EventTitle;
    this->TicketQuantity = TicketQuantity;
    this->TicketPrice = TicketPrice;
}

string Ticket::getEventTitle(){ return EventTitle; }
int Ticket::getTicketQuantity(){ return TicketQuantity; }
double Ticket::getTicketPrice(){ return TicketPrice; }