/*
This is a program that handles ticket sales:

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Transaction.h"
#include "Ticket.h"


using namespace std;
Transaction transaction;


/*
    This funtion is called when the user logs out.
    It prints out the last transaction that was made at the time of logout.
    
    @param: string filename: name of the file to be written tp
    @return: a daily transaction file that
*/
void dailyTransaction(string filename);

/*
    This functions is for wroking with the user file. It takes in user input and searches 
    for the user in the Current_User_Accounts_File.txt, If the user exists then provide next set of options

    @param string filename: This variable takes in the Current_Users file
    @returns the next set of options if the user exist, else exit 
*/
void readCurrentUser(string filename);

/*
    This function is for reading the event file, and checking if the event exists.
    
    @param string filename takes in the file that stores all the events
    @returns a vaild purchase if the event exists and if the user bought proper amount of tickets
*/
void readTicketFile(string filename);

int main(int argc, char const *argv[]){


   if(argv[1] != NULL){
        ifstream inFile;
        string data;
        inFile.open(argv[1]);


        while(getline(inFile, data)){
            if(data == "login"){
                cout << "user is logged in." << endl;
            }
        }
        inFile.close();
   }else{
        cout << "Welcome to FooBar Ticket Service" << endl;
        cout << "Please Enter A User Name: ";
        readCurrentUser("Current_User_Accounts_File.txt");

    }

   return 0;
}

void readCurrentUser(string filename){

    ifstream file_input;
    bool nameExists = 0;
    file_input.open(filename);

    string new_username;
    string eventTitle;
    string sellername;
    int ticketQuantity;

    getline(cin, new_username);

    if(file_input.fail()){
        cout << "Reading of current user file has failed." << endl;
        exit(1);
    }

    while(!file_input.eof()){

        string temp = "";
        getline(file_input, temp);
	
        transaction.login(new_username, temp, nameExists);
    }
    
    if(file_input.eof()&&(nameExists == 0)){
        cout << "User doesnt exist." << endl;
    }

    file_input.close();
}
