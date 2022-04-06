class Account {
private:
	const int bankAccountNumber;
	char * name;
	int balance;

public:
	Account(int bankAccountNumber, const char* name, int balance);
	
	int Deposit(int money);

	int Withdraw(int money);

	void ShowAccountInfo() const;

	int GetBankAccountNumber();

	~Account();
};