#include "TFSA.h"

TFSA::TFSA() {
	updateRate();
}
TFSA::TFSA(double r) : investments(r) {
	rate = r;
}
TFSA::~TFSA() {

}
