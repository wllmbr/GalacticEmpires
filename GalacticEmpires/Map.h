#pragma once
#include <vector>
#include "Star.h"
#include "Fleet.h"

class Map {
	std::vector<Star> starMap;
	std::vector<Fleet> fleetTracking;
};