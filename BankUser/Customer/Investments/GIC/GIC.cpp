#include "GIC.h"

GIC::GIC() {
	updateRate();
}
GIC::GIC(double r) : investments(r) {
	rate = r;
}
GIC::~GIC() {

}
