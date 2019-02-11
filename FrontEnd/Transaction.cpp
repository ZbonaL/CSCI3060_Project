#include <Transaction.h>
#include <iostream>
#include <string>
#include <User.h>
#include <Ticket.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//Transaction Methods 
// Login #TODO
void login(string userName){
    cout << "Enter a Username: ";
    cin >> userName;

    while(userName.size() == 0 || userName.size() == 15){
        cout << "Was not Correct. Please Try Again" << endl;

    }

}

// Logout #TODO
void logout(){
}

// Create
void create(string userName, string accountType, double credit){

}

// Delete Note: Used deleteUser instead of delete due to delete being a C++ keyword
void deleteUser(string userName){

}

// Sell
void sell(){

}

// Buy #TODO
void buy(string eventname, string sellername, int ticketQuantity){
    cout << "Enter the Login of the Event: ";
    cin >> eventname;
    if (eventname.size() == 0 || eventname.size() > 25){
        cout << "Sorry that was an invalid event: ";
        //logout();
    }
    else{
        cout << "Enter the Seller's Username: ";
        cin >> sellername;
    }
}

// Refund
void refund(){

}

// AddCredit
void addcredit(){

}