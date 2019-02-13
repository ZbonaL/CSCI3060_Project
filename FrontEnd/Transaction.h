/*
This is a header file which defines the Transaction class, and declares all classes and methods used by Transaction objects.

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#ifndef TRANSACTION_H_ //If a Transaction.h header file is not already included:
#define TRANSACTION_H_ //Include the Transaction.h class

/*
Class name: Transaction
Description: A Transaction class for creating Transaction objects for our ticket selling program.
*/
class Transaction{

	public:

/* 
	This function is called when a Transaction object is created
	@params: None
	@returns: Constructs the Transaction object.

*/
		Transaction();

/* 
	This function is called when a User is logging in.
	@params: string UserName: the name of the User
			 string temp: the current iteration of the username from the file
			 bool nameExists: a boolean checking if UserName is valid.
	@returns: Sends a welcome message to the user if username is valid

*/
		void login(std::string UserName, std::string temp, bool nameExists);

/* 
	This function logs the user out
	@params: None
	@returns: Logs the user out of the program.
*/
		void logout();
	
/* 
	This function is called when a buy transaction is issued
	@params: string eventname: the name of the event
			 string sellername: the name of the seller
			 int ticketQuantity: the credit available on users account.
	@returns: Buys a ticket for the user

*/
		void buy(std::string eventname, std::string sellername, int ticketQuantity);
		
/* 
	This function is called when a sell transaction is issued
	@params: string eventTitle: the name of the event
			 int ticketQuantity: the number of tickets available
			 double ticketPrice: the price of a ticket
	@returns: Sells a ticket for the user.

*/
		void sell(std::string eventTitle, int ticketQuantity, double ticketPrice);

/* 
	This function is called when a User is being created
	@params: string userName: the name of the User being created
			 string accountType: the privelege level of the user being created
			 double credit: the credit to be available on users account.
	@returns: Constructs a user object, and writes it to the current user file
*/ 
		void create(std::string userName, std::string accountType, double credit);
	
/* 
	This function is called when a User is being deleted
	@params: string userName: the name of the User being deleted
	@returns: Deletes the user object possessing the usernames.
*/
		void deleteUser(std::string userName);

/* 
	This function is called when a refund transaction is issued.
	@params: string userNameBuy: the name of the buyer
			 string userNameSell: the name of the seller
			 double creditAmount: the credit being refunded.
	@returns: An amount of the seller accounts credit is sent to the buyer accounts credit
*/
		void refund(std::string userNameBuy, std::string userNameSell, double creditAmount);

/* 
	This function is called when a User object is created
	@params: double creditAmount: the credit to add to the users account. (Self or chosen user if admin)
			 string userName: the name of the User being given credit (USED FOR ADMIN ONLY)
	@returns: Constructs the User object.
*/
		void addCredit(double creditAmount, std::string userName);
};
#endif // Ends the ifndef condition