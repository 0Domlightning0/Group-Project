#pragma once
class investments {
protected:
	double rate = 0;
public:
	investments();
	investments(double r);
	~investments();
    virtual double calculateReturn(double amount);
    virtual void updateRate();
};
