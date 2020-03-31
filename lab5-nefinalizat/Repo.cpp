#include "Repo.h"
#include <fstream>

Repo::Repo() {
	this->in_f = NULL;
	this->out_f = NULL;
}

Repo::Repo(const char* in_f, const char* out_f) {
	this->in_f = new char[strlen(in_f) + 1];
	strcpy_s(this->in_f, strlen(in_f) + 1, in_f);
	this->out_f = new char[strlen(out_f) + 1];
	strcpy_s(this->out_f, strlen(out_f)+1, out_f);
	this->loadfromfile();
}

void Repo::set_in_f(const char* in_f) {
	if (this->in_f != NULL) {
		delete[] this->in_f;
	}
	this->in_f = new char[strlen(in_f) + 1];
	strcpy_s(this->in_f, strlen(in_f) + 1, in_f);

}

void Repo::set_out_f(const char* out_f) {
	if (this->out_f != NULL) {
		delete[]this->out_f;
	}
	this->out_f = new char[strlen(out_f) + 1];
	strcpy_s(this->out_f, strlen(out_f) + 1, out_f);

}

void Repo::addElem(Bank b) {
	this->elem.push_back(b);
	this->savetofile();
}

vector<Bank> Repo::getAll() {
	return this->elem;
}

int Repo::getSize() {
	return this->elem.size();
}

void Repo::updateElem(Bank& oldBank, Bank& newBank) {
	vector<Bank>::iterator it;
	it = find(this->elem.begin(), this->elem.end(), oldBank);
	if (!(it == this->elem.end())) {
		*it = newBank;
	}
}

void Repo::deleteElem(Bank& b) {
	vector<Bank>::iterator it;
	it = find(this->elem.begin(), this->elem.end(), b);
	if (!(it == this->elem.end())) {
		this->elem.erase(it);
	}
	this->savetofile();
}

Bank Repo::getBankAtPosition(size_t pos) {
	if (pos < 0 || pos > this->elem.size()-1) {
		char emptyType[] = "";
		char emptyDescription[] = "";
		return Bank(0, 0, emptyType, emptyDescription);
	}
	return this->elem[pos];
}

void Repo::loadfromfile() {
	if (this->in_f != NULL) {
		this->elem.clear();
		ifstream f(this->in_f);
		int day; int amount_money;
		char* type = new char[4]; 
		char* description = new char[40];
		while (!f.eof()) {
			f >> day >> amount_money >> type >> description;
			if (strlen(type) > 0) {
				this->addElem(Bank(day, amount_money, type, description));
			}
		}
		delete[] type;
		delete[] description;
		f.close();

	}
}

void Repo::savetofile() {
	if (this->out_f != NULL) {
		ofstream f(this->out_f);
		for (size_t i = 0; i < this->elem.size(); i++) {
			f << this->elem[i] << endl;
		}
		f.close();
	}
}

Repo::~Repo() {
	this->elem.clear();
}