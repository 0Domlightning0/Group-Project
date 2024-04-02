#include "investments.h"
investments::investments(){
	rate = 0;
}
investments::investments(double r) {
	rate = r;
}

investments::~investments() {

}

double investments::calculateReturn(double amount) {
	return amount;
}

void investments::updateRate() {

}
