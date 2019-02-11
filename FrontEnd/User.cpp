#include "User.h"
#include <string>

using std::string;

// user constructor
User::User(string UserName, string accountType, double creditAmount){
    this->UserName = UserName;
    this->accountType = accountType;
    this->creditAmount = creditAmount;
}

string User::getUserName(){ return UserName; }
string User::getAccountType(){ return accountType; }
double User::getCreditAmount(){ return creditAmount; }
void User::setCredit(double credit){ creditAmount = credit; }