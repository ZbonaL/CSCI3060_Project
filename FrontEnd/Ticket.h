#include <string>

using std::string;


class Ticket{

    private:
        int TicketID;
        string EventTitle;
        int TicketQuantity;
        double TicketPrice;
    
    public:
        Ticket(int TicketID, string EventTitle, int TicketQuantity, double TicketPrice);

        void setTicket(int TicketID, string EventTitle, int TicketQuantity, double TicketPrice);

        int getTicketID(){ return TicketID;}
        string getEventTitle(){ return EventTitle;}
        int getTicketQuantity(){ return TicketQuantity;}
        double getTicketPrice(){ return TicketPrice;}
};