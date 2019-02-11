#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Transaction.h"
#include "Ticket.h"


using namespace std;

void dailyTransaction(string filename);
void readCurrentUser(string filename);
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

    cout << new_username << endl;

   
    if(input.fail()){
        cout << "Reading of current user file has failed." << endl;
        exit(1);
    }

    while(!input.eof()){

        string temp = "";
        getline(input, temp);

        
        for(int i = 0; i < new_username.size(); i++){
            if (temp[i] == new_username[i]){
                nameExists =1;
            }else{
                nameExists = 0;
                break;
            }
        }
        
        if(nameExists){
			cout << "Welcome User: " << new_username << endl;
			break;
		}
    }
    
    if(input.eof()&&(nameExists == 0)){
        cout << "User doesnt exist." << endl;
    }

    input.close();
}
