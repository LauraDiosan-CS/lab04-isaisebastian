#include "TestService.h"
#include <assert.h>

TestService::TestService()
{

}

void TestService::testAll() {
	this->testAddBank();
	this->testDeleteBank();
	this->testGetBankAtPosition();
	this->testGetAll();
	this->testUpdateBankByDescription();
}

void TestService::testAddBank() {
	Repo repo;
	this->service.setRepo(repo);
	char type[] = "in";
	char description[] = "descriere";
	Bank b(2, 20, type, description);
	this->service.addBank(2, 20, type, description);
	assert(this->service.getBankAtPosition(0) == b);
}

void TestService::testGetAll() {
	Repo repo;
	this->service.setRepo(repo);
	char type1[] = "in";
	char type2[] = "out";
	char description1[] = "pizza";
	Bank b1(1, 200, type1, description1);
	Bank b2(2, 300, type2, description1);
	this->service.addBank(1, 200, type1, description1);
	this->service.addBank(2, 300, type2, description1);
	vector<Bank> banks = this->service.getAll();
	assert(banks.size() == 2);
	assert(banks[0] == b1);
	assert(banks[1] == b2);

}

void TestService::testGetBankAtPosition()
{
	Repo repo;
	this->service.setRepo(repo);
	char type1[] = "out";
	char description1[] = "descrierea tranzactiei";
	Bank b(1, 200, type1, description1);
	this->service.addBank(1, 200, type1, description1);
	assert(this->service.getBankAtPosition(0) == b);
	char emptyType[] = "";
	char emptyDescription[] = "";
	Bank emptyBank(0, 0, emptyType, emptyDescription);
	assert(this->service.getBankAtPosition(-1) == emptyBank);
	assert(this->service.getBankAtPosition(1) == emptyBank);
}

void TestService::testUpdateBankByDescription()
{
	Repo repo;
	this->service.setRepo(repo);
	char type1[] = "in";
	char type2[] = "out";
	char description[] = "descriere";
	char description2[] = "descriere2";
	Bank b1(1, 200, type1, description);
	Bank b2(2, 300, type2, description2);
	this->service.addBank(1, 200, type2, description);
	this->service.updateBankByDescription("description", b2.getDay(), b2.getMoney(), b2.getType(), b2.getDescription());
	assert(this->service.getBankAtPosition(0) == b1);
	this->service.updateBankByDescription(description, b2.getDay(), b2.getMoney(), b2.getType(), b2.getDescription());
	assert(this->service.getBankAtPosition(0) == b2);


}

void TestService::testDeleteBank()
{
	Repo repo;
	this->service.setRepo(repo);
	char type1[] = "in";
	char type2[] = "out";
	char description[] = "descriere";
	Bank b(1, 1, type1, description);
	this->service.addBank(1, 1, type1, description);
	this->service.deleteBank(-1);
	vector<Bank> banks = this->service.getAll();
	assert(banks.size() == 1);
	this->service.deleteBank(1);
	banks = this->service.getAll();
	assert(banks.size() == 1);
	this->service.deleteBank(0);
	banks = this->service.getAll();
	assert(banks.size() == 0);
}


