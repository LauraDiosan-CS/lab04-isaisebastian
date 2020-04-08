#pragma once
#include "Service.h"

class TestService {
private:
	Service service;

	void testAddBank();
	void testGetAll();
	void testUpdateBankByDescription();
	void testDeleteBank();
public:
	TestService();
	void testall();
};