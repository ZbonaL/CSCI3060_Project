#include <string>

using namespace std;

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
}