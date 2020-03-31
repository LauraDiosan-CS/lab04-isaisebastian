#include <iostream>
#include "Bank.h"
#include "Service.h"
#include "TestRepo.h"
#include "TestService.h"
#include "UI.h"
using namespace std;

int main() {
	TestRepo testrepo;
	testrepo.testAll();
	TestService testservice;
	testservice.testAll();
	Repo repo("BanksIn.txt", "BanksOut.txt");
	Service service(repo);
	UI ui(service);
	ui.runUI(service);
}