#pragma once
class investments {
private:
	double invest = 0;
	double balance = 0;
public:
	investments();
	investments(double inv, double bal);
	~investments();

	double getInvest() { return invest; }
	double getBalance() { return balance; }

	void setInvest(double inv) { invest = inv; }
	void setBalance(double bal) { balance = bal; }
};
