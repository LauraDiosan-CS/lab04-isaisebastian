#include "TestRepo.h"
#include <assert.h>

TestRepo::TestRepo() {
	Bank b1(1, 20, "in", "descriere");
	Bank b2(2, 30, "in", "descriere1");
	Bank b3(3, 40, "out", "descriere2");
	Bank b4(4, 50, "out", "descriere4");
}

void TestRepo::testAll() {
	this->testAddElem();
	this->testBankAtPosition();
	this->testDeleteElem();
	this->testGetAll();
	this->testGetSize();
	this->testloadfromfile();
	this->testsavetofile();
	this->testUpdateElem();
}

void TestRepo::testloadfromfile()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == 6);
	vector<Bank> banksIn = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		assert(banksIn[i] == this->banksIn[i]);
	}
}

void TestRepo::testsavetofile() {
	this->repo.set_in_f(this->in_f);
	this->repo.set_out_f(this->out_f);
	int len = this->repo.getSize();
	Bank newBank(5, 60, "out", "newbank");
	this->repo.addElem(newBank);
	this->repo.savetofile();
	this->repo.set_in_f(this->out_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == len + 1);
	vector<Bank> banksIn = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		assert(banksIn[i] == this->banksIn[i]);
	}
	assert(banksIn[len] == newBank);
}

void TestRepo::testGetSize()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == 6);
}

void TestRepo::testGetAll()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	vector<Bank> banksIn = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(banksIn[i] == this->banksIn[i]);
	}
}

void TestRepo::testBankAtPosition()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(this->repo.getBankAtPosition(i) == this->banksIn[i]);
	}
	Bank emptyBank(0, 0, "", "");
	assert(this->repo.getBankAtPosition(-2) == emptyBank);
	assert(this->repo.getBankAtPosition(this->repo.getSize()) == emptyBank);
}

void TestRepo::testAddElem() {
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	int len = this->repo.getSize();
	Bank b(20, 20, "in", "tranzactie");
	this->repo.addElem(b);
	assert(this->repo.getSize() == len + 1);
	assert(this->repo.getBankAtPosition(len) == b);
}

void TestRepo::testUpdateElem() {
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	Bank b(21, 300, "in", "descriere tranzactie");
	this->repo.updateElem(b, b);
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(banksIn[i] == this->banksIn[i]);
	}
	this->repo.updateElem(this->banksIn[1], b);
	assert(this->repo.getBankAtPosition(1) == b);
}

void TestRepo::testDeleteElem() {
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	int len = this->repo.getSize();
	Bank b3(25, 25, "out", "desc");
	this->repo.deleteElem(b3);
	assert(this->repo.getSize() == len);
	this->repo.deleteElem(this->banksIn[2]);
	assert(this->repo.getSize() == len - 1);
}