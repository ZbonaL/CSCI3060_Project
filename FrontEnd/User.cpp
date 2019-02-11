#include <User.h>
#include <string>

using std::string;

// user constructor
User::User(string username, string accountType, double creditAmount){
    this->username = username;
    this->accountType = accountType;
    this->creditAmount = creditAmount;
}

string User::getUserName(){ return username; }
string User::getAccountType(){ return accountType; }
double User::getCreditAmount(){ return creditAmount; }
void User:setCredit(double credit){ creditAmount = credit; }