#include <Transaction.h>
#include <iostream>
#include <string>
#include <User.h>
#include <Ticket.h>

using std::string;




//Grabs the transaction from the methods below 
void getTransactionID(){

}

//Transaction Methods 
// Login #TODO
void login(string userName){
    std::cout << "Enter a Username: ";
    std::cin >> userName;

    while(userName.size() == 0 || userName.size() == 15){
        std::cout << "Was not Correct. Please Try Again" << std::endl;

    }

}

// Logout #TODO
void logout(){
}

// Create
void createUser(string userName, string accountType, double credit){

}

// Delete
void deleteUser(string userName){

}

// Sell
void sell(){

}

// Buy #TODO
void buy(string eventname, string sellername, int ticketQuantity){
    std::cout << "Enter the Login of the Event: ";
    std::cin >> eventname;
    if (eventname.size() == 0 || eventname.size() > 25){
        std::cout << "Sorry that was an invalid event: ";
        //logout();
    }
    else{
        std::cout << "Enter the Seller's Username: ";
        std::cin >> sellername;
    }
}

// Refund
void refund(){

}

// AddCredit
void addcredit(){

}