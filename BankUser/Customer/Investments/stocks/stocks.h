#include <ctime>

using namespace std;

#include "investments.h"
class stocks :  public investments {
public:
    stocks();
	stocks(double rate);
	~stocks();

    void updateRate() {
        // Randomize rate for Stocks between -12% and 15%
        rate = -0.12 + static_cast<double>(rand()) / RAND_MAX * (0.15 - (-0.12));
    }

    double calculateReturn(double amount) {
        return amount * (1 + rate);
    }
};
