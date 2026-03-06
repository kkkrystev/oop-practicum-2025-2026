#include <iostream>
#include <cstring>

const int MAX_NAME_LENGTH = 50;
const int IBAN_LENGTH = 22;
const double INITIAL_BALANCE = 0;
const double DEFAULT_WITHDRAWAL_LIMIT = 500;
const int MAX_BANK_ACCOUNTS = 100;

class BankAccount {
	char clientName[MAX_NAME_LENGTH + 1];
	char IBAN[IBAN_LENGTH + 1];
	double balance;
	double withdrawalLimit;

public:
	BankAccount()
		: balance(INITIAL_BALANCE), withdrawalLimit(DEFAULT_WITHDRAWAL_LIMIT) {
		clientName[0] = '\0';
		IBAN[0] = '\0';
	}

	BankAccount(const char* clientName, const char* IBAN)
		: balance(INITIAL_BALANCE), withdrawalLimit(DEFAULT_WITHDRAWAL_LIMIT) {

		strcpy_s(this->clientName, MAX_NAME_LENGTH + 1, clientName);
		strcpy_s(this->IBAN, IBAN_LENGTH + 1, IBAN);
	}

	void deposit(double amount) {
		if (amount <= 0)
			return;

		balance += amount;
	}

	bool withdraw(double amount) {
		if (amount <= 0 || amount > balance || amount > withdrawalLimit)
			return false;

		balance -= amount;
		return true;
	}

	void setWithdrawalLimit(double limit) {
		if (limit < 0)
			return;

		withdrawalLimit = limit;
	}

	const char* getName() const {
		return clientName;
	}

	const char* getIBAN() const {
		return IBAN;
	}

	double getBalance() const {
		return balance;
	}

	void print() const {
		std::cout << clientName
			<< " | IBAN: " << IBAN
			<< " | Balance: " << balance;
	}
};

class Bank {
	char bankName[MAX_NAME_LENGTH + 1];
	BankAccount accounts[MAX_BANK_ACCOUNTS];
	int accountCount;

public:
	Bank(const char* name) : accountCount(0) {
		strcpy_s(bankName, MAX_NAME_LENGTH + 1, name);
	}

	bool addAccount(const BankAccount& newAccount) {
		if (accountCount >= MAX_BANK_ACCOUNTS)
			return false;

		accounts[accountCount++] = newAccount;
		return true;
	}

	bool removeAccount(const char* iban) {
		for (int i = 0; i < accountCount; i++) {
			if (strcmp(accounts[i].getIBAN(), iban) == 0) {

				for (int j = i; j < accountCount - 1; j++) {
					accounts[j] = accounts[j + 1];
				}

				accountCount--;
				return true;
			}
		}
		return false;
	}

	double getBalanceByIBAN(const char* iban) const {
		for (int i = 0; i < accountCount; i++) {
			if (strcmp(accounts[i].getIBAN(), iban) == 0)
				return accounts[i].getBalance();
		}
		return -1;
	}

	double getTotalBalanceForClient(const char* name) const {
		double total = 0;
		bool clientExists = false;

		for (int i = 0; i < accountCount; i++) {
			if (strcmp(accounts[i].getName(), name) == 0) {
				clientExists = true;
				total += accounts[i].getBalance();
			}
		}

		return clientExists ? total : -1;
	}

	void printAllAccounts() const {
		std::cout << "--- Bank: " << bankName << " Accounts ---" << std::endl;

		for (int i = 0; i < accountCount; i++) {
			accounts[i].print();
			std::cout << std::endl;
		}
	}
};