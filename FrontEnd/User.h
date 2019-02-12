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

  private:
  	double creditAmount;

  public:
    std::string UserName;
 	std::string accountType;
	
	//Method Name: User
	//Purpose: Constructs the User object.
    User(std::string UserName, std::string accountType, double creditAmount);
	
	//Method Name: getUserName
	//Purpose: Returns the UserName of the User object.
	std::string getUserName();

	//Method Name: getAccountType
	//Purpose: Returns the accountType of the User object.
    std::string getAccountType();
	
	//Method Name: getCreditAmount
	//Purpose: Returns the creditAmount of the User object.
    double getCreditAmount();

	//Method Name: setCredit
	//Purpose: Used for altering the value of credit.
	void setCredit(double credit);
};
#endif