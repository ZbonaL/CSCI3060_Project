#include <string>
#ifndef USER_H_
#define USER_H_

class User{

  private:
  	double creditAmount;

  public:
    std::string username;
 	std::string accountType;
    User(string username, string accountType, double creditAmount);
	string getUserName();
    string getAccountType();
    double getCreditAmount();
	void setCredit(double credit);
};
#endif