#include "stocks.h"

stocks::stocks() {

}
stocks::stocks(double inv, double bal) : investments(inv, bal) {
	invest = inv;
	balance = bal;
}
stocks::~stocks() {

}
