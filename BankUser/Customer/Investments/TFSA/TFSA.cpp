#include "TFSA.h"

TFSA::TFSA() {

}
TFSA::TFSA(double inv, double bal) : investments(inv, bal) {
	invest = inv;
	balance = bal;

}
TFSA::~TFSA() {

}
