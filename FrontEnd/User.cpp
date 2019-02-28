/*
This is a program that holds the definitions of the methods and classes defined in User.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include "User.h" //Includes the declaration of the User class and its methods.
#include <string>

using std::string;

//Method: User (basic constructor)
User::User(){}

//Method: User (with params)
User::User(string UserName, string accountType, double creditAmount){
	//"this" refers to the instance of the duplicate variables belonging to the Object
    this->UserName = UserName;
    this->accountType = accountType;
    this->creditAmount = creditAmount;
}

//Method: getUserName
string User::getUserName(){ return UserName; }

//Method: getAccountType
string User::getAccountType(){ return accountType; }

//Method: getCreditAmount
double User::getCreditAmount(){ return creditAmount; }

//Method: setCredit
void User::setCredit(double credit){ creditAmount = credit; }