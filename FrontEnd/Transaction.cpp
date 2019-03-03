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
using std::to_string;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::stod;
//Method: Transaction
Transaction::Transaction(){

}


string cmd;
string result;


string currUser;
string existUser;


string eventN;
string sellerN;
int ticketQ;
double ticketPrice;
double transactCredit;
//Checks if user exists
bool checkUserExists(string username, User &user){
	std::ifstream input;
	string currentReadName = "";
	string filename = "Current_User_Accounts_File.txt";
    input.open(filename.c_str());
	if(input.fail()){
        cout << "Reading of current user file has failed." << endl;
        return false;
    }
	while (!input.eof()) {
		getline(input, currentReadName);
		if (username.size() <= 15){
			username += (string(15 - username.size(), ' '));
        	if (username == string(currentReadName.begin(), currentReadName.begin() + 15)){
				user.UserName = string(currentReadName.begin(), currentReadName.begin() + 15);//temp.substr(0,15);
				user.accountType =string(currentReadName.begin()+16 , currentReadName.begin() + 18);//temp.substr(0,15);
				user.creditAmount = stod(currentReadName.substr(19,26));
                return true;
        	} else {
			}
		}
	}
	return false;
}
//Checks if ticket exists
bool checkTicketExists(string ticketname){
	std::ifstream input;
	string currentReadName = "";
	string filename = "Available_Tickets_File.txt";
    input.open(filename.c_str());
	if(input.fail()){
        cout << "Reading of available tickets file has failed." << endl;
        return false;
    }
	while (!input.eof()) {
		getline(input, currentReadName);
		if (ticketname.size() <= 25){
			ticketname += (string(25 - ticketname.size(), ' '));
        	if (ticketname == string(currentReadName.begin(), currentReadName.begin() + 25)){
                return true;
        	} else {
			}
		}
	}
	return false;
}
//Transaction Methods 

