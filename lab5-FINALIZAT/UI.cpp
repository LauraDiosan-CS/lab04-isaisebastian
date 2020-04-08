#include "UI.h"
#include <iostream>
#include <ctime>
#include "Repo.h"
#include "Service.h"


using namespace std;

UI::UI() {

}

UI::UI(Service& s) {
	this->s = s;
}

void UI::addTransaction(Service& s) {
	int day; int money; int op;
	char* type = new char[4];
	char* description = new char[40];
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << "1. Adaugare" << endl;
	cout << "2. Inserare" << endl;
	cout << "Optiune: "; cin >> op;
	if (op == 1)
	{
		cout << "Suma de bani: "; cin >> money;
		cout << "Tipul tranzactiei(in/out): "; cin >> type;
		cout << "Descriere: "; cin >> description;
		s.addBank(ltm->tm_mday, money, type, description);
		cout << "Tranzactie adaugata cu succes!" << endl;
	}
	
	if (op == 2)
	{
		cout << "Ziua: ";  cin >> day;
		cout << "Suma de bani: ";  cin >> money;
		cout << "Tipul tranzactiei: ";  cin >> type;
		cout << "Descriere: ";  cin >> description;
		s.addBank(day, money, type, description);
		cout << "Tranzactie inserata cu succes!" << endl;
	}

}
 
void UI::deleteTransaction(Service& s) {
	cout << endl;
	cout << "Modificari:" << endl;
	cout << "	1. Eliminare tranzactie dintr-o anumita zi" << endl;
	cout << "	2. Eliminare tranzactii dintr-un interval de zile dat" << endl;
	cout << "	3. Eliminarea tranzactiilor(in/out) din luna curenta" << endl;
	cout << "	4. Inlocuirea suma veche a unei tranzactii cu o suma noua" << endl;
	cout << "Optiune: "; 
	int opt; cin >> opt;
	switch (opt) {
	case 1:
	{
		int givenDay;
		cout << "Ziua: "; cin >> givenDay;
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (it != banks.end())
		{
			if ((*it).getDay() == givenDay)
				s.deleteBank((*it));
			it++;
		}
		break;
	}
	case 2:
	{
		int day1, day2;
		cout << "Introduceti prima zi: "; cin >> day1;
		cout << "Introduceti a doua zi: "; cin >> day2;
		if (day2 < day1)
			swap(day1, day2);
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (!(it == banks.end()))
		{
			if ((*it).getDay() >= day1 && (*it).getDay() <= day2)
				s.deleteBank((*it));
			it++;
		}
		break;
	}
	case 3: 
	{
		char* givenType = new char[4];
		cout << "Introduceti tipul pentru eliminare(in/out): "; cin >> givenType;
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (!(it == banks.end())) {
			if (strcmp((*it).getType(), givenType)==0)
				s.deleteBank((*it));
			it++;
		}
		break;
	}
	case 4: 
	{
	}
	}
}
void UI::proprietiesTransaction(Service& s)
{
	cout << endl;
	cout << "Proprietati(sum/max):" << endl;
	cout << "	1. Afiseaza suma totala a tranzactiilor de tip in/out" << endl;
	cout << "	2. Afiseaza cea mai valoroara tranzactie de tip in/out dintr-o zi data" << endl;
	cout << "Optiunea: "; int opt; cin >> opt;
	switch (opt) {
	case 1: 
	{
		char* typetotal = new char[4];
		cout << "Tipul tranzactiei pentru suma totala: "; cin >> typetotal;
		s.totalSum(typetotal);
		break;
	}
	case 2:
	{
		int day; char* typegiven = new char[4];
		cout << "Tipul tranzactiei: "; cin >> typegiven;
		cout << "Ziua tranzactiei: "; cin >> day;
		s.maxBank(day, typegiven);
		break;
	}
	}
}

