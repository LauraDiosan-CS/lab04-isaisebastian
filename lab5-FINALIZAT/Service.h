#pragma once
#include "Repo.h"

class Service {
private:
	Repo repo;
	vector<Repo> undo;
public:
	Service();
	Service(Repo& repo);
	~Service();

	void setRepo(Repo repo);
	void addBank(int day, int amount_money, const char* type, const char* description);
	void deleteBank(Bank& b);
	void updateBankByDescription(const char* description, int newDay, int newMoney, const char* newType, const char* newDescription);
	vector<Bank> getAll();
	
	int soldBank(int givenDay);
	void totalSum(char* giventype);
	void maxBank(int day, char* type);
	void undo_operation();


};