#pragma once
#include "Bank.h"
#include <vector>

class Repo {
private: 
	vector<Bank> elem;
	char* in_f;
	char* out_f;
public:
	Repo();
	Repo(const char* in_f, const char* out_f);
	void set_in_f(const char* in_f);
	void set_out_f(const char* out_f);
	void addElem(Bank b);
	vector<Bank> getAll();

	int getSize();
	Bank getBankAtPosition(size_t pos);
	void updateElem(Bank& oldBank, Bank& newBank);
	void deleteElem(Bank& b);
	void loadfromfile();
	void savetofile();
	~Repo();
};