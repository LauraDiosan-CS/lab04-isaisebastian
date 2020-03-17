#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank() {
	this->type = NULL;
}

Bank::Bank(char* type)
{
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, 1 + strlen(type), type);
}

Bank::Bank(const Bank& b) {
	this->type = new char[strlen(b.type) + 1];
	strcpy_s(type, 1 + strlen(b.type), b.type);
}

Bank::~Bank() {
	if (type) {
		delete[] type;
		type = NULL;
	}
}

char* Bank::getType() {
	return this->type;
}

void Bank::setType(char* type)
{
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}