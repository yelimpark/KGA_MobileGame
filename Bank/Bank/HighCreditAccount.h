#pragma once
#include "NormalAccount.h"

enum class CRADIT_LEVEL {
	A = 7,
	B = 4,
	C = 2
};

class HighCreditAccount : public NormalAccount {
private:
	CRADIT_LEVEL cradit;

public:
	HighCreditAccount(int bankAccountNumber, const char* name, int balance, int interest, CRADIT_LEVEL cradit);

	HighCreditAccount(int bankAccountNumber, my::string name, int balance, int interest, CRADIT_LEVEL cradit);

	HighCreditAccount operator=(const HighCreditAccount& ref);

	virtual void Deposit(int money);

	virtual void ShowAccountInfo() const;

	virtual ~HighCreditAccount();
};