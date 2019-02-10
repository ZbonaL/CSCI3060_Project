#include <User.h>
#include <string>

using namespace std;

// user constructor
User::User(string username, string accountType, double creditAmount){
    SetUser(username, accountType, creditAmount);
}

void User::SetUser(string username, string accountType, double creditAmmount){
    new_username = username;
    new_accountType = accountType;
    new_creditAmount = creditAmmount;
}