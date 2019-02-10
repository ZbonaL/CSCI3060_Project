#include <Ticket.h>
#include <string>

using std::string;

Ticket::Ticket(int TicketID, string EventTitle, int TicketQuantity, double TicketPrice){
    setTicket(TicketID, EventTitle, TicketQuantity, TicketPrice);
}


void Ticket::setTicket(int TicketID, string EventTitle, int TicketQuantity, double TicketPrice){
    TicketID = TicketID;
    EventTitle = EventTitle;
    TicketQuantity = TicketQuantity;
    TicketPrice = TicketPrice;
}