#include <string>
#ifndef USER_H_
#define USER_H_

class User{

  private:
  	double creditAmount;

  public:
    std::string UserName;
 	std::string accountType;
    User(std::string UserName, std::string accountType, double creditAmount);
	std::string getUserName();
    std::string getAccountType();
    double getCreditAmount();
	void setCredit(double credit);
};
#endif