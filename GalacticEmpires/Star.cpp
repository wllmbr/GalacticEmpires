#include "Star.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <string>

#define TEXT_OFFSET 10

Star::Star(std::vector<double> slocation, int num, sf::RenderWindow &wd)
	: window(wd)
{
	location = slocation;
	//srand((unsigned)time(NULL));
	defence.size = rand() % 100;
	defence.location = location;

	buildCapacity = rand() % 21;

	numID = num;

	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		std::cout << "Font Load Failure!!!";
		std::cin.ignore();
	}
	std::string t = std::to_string(num);
	text.setString(t);
	text.setPosition(location[0] - TEXT_OFFSET, location[1] - TEXT_OFFSET);
	text.setFont(font);
	text.setCharacterSize(10);

	sf::Color worldColor(48, 58, 130);
	shape.setRadius(2.5f);
	shape.setFillColor(worldColor);
	shape.setPosition(location[0], location[1]);

}

Fleet Star::deploy(int size, std::vector<int> destination)
{
	Fleet temp;
	temp.size = size;
	temp.owner = owner;
	double deltaX = destination[0] - location[0];
	double deltaY = destination[1] - location[1];
	temp.travelTime = static_cast<int>((sqrt((deltaX * deltaX) + (deltaY * deltaY))/ 100));
	temp.deploy = true;

	return temp;
}

void Star::draw()
{
	//window.clear();
	window.draw(shape);
	window.draw(text);

}

void Star::removeDraw()
{
	window.clear();
	window.display();
}