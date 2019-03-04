/*
This is a program that handles ticket sales:

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "User.h"
#include "Transaction.h"
#include "Ticket.h"


using namespace std;
Transaction transaction;
User currentUser;
string first;



/*
    This functions is for wroking with the user file. It takes in user input and searches 
    for the user in the Current_User_Accounts_File.txt, If the user exists then provide next set of options

    @param string filename: This variable takes in the Current_Users file
    @returns the next set of options if the user exist, else exit 
*/
void readCurrentUser(string filename);


int main(int argc, char const *argv[]){
    
    cout << "Welcome to FooBar Ticket Service" << endl;
	    
    cout << "Please enter login to begin: ";
    getline(cin, first, '\n');
    if (first == "login"){
        cout << "Please Enter A User Name: ";
        readCurrentUser("Current_User_Accounts_File.txt");
	} else if (first == "logout"){
		transaction.logout();
	} else {
		cout << "Please enter login to start the service, or enter logout to exit this." << endl;
         
	}
    

   return 0;
}

void readCurrentUser(string filename){

    ifstream file_input;
    bool nameExists = 0;
    file_input.open(filename.c_str());

    string cmd;
    
    string new_username;
    string eventTitle;
    string sellername;
    int ticketQuantity;
    double ticketPrice;

    getline(cin, new_username, '\n');

    if(file_input.fail()){
        cout << "Reading of current user file has failed." << endl;
        exit(1);
    }

    while(!file_input.eof()){
        string temp = "";
        getline(file_input, temp, '\n');
	
        
        transaction.login(new_username, temp, nameExists, currentUser);
        // cout << currentUser.getAccountType() << endl;
		// cout << currentUser.getCreditAmount() << endl;
       while(nameExists == 1){

           cout << "Enter The Command: ";
            getline(cin, cmd, '\n');

            if(cmd == "logout"){
                transaction.logout(currentUser);
            }else if(cmd == "create"){
                transaction.create(currentUser); 
            }else if(cmd == "delete"){
                transaction.deleteUser(currentUser);
            }else if(cmd == "buy"){
                transaction.buy(currentUser);
            }else if(cmd == "sell"){
                transaction.sell(currentUser);
            }else if(cmd == "refund"){
                transaction.refund(currentUser);
            }else if(cmd == "addcredit"){
                transaction.addCredit(currentUser);
            }
        
       }
   
    if(file_input.eof()&&(nameExists == 0)){
        cout << "User doesnt exist." << endl;
    }
    }
    file_input.close();
}
