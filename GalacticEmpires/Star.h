#pragma once
#include "Fleet.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Star {
public:
	Fleet defence;
	std::vector<double> location;
	int owner;
	int buildCapacity;
	int numID;
	sf::RenderWindow &window;
	sf::Font font;
	sf::Text text;
	sf::CircleShape shape;

	Star(std::vector<double> slocation, int num, sf::RenderWindow &wd);
	Fleet deploy(int size, std::vector<int> destination);
	void draw();
	void removeDraw();
};