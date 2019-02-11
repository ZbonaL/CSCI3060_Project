#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction{

	public:
		Transaction();
		void login(std::string UserName);
		void logout();
		void buy();
		void sell();
		void create();
		void deleteUser();
		void refund();
		void addCredit();
};
#endif