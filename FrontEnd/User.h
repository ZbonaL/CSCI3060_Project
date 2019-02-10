#include <string>

using namespace std;

class User{

  private:
  string new_username;
  string new_accountType;
  double new_creditAmount;

  public:
    User(string username, string accountType, double creditAmount);

    void SetUser(string username, string accountType, double creditAmount);
    
    string getUserName(){ return new_username; }
    string getAccountType(){ return new_accountType; }
    double getCreditAmount(){ return new_creditAmount; }
}