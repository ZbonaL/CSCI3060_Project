/*
This is a header file which defines the User class, and declares all classes and methods.

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <string>
#ifndef USER_H_	//If a User.h header file is not already included:
#define USER_H_ //Include the User.h class

/*
Class name: User
Description: A User class for creating User objects for our ticket selling program.
			 Users have public instance variables: UserName (string), accountType (string). And 
			 private instance variables: creditAmount (double).
*/
class User{

  public:
    std::string UserName;
 	std::string accountType;
 	double creditAmount;
	
/* 
	This function is called when a User object is created
	@params: string UserName: the name of the User
			 string accountType: the privelege level of the user..
			 double creditAmount: the credit available on users account.
	@returns: Constructs the User object.

*/
	User();
    User(std::string UserName, std::string accountType, double creditAmount);
	
/* 
	This function is for getting the username from the User.
	@params: None
	@returns: The username on the User object
*/
	std::string getUserName();

/* 
	This function is for getting the account type from the user
	@params: None
	@returns: The account type on the User object
*/
    std::string getAccountType();
	
/* 
	This function is for getting the amount of credit on the users account.
	@params: None
	@returns: The credit amount on the User object

*/
    double getCreditAmount();

/* 
	This function is for changing the amount of credit on the users account.
	@params: double credit: the amount of credit to change to.
	@returns: Sets the new amount of credit.

*/
	void setCredit(double credit);
};
#endif