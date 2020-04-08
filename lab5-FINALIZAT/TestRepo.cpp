#include "TestRepo.h"
#include <assert.h>

TestRepo::TestRepo()
{
	Bank b1(1, 200, "in", "pizza");
	Bank b2(2, 300, "in", "btpay");
	Bank b3(3, 400, "out", "tranzactie");
	Bank b4(4, 500, "out", "kfc");
	this->banksIn.push_back(b1);
	this->banksIn.push_back(b2);
	this->banksIn.push_back(b3);
	this->banksIn.push_back(b4);
}

void TestRepo::testAll()
{
	this->testloadfromfile();
	this->testsavetofile();
	this->testDeleteElem();
	this->testAddElem();
	this->testGetSize();
}

void TestRepo::testloadfromfile()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == 4);
}

void TestRepo::testsavetofile()
{
	this->repo.set_in_f(this->in_f);
	this->repo.set_out_f(this->out_f);
	this->repo.loadfromfile();
	int len = this->repo.getSize();
	Bank newBank(6, 600, "in", "descriere");
	this->repo.addElem(newBank);
	this->repo.savetofile();
	this->repo.set_in_f(this->out_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == len + 1);
}

void TestRepo::testGetAll()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	vector<Bank> banksIn = this->repo.getAll();
	for (int i = 0; i < this->repo.getSize(); i++)
		assert(banksIn[i] == this->banksIn[i]);
}

void TestRepo::testAddElem()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	int len = this->repo.getSize();
	Bank b(7, 700, "out", "description");
	this->repo.addElem(b);
	assert(this->repo.getSize() == len + 1);
}

void TestRepo::testUpdateElem()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	Bank b(8, 800, "out", "pizza");
	this->repo.updateElem(b, b);
	for (int i = 0; i < this->repo.getSize(); i++) {
		assert(banksIn[i] == this->banksIn[i]);
	}
}

void TestRepo::testDeleteElem()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	int len = this->repo.getSize();
	Bank b(9, 900, "in", "h&m");
	this->repo.addElem(b);
	this->repo.deleteElem(b);
	assert(this->repo.getSize() == len);

}

void TestRepo::testGetSize()
{
	this->repo.set_in_f(this->in_f);
	this->repo.loadfromfile();
	assert(this->repo.getSize() == 4);
}
