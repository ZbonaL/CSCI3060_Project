#include <string>
#ifndef TICKET_H_
#define TICKET_H_

class Ticket{
    public:
        std::string EventTitle;
        int TicketQuantity;
        double TicketPrice;

        Ticket(std::string EventTitle, int TicketQuantity, double TicketPrice);
        std::string getEventTitle();
        int getTicketQuantity();
        double getTicketPrice(); 
};
#endif 