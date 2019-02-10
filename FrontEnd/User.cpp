#include <User.h>
#include <string>

using std::string;

// user constructor
User::User(string username, string accountType, double creditAmount){
    SetUser(username, accountType, creditAmount);
}

void User::SetUser(string username,string accountType, double creditAmmount){
    username = username;
    accountType = accountType;
    creditAmount = creditAmmount;
}