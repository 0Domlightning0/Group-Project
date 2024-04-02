#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "investments.h"

using namespace std;

class TFSA :  public investments {
public:
    TFSA();
    TFSA(double rate);
	~TFSA();

    void updateRate() {
        // Randomize rate for TFSA between -6% and 10%
        rate = -0.06 + static_cast<double>(rand()) / RAND_MAX * (0.10 - (-0.06));
    }

    double calculateReturn(double amount) {
        return amount * (1 + rate);
    }
};
