#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "investments.h"
class GIC :  public investments {
public:
    GIC();
	GIC(double rate);
	~GIC();

    void updateRate() {
        // Randomize rate for GIC between 2% and 5%
        rate = 0.02 + static_cast<double>(rand()) / RAND_MAX * (0.05 - 0.02);
    }

    double calculateReturn(double amount) {
        return amount * (1 + rate);
    }
};
