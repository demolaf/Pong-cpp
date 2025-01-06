#pragma once
#include <SFML/Graphics.hpp>

class MediaQuery
{
public:
	static sf::VideoMode getCurrentVM();
	static int screenWidth();
	static int screenHeight();

private:
	MediaQuery();
	static MediaQuery instance;
	sf::VideoMode currentVideoMode;
};