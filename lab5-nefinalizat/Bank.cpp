#include "Bank.h"
#include <iostream>
#include <ostream>
#include <cstddef>

using namespace std;

Bank::Bank() {
	this->day = 0;
	this->amount_money = 0;
	this->type = NULL;
	this->description = NULL;
}

Bank::Bank(int day, int amount_money, const char* type, const char* description) {
	this->day = day;
	this->amount_money = amount_money;

	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);

}

Bank::Bank(const Bank& b) {
	this->day = b.day;
	this->amount_money = b.amount_money;
	
	this->type = new char[strlen(b.type) + 1];
	strcpy_s(this->type, strlen(b.type) + 1, b.type);
	this->description = new char[strlen(b.description) + 1];
	strcpy_s(this->description, strlen(b.description) + 1, b.description);
}

int Bank::getDay() {
	return this->day;
}

int Bank::getMoney() {
	return this->amount_money;
}

char* Bank::getType() {
	return this->type;
}

char* Bank::getDescription() {
	return this->description;
}

void Bank::setDay(int day) {
	this->day = day;
}

void Bank::setMoney(int amount_money) {
	this->amount_money = amount_money;
}

void Bank::setType(const char* type) {
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

void Bank::setDescription(const char* description) {
	if (this->description) {
		delete[] this->description;
	}
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);

}

Bank& Bank::operator=(const Bank& b) {
	this->setDay(b.day);
	this->setMoney(b.amount_money);
	this->setType(b.type);
	this->setDescription(b.description);
	return *this;
}

bool Bank::operator==(const Bank& b) {
	return this->day == b.day && this->amount_money == b.amount_money && strcmp(this->type, b.type) == 0 && strcmp(this->description, b.description) == 0;
}

Bank::~Bank() {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
	if (this->description) {
		delete[] this->description;
		this->description = NULL;
	}
}

ostream& operator<<(ostream& os, Bank& b) {
	os << b.day << " " << b.amount_money << " " << b.type << " " << b.description << endl;
	return os;
}

