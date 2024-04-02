#include "stocks.h"

stocks::stocks() {
	updateRate();
}
stocks::stocks(double r) : investments(r) {
	rate = r;
}
stocks::~stocks() {

}
