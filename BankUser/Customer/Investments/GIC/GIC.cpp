#include "GIC.h"

GIC::GIC() {

}
GIC::GIC(double inv, double bal) : investments(inv, bal) {
	invest = inv;
	balance = bal;
}
GIC::~GIC() {

}
