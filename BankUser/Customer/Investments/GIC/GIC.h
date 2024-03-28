#pragma once
#include "investments.h"
class GIC :  public investments {
public:
	GIC();
	GIC(double inv, double bal);
	~GIC();
};
