#include "MediaQuery.h"

MediaQuery::MediaQuery() 
{
	currentVideoMode = sf::VideoMode::getFullscreenModes()[0];
}

MediaQuery MediaQuery::instance = MediaQuery();

sf::VideoMode MediaQuery::getCurrentVM()
{
	return instance.currentVideoMode;
}

int MediaQuery::screenWidth()
{
	return instance.currentVideoMode.width;
}

int MediaQuery::screenHeight()
{
	return instance.currentVideoMode.height;
}