void UI::filterTransactions(Service& s)
{
	cout << endl;
	cout << "Filter: " << endl;
	cout << "	1. Pastreaza doar tranzactiile de tip in/out" << endl;
	cout << "	2. Pastreaza doar tranzactiile de tip in/out dintr-o zi data" << endl;
	cout << "Optiunea: "; int opt; cin >> opt;
	switch (opt)
	{
	case 1:
	{
		char* type = new char[4];
		cout << "Tipul: "; cin >> type;
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (it != banks.end()) {
			if (strcmp((*it).getType(), type) == 0)
				cout << *it;
			it++;
		}
		break;
	}
	case 2: {
		char* type = new char[4];
		int day;
		cout << "Tipul: "; cin >> type;
		cout << "Ziua: "; cin >> day;
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (it != banks.end()) {
			if (strcmp((*it).getType(), type) == 0 && (*it).getDay() == day)
				cout << *it;
			it++;
		}
		break;
	}
	}
}

void UI::showAll(Service& s) {
	cout << endl;
	cout << "Listari:" << endl;
	cout << "	1. Afiseaza toate tranzactiile din lista " << endl;
	cout << "	2. Afiseaza toate tranzactiile de tip in/out din lista " << endl;
	cout << "	3. Afiseaza toate tranzactiile din lista cu suma mai mare/mica sau egala decat un numar dat" << endl;
	cout << "	4. Afiseaza sold-ul tranzactiilor dintr-o anumita zi data " << endl;
	cout << "Optiunea: "; 
	int opt; cin >> opt;
	switch (opt) {
	case 1: 
	{
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (it != banks.end()) {
			cout << *it;
			it++;
		}
		break;
	}

	case 2:
	{
		char* giventype = new char[4];
		cout << "Tranzactiile de tip (out/in): "; cin >> giventype;
		vector<Bank> banks = s.getAll();
		vector<Bank>::iterator it = banks.begin();
		while (it != banks.end()) {
			if (strcmp((*it).getType(), giventype) == 0)
				cout << *it;
			it++;
		}
		break;
	}

	case 3: 
	{
		int givenSum; int option;
		cout << "1. Afisarea tranzactiilor din lista cu suma mai mare decat un numar dat." << endl;
		cout << "2. Afisarea tranzactiilor din lista cu suma mai mica decat un numar dat." << endl;
		cout << "3. Afisarea tranzactiilor din lista cu suma egala cu un numar dat." << endl;
		cout << "Optiune: "; cin >> option;
		cout << "Suma data: "; cin >> givenSum;
		if (option == 1) {
			vector<Bank> banks = s.getAll();
			vector<Bank>::iterator it = banks.begin();
			while(it != banks.end()) {
				if ((*it).getMoney() > givenSum)
					cout << *it;
				it++;
			}
		}
		else if (option == 2) {
			vector<Bank> banks = s.getAll();
			vector<Bank>::iterator it = banks.begin();
			while ( it != banks.end()) {
				if ((*it).getMoney() < givenSum)
					cout << *it;
				it++;
			}
		}
		else if (option == 3) {
			vector<Bank> banks = s.getAll();
			vector<Bank>::iterator it = banks.begin();
			while ( it != banks.end()) {
				if ((*it).getMoney() == givenSum)
					cout << *it;
				it++;
			}
		}
		break;
	}

	case 4: 
	{
		int givenDay; 
		cout << "Ziua: "; cin >> givenDay;
		cout << "Sold-ul tranzactiilor din ziua " << givenDay << " este: " << s.soldBank(givenDay);
		break;
	}
	}
}

void UI::showMenu() {
	cout << endl;
	cout << "Optiuni: " << endl;
	cout << "1. Adaugarea / inserarea unei tranzactii in lista" << endl;
	cout << "2. Modificarea tranzactiilor din lista" << endl;
	cout << "3. Identificarea tranzactiilor cu anumite proprietati (listare)" << endl;
	cout << "4. Obtinerea unor caracteristici ale tranzactiilor (sum, max)" << endl;
	cout << "5. Filtrari" << endl;
	cout << "6. Undo" << endl;
	cout << "0. Exit" << endl;
	cout << "Introduceti optiunea: ";
}

void UI::runUI(Service& s)
{
	bool done = false;
	while (!done) {
		this->showMenu();
		int op;
		cin >> op;
		switch (op) {
		case 1: {addTransaction(s); break; }
		case 2: {deleteTransaction(s); break; }
		case 3: {showAll(s); break; }
		case 4: {proprietiesTransaction(s); break; }
		case 5: {filterTransactions(s); break; }
		case 6: {s.undo_operation(); cout << "Undo efectuat!" << endl; break; }
		case 0: {done = true; cout << "Done! " << endl; }
		}
	}
}