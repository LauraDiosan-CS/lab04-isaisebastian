#pragma once
#include <vector>
#include "Repo.h"

class TestRepo {
private:
	Repo repo;
	vector<Bank> banksIn;
	const char* in_f = "Test_in_f.txt";
	const char* out_f = "Test_out_f.txt";

	void testloadfromfile();
	void testsavetofile();
	void testGetSize();
	void testGetAll();
	void testAddElem();
	void testUpdateElem();
	void testDeleteElem();
	void testBankAtPosition();
public:
	TestRepo();
	void testAll();

};