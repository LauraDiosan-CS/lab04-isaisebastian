#include <iostream>
#include <ostream>
#include "Bank.h"
#include "Repo.h"
#include "Tests.h"
using namespace std;


void add(Repo& repo)
{
	char type[30];
	cout << "Introduceti tipul cheltuielii: ";
	cin >> type;
	Bank b1(type);
	repo.addElem(b1);
	cout << "Added!";
}

void show_all(Repo& repo)
{
	repo.getAll();
}
void menu()
{
	char option;
	cout << "1. Adaugare cheltuiala." << endl;
	cout << "2. Afisare cheltuieli." << endl;
	cout << "3. Iesire" << endl;
	cout << "Alegeti optiunea: "; cin >> option;
}

int main() {

}
