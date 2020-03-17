#include <assert.h>
#include "Tests.h"
#include "Bank.h"
#include "Repo.h"
using namespace std;

void add_get_tests() {
	char* type1 = new char[10];
	char* type2 = new char[10];
	char* type3 = new char[10];


	strcpy_s(type1, sizeof "out", "out");
	strcpy_s(type2, sizeof "in", "in");
	Bank b(type1);
	b.setType(type2);
	assert(b.getType() == type2);
	
	Bank newbank(type1);
	assert(newbank.getType() == type1);

	Bank mybank;
	mybank.setType(type3);
	Bank mybank2;
	mybank2.setType(type2);
	Repo repo;
	repo.addElem(mybank);
	repo.addElem(mybank2);
	assert(repo.getSize() == 2);
	assert(repo.getAll()[0].getType() == type3);
	assert(repo.getAll()[1].getType() == type2);


}