//Method: login
void Transaction::login(string UserName, string temp, bool &nameExists, User &currentUser){
    nameExists = 0;

        if (UserName.size() <= 15){
			UserName += (string(15 - UserName.size(), ' '));
		
        	if (UserName == temp.substr(0,15)){
                nameExists = 1;
        	} else {
				nameExists = 0;
			}
		}
       
      if(nameExists == 1){
        	cout << "Welcome User: " <<  UserName << endl;
        
			currentUser.UserName = string(temp.begin(), temp.begin() + 15);//temp.substr(0,15);
			currentUser.accountType =string(temp.begin()+16 , temp.begin() + 18);//temp.substr(0,15);
			currentUser.creditAmount = stod(temp.substr(19,26));
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
void Transaction::deleteUser(User adminUser){
    string userToDel;
    if(adminUser.getAccountType() == "AA"){
        cout << "Enter an Account to Delete from the System ";
        getline(cin, userToDel, '\n');
        //#TODO
        //Calls Transaction File Here and Writes to it
    }
    else{
        cout << "Not an Admin User, Try Another Command. " << endl;
    }
}

//Method: sell
void Transaction::sell(User sellerAccount){
    string result;
    string eventTitle;
    string ticketQuantity;
    string ticketPrice;

while(sellerAccount.getAccountType() != "BS"){ // As long as the user is not BS
    cout << "Enter the Event Title: ";
    getline(cin, eventTitle, '\n');
    

    if ((eventTitle.size() > 25 )|| (eventTitle.empty() == true)){
         cout << "ERROR: Either no Input OR Exceeded Maximum Length for Event Name." << endl;
        logout();
    }

    else{
        cout << "Enter the price for each ticket: ";
        getline(cin, ticketPrice, '\n');
       
    }

    if(ticketPrice.empty() == true || stod(ticketPrice) > 999.99){
        cout << "ERROR: Either no Input OR Exceeded Maximum Price for Tickets." << endl;
        logout();
    }

    else{
        cout << "Enter the amount of tickets to sell: ";
        getline(cin, ticketQuantity, '\n');
        }  

    if(ticketQuantity.empty() == true || stoi(ticketQuantity) > 100){
        cout << "ERROR: Either no Input OR Exceeded Maximum Amount of Tickets to Sell." << endl;
        logout();
    }
        
    else{
        cout << "Inputs were all Successful, You can now sell tickets for the event" << endl;
        result = eventTitle + ticketQuantity + ticketPrice;
        logout();
        } 
    }
    cout << "This is a Buy-Standard Account. Please Try Another Transaction" << endl;
    // logout();
}

//Method: buy
void Transaction::buy(User buyerAccount){
    string eventname;
    string sellername;
    string ticketQuantity;

    string result;

while(buyerAccount.getAccountType() != "SS"){

    cout << "Enter the Title of the Event: ";
    getline(cin, eventname, '\n');

    if(eventname.empty() == true || eventname.size() > 25){
        cout << "ERROR: Either no Input OR Exceeded Maximum Length for Event Name." << endl;
        logout();
    }

    else{
        cout << "Enter the Username of the Seller: ";
        getline(cin, sellername, '\n');
    }

//Seller Stuff
    if(sellername.empty() == true || sellername.size() > 15){
         cout << "ERROR: Either no Input OR Exceeded Maximum Length for Seller Name." << endl;
         logout();
        }
    
    else{
       cout << "Enter the amount of Tickets: ";
       getline(cin, ticketQuantity, '\n');
    }
 //Ticket Stuff   
    if(ticketQuantity.empty() == true || stoi(ticketQuantity) > 4){
        cout << "ERROR: Either no Input OR Exceeded Maximum Amount of Tickets to Buy." << endl;
        logout();
    }

    else{
       cout << "Transaction Done" << endl;
        logout();
        }
    }
    cout << "This is a Sell-Standard Account. Please Try Another Transaction" << endl;
}

//Method: refund
void Transaction::refund(User UserAccount){
	string transactionresult;
	string buyerName; //Will become User objects in future.
	string sellerName; //Will become User objects in future.
	string creditTransfer; 

	User buyer;	
	User seller;

	//TODO: CHECK USERS PRIVELEGE (can be done later) 
	if (UserAccount.getAccountType() == "AA") {
		//Continue refund.
		//Prompt user for buyer username
		cout << "Please enter the buyers username: ";
		getline(cin, buyerName);
		//TODO: Check valid buyer username format
		if (buyerName.size() <= 15 && buyerName.size() >= 0){
			//Continue Transaction
			//TODO: Check if buyer username exists
			if (checkUserExists(buyerName, buyer) == true){
				cout << "Valid buyer profile found.";
				//Prompt user for seller username
				cout << endl;
				cout << "Please enter the sellers username: ";
				getline(cin, sellerName);
				//TODO: Check valid seller username format
				if (sellerName.size() <= 15 && sellerName.size() >= 0){
					//Continue Transaction
					//TODO: Check if seller username exists
					if (checkUserExists(sellerName, seller) == true){
						cout << "Valid seller profile found.";
						//Prompt user for amount of credit
						cout << endl;
						cout << "Please enter the credit to refund: ";
						getline(cin, creditTransfer);
						//TODO: Check valid credit entry
						
					} else {
						//End transaction for non existing sellername
						cout << "The seller name you have entered is non existant." << endl;
					}
				} else {
					// End transaction for invalid seller username
					cout << "The seller name you have entered is formatted incorrectly." << endl;
				}	
			} else {
				//End Transaction for non existing buyername.
				cout << "The buyer name you have entered is non existant." << endl;
			}
		} else {
			//End Transaction for invalid buyer username
			cout << "The buyer name you have entered is formatted incorrectly." << endl;
		}
	} else {
		//End Transaction for non admin user
		cout << "Only users with admin priveleges can make refunds." << endl;
	}
	
}

//Method: addCredit
void Transaction::addCredit(){
	string inputAccount;
	double creditTransfer;
	//TODO: Check users privelege (Can be done later)
	//TODO: Check if recieverAccount exists
	//TODO: Check if sufficient credits to be transfered.
	
	//TODO:
}