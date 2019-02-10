#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Transaction.h"
#include "Ticket.h"


using namespace std;

void dailyTransaction(string filename);
void readCurrentUser(string filename, string username);
void readTicketFile(string filename, string eventName);

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
        cout << "Please enter your username: " << endl;

        string new_username;
        cin >> new_username;
        readCurrentUser("Current_User_Accounts_File.txt", new_username);
    }

   return 0;
}

void readCurrentUser(string filename, string username){

    ifstream input;
    bool nameExists = 0;
    input.open(filename);
    
    if(input.fail()){
        cout << "Reading of current user file has failed." << endl;
        exit(1);
    }

    while(!input.eof()){
        string temp = "";
        getline(input, temp);

        for(int i = 0; i < username.size(); i++){
            if (temp[i] == username[i]){
                nameExists =1;
            }else{
                nameExists = 0;
                break;
            }
        }
        
        if(nameExists){
			cout << "Welcome User: " << username << endl;
			break;
		}
    }
    
    if(input.eof()&&(nameExists == 0)){
        cout << "User doesnt exist." << endl;
    }

    input.close();
}
