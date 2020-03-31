#include "UI.h"
#include <iostream>

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
	cout << "1. Adaugare" << endl;
	cout << "2. Inserare" << endl;
	cout << "Optiune: "; cin >> op;
	cout << "Ziua: ";  cin >> day;
	cout << "Suma de bani: ";  cin >> money;
	cout << "Tipul tranzactiei: ";  cin >> type;
	cout << "Descriere: ";  cin >> description;
	s.addBank(day, money, type, description);
	cout << "Tranzactie adaugata cu succes!" << endl;
}

void deleteTransaction(Service& s) {
	int pos;
	cout << "Introduceti pozitia tranzactiei: " << endl; cin >> pos;
	s.deleteBank(pos);
	cout << "Tranzactie stearsa!" << endl;
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
	case 1: {
		vector<Bank> banks = s.getAll();
		for (Bank b : banks)
			cout << b;
		break;
	}
	case 2: {
		char* giventype = new char[4];
		cout << "Tranzactiile de tip (out/in): "; cin >> giventype;
		vector<Bank> banks = s.getAll();
		for (int i = 0; i < banks.size(); i++) {
			if (banks[i].getType() == giventype)
				cout << banks[i];
		}
		break;
	}
	case 3: {
		int givenSum; int option;
		cout << "1. Afisarea tranzactiilor din lista cu suma mai mare decat un numar dat." << endl;
		cout << "2. Afisarea tranzactiilor din lista cu suma mai mica decat un numar dat." << endl;
		cout << "3. Afisarea tranzactiilor din lista cu suma egala cu un numar dat." << endl;
		cout << "Optiune: "; cin >> option;
		cout << "Suma data: "; cin >> givenSum;
		if (option == 1) {
			vector<Bank> banks = s.getAll();
			for (int i = 0; i < banks.size(); i++) {
				if (banks[i].getMoney() > givenSum)
					cout << banks[i];
			}
		}
		else if (option == 2) {
			vector<Bank> banks = s.getAll();
			for (int i = 0; i < banks.size(); i++) {
				if (banks[i].getMoney() < givenSum)
					cout << banks[i];
			}
		}
		else if (option == 3) {
			vector<Bank> banks = s.getAll();
			for (int i = 0; i < banks.size(); i++) {
				if (banks[i].getMoney() == givenSum)
					cout << banks[i];
			}
		}
		break;
	}
	case 4: 
	{
		vector<Bank> banks = s.getAll();
		int givenDay; int sumIn = 0; int sumOut = 0;
		cout << "Ziua pentru a calcula sold-ul tranzactiilor: "; cin >> givenDay;
		for (int i = 0; i < banks.size(); i++)
		{
			if (banks[i].getDay() == givenDay) {
				if (banks[i].getType() == "in")
					sumIn = sumIn + banks[i].getMoney();
				else if (banks[i].getType() == "out")
					sumOut = sumOut + banks[i].getMoney();
			}
		}
		int sold = sumIn - sumOut;
		cout << "Sold-ul tranzactiilor din ziua " << givenDay << " este: " << sold;
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
		case 3: {showAll(s); break; }
		case 0: {done = true; cout << "Done! " << endl; }
		}
	}
}