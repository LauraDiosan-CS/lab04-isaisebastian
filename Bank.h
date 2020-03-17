#pragma once
#include <iostream>

class Bank {
private:
	char* type;
public:
	Bank();
	Bank(char* type);
	Bank(const Bank& b);
	~Bank();
	char* getType();
	void setType(char* type);
};