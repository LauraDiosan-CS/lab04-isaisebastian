#pragma once
#include "Repo.h"

class Service {
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);
	~Service();

	void setRepo(Repo repo);
	void addBank(int day, int amount_money, const char* type, const char* description);
	vector<Bank> getAll();
	Bank getBankAtPosition(size_t pos);
	void deleteBank(size_t pos);
	void updateBankByDescription(const char* description, int newDay, int newMoney, const char* newType, const char* newDescription);

};