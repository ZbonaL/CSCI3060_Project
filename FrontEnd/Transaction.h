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

		//Method Name: Transaction
		//Purpose: Constructs the Transaction object.
		Transaction();

		//Method Name: login
		//Purpose: Compares the inputted UserName to the usernames in the Users file to check if it exists.
		void login(std::string UserName, std::string temp, bool nameExists);

		//Method Name: logout
		//Purpose: Acts as an ideal exit to the program, writes the recorded transactions to the output file.
		void logout();
	
		//Method Name: buy
		//Purpose: Purchases a number of available tickets and transfers credit from the buying user to the selling user.
		void buy(std::string eventname, std::string sellername, int ticketQuantity);
		
		//Method Name: sell
		//Purpose: Sells a number of tickets and writes them to the tickets file to be available for purchase.
		void sell(std::string eventTitle, int ticketQuantity, double ticketPrice);

		//Method Name: create
		//Purpose: Creates a User class, and issues them a privelege. Then saves this to the current user input file. 
		void create(std::string userName, std::string accountType, double credit);
	
		//Method Name: deleteUser
		//Purpose: Cancels any outstanding tickets for purchase or sale of a user and removes that user account.
		void deleteUser(std::string userName);

		//Method Name: refund
		//Purpose: Issues a credit from the buyers account to the sellers account.
		void refund(std::string userNameBuy, std::string userNameSell, double creditAmount);

		//Method Name: addCredit
		//Purpose: Adds credit to a users own account or as an admin adds credit to a different user account
		void addCredit(double creditAmount, std::string userName);
};
#endif // Ends the ifndef condition