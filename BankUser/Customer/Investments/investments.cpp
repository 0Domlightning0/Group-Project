#include "investments.h"

investments::investments() {
	invest = 0;
	balance = 0;
}
investments::investments(double inv, double bal) {
	invest = inv;
	balance = bal;
}
investments::~investments() {

}
