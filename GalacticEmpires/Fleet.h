#pragma once
#include <vector>

class Fleet {
public:
	int size;
	int owner;
	std::vector<double> location;
	std::vector<double> destination;
	int travelTime;
	bool deploy;

	Fleet();

};