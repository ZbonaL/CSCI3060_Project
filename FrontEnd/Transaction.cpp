/*
This is a program that holds the definitions of the methods and classes defined in Transaction.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <iostream>
#include "User.h" //Includes the declaration of the User class and its methods.
#include "Transaction.h" //Includes the declaration of the Transaction class and its methods.
#include "Ticket.h"
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

string transactionresult = "";

string cmd;
string result;


string currUser;
string existUser;


string eventN;
string sellerN;
int ticketQ;
double ticketPrice;
double transactCredit;

//Print to transaction to daily transaction file.
void printTransaction(string transaction){
	std::ofstream output;
	string filename = "Daily_Transaction_File.txt";
	output.open(filename.c_str(), std::fstream::app);
	if (output.fail()){
		cout << "Reading of daily transaction file has failed." << endl;
	}
	output << transaction+"\n";
	output.close();
}

string formatDouble(double dub){
	string formattedDouble = to_string(dub);
	string formattedString = "";
	//Add decimal places if needed
	int decimalIndex = formattedDouble.find('.');
	if (decimalIndex == std::string::npos){
		formattedDouble += ".00";
	//Remove the extra decimal places if needed
	} else {
		formattedDouble = string(formattedDouble.begin(), formattedDouble.begin() + decimalIndex + 3);
	}
	if (formattedDouble.size() <= 9) {
		formattedString += (string(9 - formattedDouble.size(), '0'));
		formattedString += formattedDouble;
	}
	return formattedString;
}

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
bool checkTicketExists(string ticketname, Ticket &event){
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
				event.EventTitle = string(currentReadName.begin(), currentReadName.begin() + 25);
				event.EventSeller = string(currentReadName.begin() + 26, currentReadName.begin() + 39);
				event.TicketPrice = stod(currentReadName.substr(44,49));
				event.TicketQuantity = stoi(currentReadName.substr(40,42));
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
	string transactionresult = "00";
	printTransaction(transactionresult);
	cout << "Logging out.. have a nice day!" << endl;
	exit(0);
}
void Transaction::logout(User user){
	string usersCredit = formatDouble(user.getCreditAmount());
	string transactionresult = "00 " + user.getUserName() + " " + user.getAccountType() +" "+ usersCredit;
	printTransaction(transactionresult);
	cout << "Logging out.. have a nice day!" << endl;
    exit(0);
}

//Method: create
void Transaction::create(User UserAccount){
	string tranactionresult = "";	
	string adminUserName;
	string newUserName;
	User admin;
	User newUser;
	if(UserAccount.getAccountType() == "AA"){
		cout << "Enter new usersname. " << endl;
		getline(cin, adminUserName);
		if(adminUserName.size() <= 15 && adminUserName.size() >= 0 ){
			if(checkUserExists(newUserName, newUser) == false){
				cout << endl << "Enter new Users name.";
				getline(cin, newUserName);
				if(newUserName.size() <= 15 && newUserName.size() >= 0){
					if(newUserName.size() < 15){

					}
				}else{
					cout << "new username is not valid." << endl;
				}
				
			}else{
				cout << "The user already exists." << endl;
			}
		}else{
			cout << "The Admin name is not valid.";
		}

	}else{
		cout << "Only Admins can create new users." << endl;
	}

}
//Method: deleteUser
// Delete Note: Used deleteUser instead of delete due to delete being a C++ keyword
void Transaction::deleteUser(User adminUser){
    string userToDel;
	string adminAccount;
    User deleteUserCheck;

    if(adminUser.getAccountType() == "AA"){
        cout << "Enter an Account to Delete from the System ";
        getline(cin, userToDel, '\n');
        

	    if(checkUserExists(userToDel, deleteUserCheck) == true){ //Check that the user exists

        if(deleteUserCheck.getUserName() != adminUser.getUserName()){ // Check that user is not the current one
			transactionresult = "02 " + deleteUserCheck.getUserName() + " " + deleteUserCheck.getAccountType() + " " + to_string(deleteUserCheck.getCreditAmount());
			cout << transactionresult << endl;
            }
            else{
                cout << "ERROR: Cannot Delete Yourself" << endl;
                logout();
            }
        }
        else{
            cout << "ERROR: Non-Existing User." << endl;
            logout();    
        }
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
	Ticket event;
	// event.setEventSeller(sellerAccount.getUserName());
while(sellerAccount.getAccountType() != "BS"){ // As long as the user is not BS
    cout << "Enter the Event Title: ";
    getline(cin, eventTitle, '\n');
    
    if ((eventTitle.size() <= 25 ) && (eventTitle.empty() != true)){
		event.setEventTitle(eventTitle);
        cout << "Enter the price for each ticket: ";
        getline(cin, ticketPrice, '\n');

        if(ticketPrice.empty() != true && stod(ticketPrice) <= 999.99){
			event.setEventPrice(stod(ticketPrice));
            cout << "Enter the amount of tickets to sell: ";
            getline(cin, ticketQuantity, '\n');

            if(ticketQuantity.empty() != true && stoi(ticketQuantity) <= 100){
				event.setEventQuantity(stoi(ticketQuantity));
				transactionresult = "04 " + event.getEventTitle() +  " " + event.getEventSeller() + " " + to_string(event.getTicketQuantity()) + " " + to_string(event.getTicketPrice());
                cout << transactionresult << endl;
				cout << "Inputs were all Successful, You can now sell tickets for the event" << endl;
                logout();
            }
            else{
                cout << "ERROR: Either no Input OR Exceeded Maximum Amount of Tickets to Sell." << endl;
                logout();
            }    
        }
        else{
            cout << "ERROR: Either no Input OR Exceeded Maximum Price for Tickets." << endl;
            logout();  
        }
    }
    else{
        cout << "ERROR: Either no Input OR Exceeded Maximum Length for Event Name." << endl;
        logout();
        }  
    }
    cout << "This is a Buy-Standard Account. Please Try Another Transaction" << endl;
}

//Method: buy
void Transaction::buy(User buyerAccount){
    string eventname;
    string sellername;
    string ticketQuantity;
	Ticket event;

    User seller;
    // Ticket event;

while(buyerAccount.getAccountType() != "SS"){
    cout << "Enter the Title of the Event: ";
    getline(cin, eventname, '\n');

    if(eventname.empty() != true && eventname.size() <= 25){

        if(checkTicketExists(eventname, event) == true ){
        	cout << "Enter the Username of the Seller: ";
        	getline(cin, sellername, '\n');

        	if(sellername.empty() != true && sellername.size() <= 15){

//  seller.getUserName() == event.getEventSeller() && 
//&& checkUserExists(sellername, buyerAccount) == false
            	if(checkUserExists(sellername, seller) == true ){
                	cout << "Enter the amount of Tickets: ";
                	getline(cin, ticketQuantity, '\n');
            
                	if((ticketQuantity.empty() != true && stoi(ticketQuantity) <= 4) || (buyerAccount.getAccountType() == "AA" && ticketQuantity.empty() != true)){
						double totalPrice = (stod(ticketQuantity) * event.getTicketPrice());

						if(event.getTicketQuantity() != 0){
							string confirm;
							cout << "Would you like to Continue the Payment?: [Yes/No]";
							getline(cin, confirm, '\n');

							if(confirm == "yes"){	

								if(buyerAccount.getCreditAmount() >= totalPrice){
									double buyercreditR = buyerAccount.getCreditAmount() - totalPrice;
									double sellercredR = seller.getCreditAmount() + (stod(ticketQuantity) * event.getTicketPrice());
									int remainingTickets = event.getTicketQuantity() - stoi(ticketQuantity);
									transactionresult = "04 " + event.getEventTitle() + " " + event.getEventSeller() + " " + to_string(remainingTickets) + " " + to_string(event.getTicketPrice());  
                    				cout << transactionresult << endl;
									printTransaction(transactionresult);
									cout << "Transaction Done" << endl;
                    				logout();
								}
								else{
									cout << "Theres not enough Credit for this purchase." << endl;
									logout();
								}
							}
							else if(confirm == "no"){
							 cout << "Transaction cancelled " << endl;
							
							}
								
						}
						else{
							cout << "No More Tickets. Try Another Event" << endl;
							logout();
						}
                	}
                	else{
                		cout << "ERROR: Either no Input OR Exceeded Maximum Amount of Tickets to Buy." << endl;
                		logout();
                	}
            	}
            	else{
                	cout << "ERROR: Non-Existing User " << endl;
                	logout();
            	}
        	}
        	else{
            	cout << "ERROR: Either no Input OR Exceeded Maximum Length for Seller Name." << endl;
            	logout();
        	}
        }
		else{
         cout << "Non-Exsting Event" << endl;
         logout();
        }
    }
    else{
        cout << "ERROR: Either no Input OR Exceeded Maximum Length for Event Name." << endl;
        logout();
        }
    }
    cout << "This is a Sell-Standard Account. Please Try Another Transaction" << endl;
}

//Method: refund
void Transaction::refund(User UserAccount){
	string buyerName; //Will become User objects in future.
	string sellerName; //Will become User objects in future.
	string creditTransfer; //String version of inputted credits (Is a string for getline() to work effectively.)
	double credit;	//Double version of inputted credits
	bool validCredit = false; //Flag used for checking
	User buyer;	
	User seller;
	if (UserAccount.getAccountType() == "AA") {
		//Continue refund.
		//Prompt user for buyer username
		cout << "Please enter the buyers username: ";
		getline(cin, buyerName);
		if (buyerName.size() <= 15 && buyerName.size() >= 0){
			//Continue Transaction
			if (checkUserExists(buyerName, buyer) == true){
				//Prompt user for seller username
				cout << endl;
				cout << "Please enter the sellers username: ";
				getline(cin, sellerName);
				if (sellerName.size() <= 15 && sellerName.size() >= 0){
					//Continue Transaction
					if (checkUserExists(sellerName, seller) == true){
						//Prompt user for amount of credit
						cout << endl;
						cout << "Please enter the credit to refund: ";
						getline(cin, creditTransfer);
						try {	//Try to convert string to double
  							credit = stod(creditTransfer); 
							validCredit = true;
 						}
  						catch (const std::invalid_argument& ia) { // Catch error and end transaction if fail
  						}
						if (credit >= 0.00 && credit <= 999999.99 && validCredit == true){
							if (credit <= seller.getCreditAmount()){
								if ((buyer.getCreditAmount() + credit) <= 999999.99){
									//HERE THE REFUND ACTUALLY TAKES PLACE
									buyer.setCredit(buyer.getCreditAmount() + credit);
									seller.setCredit(seller.getCreditAmount() - credit);
									//TODO: Write transaction to Daily Transaction file.
									creditTransfer = formatDouble(credit);
									transactionresult = "05 " + buyer.getUserName() + " " + seller.getUserName() +" "+ creditTransfer;
									printTransaction(transactionresult);
									cout << "TRANSACTION COMPLETE!" << endl;
								} else {
									//End transaction if amount of credit cannot be added to buyers account.
									cout << "The buyer exceeds maximum allowed credit after transaction." << endl << "Ending transaction.." << endl;
								}
							} else {
								//End transaction if amount of credit cannot be removed from sellers account.
								cout << "The seller has insufficient credit to be transfered." << endl << "Ending transaction.." << endl;
							}
						} else {
							//End transaction if invalid amount of credit entered
							cout << "The credit you have entered is invalid, please enter a number from 0 to 999999.99" << endl;
						}
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
void Transaction::addCredit(User user){
	string inputAccount;
	string creditTransfer;
	double credit;
	User recieverAccount;
	bool validCredit = false;
	string transactionresult;
	

	if (user.getAccountType() == "AA"){
		cout << "Admin user detected." << endl;
		cout << "Please enter the username of the account to add credit too: ";
		getline(cin, inputAccount);
		if (inputAccount.size() <= 15 && inputAccount.size() >= 0){
			if (checkUserExists(inputAccount, recieverAccount) == true) {
				//Prompt user for credit to be entered.
				cout << "Enter how much credit to add to the account: ";
				getline(cin, creditTransfer);
				cout << endl;
				try {	//Try to convert string to double
  					credit = stod(creditTransfer); 
					validCredit = true;
 				}
  					catch (const std::invalid_argument& ia) { // Catch error and end transaction if fail
  				}
				if (credit >= 0.00 && credit <= 1000.00 && validCredit == true){
					if ((credit + recieverAccount.getCreditAmount()) < 999999.99){
						//ADDCREDIT transaction functions here for admin users.
						recieverAccount.setCredit(recieverAccount.getCreditAmount() + credit);
						creditTransfer = formatDouble(user.getCreditAmount());
						transactionresult = "06 " + user.getUserName() + " " + user.getAccountType() + " " + creditTransfer;
						printTransaction(transactionresult);
						cout << "TRANSACTION COMPLETE!" << endl;
					} else {
						//End transaction if amount of credit cannot be added to buyers account.
						cout << "reciever account has too much credit to transfer this much" << endl;
					}
				
				} else {
					//End transaction if invalid credit entered.
				}
				//TODO: Check if maximum credits not reached on reciever
			} else {
				//End transaction if buyer name is not valid	
				cout << "Account entered is not valid, exiting transaction." << endl;
			}
		} else {
			//End transaction if buyer name is invalid format
			cout << "Invalid format, exiting transaction." << endl;
		}
		
	} else {
		//Continue transaction as a non admin.
		//TODO: Check if sufficient credits to be transfered.
		//TODO: Check if maximum credits not reached on reciever
		cout << "Enter how much credit to add to your account: ";
		getline(cin, creditTransfer);
		cout << endl;
		try {	//Try to convert string to double
  			credit = stod(creditTransfer); 
			validCredit = true;
 		}
 		catch (const std::invalid_argument& ia) { // Catch error and end transaction if fail
  		}
		if (credit >= 0.00 && credit <= 1000.00 && validCredit == true){
			if ((credit + recieverAccount.getCreditAmount()) < 999999.99){
				//ADDCREDIT transaction functions here for non admin users
				recieverAccount.setCredit(recieverAccount.getCreditAmount() + credit);
				creditTransfer = formatDouble(user.getCreditAmount());
				transactionresult = "06 " + user.getUserName() + " " + user.getAccountType() + " " + creditTransfer;
				printTransaction(transactionresult);
				cout << "TRANSACTION COMPLETE!" << endl;
			} else {
				//End transaction if amount of credit cannot be added to buyers account.
				cout << "Reciever account has too much credit to transfer this much." << endl;
			}
				
		} else {
			//End transaction if invalid credit entered.
			cout << "The amount of credit you have entered is invalid. (Can only transfer up to 1000 credits)" << endl;
		}
	}
	
}