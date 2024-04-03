#pragma once
#include "Admin.h"

#include "Customer.h"

class Approvals : public Admin, public Customer{
private:

public:

	void flagDebitAccount(ifstream& infile, int len);

	void flagCreditAccount(ifstream& infile, int len);

	void updateRequests(ifstream& infile, int len, string type, int ID);
};

