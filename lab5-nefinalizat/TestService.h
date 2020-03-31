#pragma once
#pragma once
#include "Service.h"

class TestService {
private:
	Service service;

	void testAddBank();
	void testGetAll();
	void testUpdateBankByDescription();
	void testDeleteBank();
	void testGetBankAtPosition();
public:
	TestService();
	void testAll();
};