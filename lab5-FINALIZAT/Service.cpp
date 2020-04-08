#include "Service.h"
#include <algorithm>
Service::Service() {

}

Service::Service(Repo& repo) {
	this->repo = repo;
	this->undo.push_back(this->repo);
}

void Service::setRepo(Repo repo) {
	this->repo = repo;
}

void Service::addBank(int day, int amount_money, const char* type, const char* description) {
	undo.push_back(this->repo);
	this->repo.addElem(Bank(day, amount_money, type, description));
	this->repo.savetofile();
}

vector<Bank> Service::getAll() {
	return this->repo.getAll();
}

void Service::updateBankByDescription(const char* description, int newDay, int newMoney, const char* newType, const char* newDescription) {
	undo.push_back(this->repo);
	vector<Bank> elem = this->repo.getAll();
	Bank newBank(newDay, newMoney, newType, newDescription);
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(elem[i].getDescription(), description) == 0) {
			Bank oldBank(elem[i].getDay(), elem[i].getMoney(), elem[i].getType(), description);
			this->repo.updateElem(oldBank, newBank);
			return;
		}
	}
}


void Service::deleteBank(Bank& b)
{
	undo.push_back(this->repo);
	this->repo.deleteElem(b);
	this->repo.savetofile();
}

int Service::soldBank(int givenDay)
{
	vector<Bank> banks = repo.getAll();
	vector<Bank>::iterator it = banks.begin();
	int sumIn = 0; int sumOut = 0;;
	while (it != banks.end())
	{
		if ((*it).getDay() == givenDay) {
			if (strlen((*it).getType()) == 2)
				sumIn = sumIn + (*it).getMoney();
			if (strlen((*it).getType()) == 3)
				sumOut = sumOut + (*it).getMoney();
		}
		it++;
	}
	return sumIn - sumOut;
}


void Service::totalSum(char* totaltype)
{
	int total = 0;
	vector<Bank> banks = repo.getAll();
	vector<Bank>::iterator it = banks.begin();
	while (it != banks.end())
	{
		if (strcmp((*it).getType(), totaltype) == 0)
			total += (*it).getMoney();
		it++;
	}
	cout << "Suma totala a tranzactiilor de tip " << totaltype << " este: " << total;
	cout << endl;
}

void Service::maxBank(int day, char* type)
{
	vector<Bank> banks = repo.getAll();
	vector<Bank>::iterator it = banks.begin();
	Bank b;
	while (it != banks.end())
	{
		if ((*it).getDay() == day)
			if (strcmp((*it).getType(), type) == 0)
				b = *it;
		it++;
	}
	cout << b;
}

void Service::undo_operation()
{
	auto actual_state = undo.back();
	undo.pop_back();
	this->repo = actual_state;
	this->undo = undo;

}

Service::~Service() {

}