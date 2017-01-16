#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <ctime>
#include "Star.h"
#include "Fleet.h"
#include <windows.h>

#define MAP_WIDTH 700
#define MAP_HEIGHT 350
#define MAP_OFFSET 50

int main()
{
	
	
	//Game parameters
	int playerCount;
	int years;
	int starCount;
	std::cout << "How many players? ";
	std::cin >> playerCount;
	std::cout << "How many years? ";
	std::cin >> years;
	std::cout << "How many stars? ";
	std::cin >> starCount;


	//Game Data Structures
	sf::RenderWindow window(sf::VideoMode(MAP_WIDTH + (2 * MAP_OFFSET), MAP_HEIGHT + (2 * MAP_OFFSET)), "Galactic Empires");
	std::vector<Star> Galaxy;

	//Create game
	bool good = false;
	srand((unsigned)time(NULL));
	window.clear();
	while (!good)
	{
		window.clear();
		window.display();
		std::string response;
		for (int i = 0; i < starCount;i++)
		{
			double xloc = std::fmod(rand(), MAP_WIDTH);
			double yloc = std::fmod(rand(), MAP_HEIGHT);
			std::vector<double> loc = { xloc + MAP_OFFSET,yloc + MAP_OFFSET };
			Star newstar(loc, i, window);
			Galaxy.push_back(newstar);
			Galaxy[i].draw();
			//Sleep(100);
			//window.display();
		}
		window.display();
		std::cout << "Create a new galaxy? ";
		std::cin >> response;
		if ((response == "n") || (response == "N")){
			good = true;
		}else{
			for (int i = 0; i < starCount;i++)
			{
				Galaxy[i].removeDraw();
			}
			Galaxy.clear();
		}
	}

	//Assign each player a random homeworld
	for (int i = 0; i < playerCount; i++)
	{
		int possibleHomeworld = rand() % starCount;
		if (Galaxy[possibleHomeworld].owner != -1)
		{
			Galaxy[possibleHomeworld].owner = i;
		}
	}

	//Play Game
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//window.clear();
		//window.draw(shape);
		//window.display();
	}

	return 0;
}
