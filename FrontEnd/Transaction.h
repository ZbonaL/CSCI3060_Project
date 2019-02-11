#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction{

	public:
		Transaction();
		void login(std::string UserName, std::string temp, bool nameExists);
		void logout();
		void buy();
		void sell();
		void create();
		void deleteUser();
		void refund();
		void addCredit();
};
#endif