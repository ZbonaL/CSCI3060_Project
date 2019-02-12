/*
This is a program that holds the definitions of the methods and classes defined in Transaction.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <iostream>
#include "User.h" //Includes the declaration of the User class and its methods.
#include "Transaction.h" //Includes the declaration of the Transaction class and its methods.
#include <string>
#include <fstream>

//Importing from the standard library in order to avoid using redundant methods and slowing down performance.
using std::string;
using std::cout;
using std::cin;
using std::endl;

//Method: Transaction
Transaction::Transaction(){

}

std::string command;


//Transaction Methods 
//Method: login
void Transaction::login(string UserName, string temp, bool nameExists){
    std::string eventTitle;
    std::string sellername;
    int ticketQuantity;
       
    int     nameExists = 0;
	for(int i = 0; i < UserName.size(); i++){
        if (UserName[i] == temp[i]){
			nameExists = 1;
		}
        else {
			nameExists = 0;
			break;
		}
       
            
	}
    
    if(nameExists){
        cout << "Welcome User: " << UserName << endl;
		std::cout << "Enter a Command: ";
        std::cin >> command;
        if (command == "buy"){
            buy(eventTitle, sellername, ticketQuantity);
        }
        if (command == "logout"){
            logout();
        }
    }
}

//Method: logout
void Transaction::logout(){
    string filename;
    string output;
    
    std::ofstream file;
    file.open(filename);
    file << output;
    file.close();
    exit(0);
}

//Method: create
void Transaction::create(string userName, string accountType, double credit){

}

//Method: deleteUser
// Delete Note: Used deleteUser instead of delete due to delete being a C++ keyword
void Transaction::deleteUser(string userName){

}

//Method: sell
void Transaction::sell(string eventTitle, int ticketQuantity, double ticketPrice){

}

//Method: buy
void Transaction::buy(string eventname, string sellername, int ticketQuantity){
    cout << "Enter the Title of the Event: ";
    cin >> eventname;
    if (eventname.size() == 0 || eventname.size() > 25){
        cout << "Sorry that was an invalid event: ";
    }
    else{
        cout << "Enter the Seller's Username: ";
        cin >> sellername;
    }
}

//Method: refund
void Transaction::refund(string userNameBuy, string userNameSell, double creditAmount){

}

//Method: addCredit
void Transaction::addCredit(double creditAmount, string userName){

}