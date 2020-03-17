#include "Repo.h"

Repo::Repo() {
	nr = 0;
}
Repo::~Repo() {
	nr = 0;
}

void Repo::addElem(Bank b) {
	banks[nr++] = b;
}

Bank* Repo::getAll() {
	return banks;
}

int Repo::getSize() {
	return nr;
}