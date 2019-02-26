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
#include <stdlib.h>

//Importing from the standard library in order to avoid using redundant methods and slowing down performance.
using std::string;
using std::to_string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

//Method: Transaction
Transaction::Transaction(){

}


string cmd;
string result;

string newUser;
string accountType;
double userCredit;

string currUser;
string existUser;

string eventN;
string sellerN;
int ticketQ;
double ticketPrice;
double transactCredit;


void fileOutput(string result){
    std::ofstream file("TransactionTest.txt", std::ios::app);
    if(file.is_open() ==  true){
        file << result;
        file.close();
    }
}


//Transaction Methods 
//Method: login
void Transaction::login(string UserName, string temp, bool &nameExists){

    nameExists = 0;

        if (UserName.size() < 15){
			UserName += (string(15 - UserName.size(), ' '));

            if (UserName == temp.substr(0,15)){
                nameExists = 1;
            }

            else {
			nameExists = 0;
		}
		}
       
      if(nameExists == 1){
        	cout << "Welcome User: " <<  UserName << endl;
      }
	}

//Method: logout 
void Transaction::logout(){
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
    string result;

    cout << "Enter the Event Title: ";
    cin >> eventTitle;

    while (eventTitle.size() <= 25 && eventTitle.size() > 0){
        cout << "Enter the amount of tickets to sell: ";
        cin >> ticketQuantity;  

        if(ticketQuantity == 0 || ticketQuantity > 100){
            cout << "Logging out for either no Quanitity or exceeding Maximum" << endl;
            logout();
        }
        else{
            cout << "Enter the price for each ticket: ";
            cin >> ticketPrice;
        }
        if (ticketPrice > 999.99){
            cout << "Logging out for Exceeding Maximum Price" << endl;
            logout();
        }
        else{
            cout << "Inputs were all Successful, You can now sell tickets for the event" << endl;
            result = eventTitle + to_string(ticketQuantity) + to_string(ticketPrice);
            fileOutput(result);
            logout();
        }   
    }
    cout << "Length of Event exceeded maximum length" << endl;
    logout();
}




//Method: buy
void Transaction::buy(string eventname, string sellername, int ticketQuantity){
    string confirm;
    string result;
    
    cout << "Enter the Title of the Event: ";
    cin >> eventname;


    while (eventname.size() > 0 && eventname.size() < 25){
        cout << "Enter the Username of the Seller: ";
        cin >> sellername;
        
//Seller Stuff
    if(sellername.size() == 0 || sellername.size() > 15){
         cout << "Invalid Seller. Logging Out " << endl;
         logout();
        }
    else{
       cout << "Enter the amount of Tickets: ";
       cin >> ticketQuantity;
    }
        
//Ticket Stuff
    if(ticketQuantity == 0 || ticketQuantity > 4){
        cout << "Invalid Amount of Tickets. Logging Out " << endl;
        logout();
    }
    else{
        cout << "Do You confirm the transaction [y/n]: ";
        cin >> confirm;
    }

        if(confirm == "y"){
            cout << "Transaction Completed. Logging Out " << endl;
            result = eventname + sellername + to_string(ticketQuantity);
            fileOutput(result);
            logout();
        }

        else if (confirm == "n"){
            cout << "Transaction Cancelled. Logging Out " << endl;
            logout();
        }
}
        cout << "Sorry that was an Invalid event: Logging Out " << endl;
        logout();
}

//Method: refund
void Transaction::refund(string userNameBuy, string userNameSell, double creditAmount){

}

//Method: addCredit
void Transaction::addCredit(double creditAmount, string userName){

}