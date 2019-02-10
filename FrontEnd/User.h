#include <string>

using std::string;

class User{

  private:
  string username;
  string accountType;
  double creditAmount;

  public:
    User(string username, string accountType, double creditAmount);

    void SetUser(string username, string accountType, double creditAmount);
    
    string getUserName(){ return username; }
    string getAccountType(){ return accountType; }
    double getCreditAmount(){ return creditAmount; }
};