#include "Service.h"

Service::Service() {

}

Service::Service(Repo& repo) {
	this->repo = repo;
}

Service::~Service() {

}

void Service::setRepo(Repo repo) {
	this->repo = repo;
}

void Service::addBank(int day, int amount_money, const char* type, const char* description) {
	this->repo.addElem(Bank(day, amount_money, type, description));
}

vector<Bank> Service::getAll() {
	return this->repo.getAll();
}

void Service::updateBankByDescription(const char* description, int newDay, int newMoney, const char* newType, const char* newDescription) {
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

Bank Service::getBankAtPosition(size_t pos) {
	return this->repo.getBankAtPosition(pos);
}

void Service::deleteBank(size_t pos) {
	Bank bankDelete = this->repo.getBankAtPosition(pos);
	this->repo.deleteElem(bankDelete);
}