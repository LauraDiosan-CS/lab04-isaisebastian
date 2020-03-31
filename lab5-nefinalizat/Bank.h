#pragma once
#include <iostream>
using namespace std;

class Bank {
private:
	int day; int amount_money;
	char* type; char* description;
public:
	Bank();
	Bank(int day, int amount_money, const char* type, const char* description);
	Bank(const Bank& b);
	Bank& operator=(const Bank& b);
	~Bank();
	int getDay();
	int getMoney();
	char* getType();
	char* getDescription();

	void setDay(int day);
	void setMoney(int amount_money);
	void setType(const char* type);
	void setDescription(const char* description);

	bool operator==(const Bank& b);

	friend ostream& operator<<(ostream& os, Bank& b);

};