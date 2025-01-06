#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "MediaQuery.h"

int main()
{
	sf::RenderWindow window(MediaQuery::getCurrentVM(), "Pong", sf::Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	Bat bat(MediaQuery::centerX(), MediaQuery::screenHeight() - 20);

	// HUD
	sf::Text hud;

	// HUD Font
	sf::Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(20, 20);

	// Game loop clock
	sf::Clock clock;
	
	while (window.isOpen())
	{
		// Handle the player input

		// Update the bat, ball and HUD

		// Draw bat, ball and HUD
	}

	return 0;
}