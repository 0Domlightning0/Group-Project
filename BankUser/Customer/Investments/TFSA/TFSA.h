#pragma once
#include "investments.h"
class TFSA :  public investments {
public:
	TFSA();
	TFSA(double inv, double bal);
	~TFSA();
};
