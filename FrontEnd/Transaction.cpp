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
using std::cout;
using std::cin;
using std::endl;

//Method: Transaction
Transaction::Transaction(){

}

string cmd;
string eventN;
string sellerN;
int ticketQ;

//Transaction Methods 
//Method: login
void Transaction::login(string UserName, string temp, bool nameExists){

    nameExists = 0;
	for(int i = 0; i < UserName.size() - 1; i++){
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
			cout << "Enter a Cmd (Only 'buy' and 'logout' work): ";
            cin >> cmd;
		}
        if(cmd == "buy"){
            buy(eventN, sellerN, ticketQ);
        }

        else if(cmd == "logout"){
           cout << "User " << UserName << " Logging Out " << endl;  
           logout();
      
        }  
	}

//Method: logout 
void Transaction::logout(){
    string filename;
    string output;
    
    std::ofstream file;
    file.open(filename.c_str());
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
    string confirm;
  //Event Stuff (Skeleton Code)
    cout << "Enter the Title of the Event: ";
    cin >> eventname;
    if(eventname.empty() || eventname.size() > 25){
        cout << "Sorry that was an Invalid event: Logging Out " << endl;
        logout();
    }
    else{
        cout << "Enter the Username of the Seller: ";
        cin >> sellername;
    }

//Seller Stuff
    if(sellername.empty() || sellername.size() > 15){
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
            logout();
        }

        else if (confirm == "n"){
            cout << "Transaction Cancelled. Logging Out " << endl;
            logout();
        }
}

//Method: refund
void Transaction::refund(string userNameBuy, string userNameSell, double creditAmount){

}

//Method: addCredit
void Transaction::addCredit(double creditAmount, string userName){

}