#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "MediaQuery.h"
#include "UISizing.cpp"


int main()
{
	sf::RenderWindow window(MediaQuery::getCurrentVM(), "Pong", sf::Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	double batBottomMargin = 0.0185 * MediaQuery::screenHeight();
	int batCenterOrigin = UISizing::batWidth() / 2;
	Bat bat(MediaQuery::centerX() - batCenterOrigin, MediaQuery::screenHeight() - batBottomMargin);

	// HUD
	sf::Text hud;

	// HUD Font
	sf::Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");
	hud.setFont(font);
	hud.setCharacterSize(UISizing::hudFontSize());
	hud.setFillColor(sf::Color::White);
	hud.setPosition(0.0104 * MediaQuery::screenWidth(), 0.0185 * MediaQuery::screenHeight());

	// Game loop clock
	sf::Clock clock;
	
	while (window.isOpen())
	{
		// Handle the player input
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}

		// Handle the player quitting
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		// Handle the pressing and releasing of the arrow keys
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bat.moveLeft();
		}
		else 
		{
			bat.stopLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}

		// Update the bat, ball and HUD

		// Update the delta time
		sf::Time dt = clock.restart();
		bat.update(dt);

		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());

		// Draw bat, ball and HUD
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();
	}

	return 0;
}