#pragma once
#include "Fleet.h"
#include <vector>

class Star {
public:
	Fleet defence;
	std::vector<double> location;
	int owner;
};