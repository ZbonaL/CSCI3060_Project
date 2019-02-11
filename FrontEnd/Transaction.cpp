#include <iostream>
#include "User.h"
#include "Transaction.h"
#include <string>
#include <fstream>


using std::string;
using std::cout;
using std::cin;
using std::endl;

Transaction::Transaction(){

}

//Transaction Methods 
// Login #TODO
void Transaction::login(string UserName, string temp, bool nameExists){
    
    bool nameExists = 0;
    int counter = 0;
	int addOn = 14 - UserName.size();
	for(int i = 0; i < addOn; i++){
		UserName = UserName + " "
	}
	for(int i = 0; i < UserName.size(); i++){
        if (UserName[i] == temp[i]){
			counter++;
		}
        if (counter == (UserName.size() - 1)){
			nameExists = 1;
		}
        if(nameExists){
        	cout << "Welcome User: " << UserName << endl;
			break;
		}
  	}
}

// Logout #TODO
void logout(){
    string filename;
    string output;
    
    std::ofstream file;
    file.open(filename);
    file << output;
    file.close();
    exit(0);
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