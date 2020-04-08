#pragma once
#include "Service.h"
class UI {
private:
	Service s;
	void showMenu();
	void showAll(Service& s);
	void addTransaction(Service& s);
	void deleteTransaction(Service& s);
	void proprietiesTransaction(Service& s);
	void filterTransactions(Service& s);
public:
	UI();
	UI(Service& s);
	void runUI(Service& s);
};