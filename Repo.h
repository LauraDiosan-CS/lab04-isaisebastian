#pragma once
#include "Bank.h"

class Repo {
private:
	Bank banks[50];
	int nr;
public:
	Repo();
	~Repo();
	void addElem(Bank b);
	Bank* getAll();
	int getSize();
};