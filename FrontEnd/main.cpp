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
Transaction transction;

/**/
void dailyTransaction(string filename);
/**/
void readCurrentUser(string filename);
/**/
void readTicketFile(string filename);

int main(int argc, char const *argv[]){


   if(argv[1] != NULL){
        ifstream inFile;
        string data;
        inFile.open(argv[1]);
        transction.login(data);

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

    ifstream input;
    bool nameExists = 0;
    input.open(filename);




    
    string new_username;
    getline(cin, new_username);

   
    if(input.fail()){
        cout << "Reading of current user file has failed." << endl;
        exit(1);
    }

    while(!input.eof()&&(nameExists == 1)){

        string temp = "";
        getline(input, temp);
	
        transction.login(new_username, temp, nameExists);

        
    }
    
    if(input.eof()&&(nameExists == 0)){
        cout << "User doesnt exist." << endl;
    }

    input.close();
}
