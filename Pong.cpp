#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "MediaQuery.h"
#include "UISizing.cpp"
#include "Ball.h"

// NOTES
// if(objectA.getPosition().right > objectB.getPosition().left && 
//		objectA.getPosition().left < objectB.getPosition().right) {
//			if(objectA.getPosition().top < objectB.getPosition().bottom && 
//				objectA.getPosition().bottom > objectB.getPosition().top) {
//					// Collision detected
//		}
// }
// 
// Collision detection
// 
// if both the x-axis and y-axis conditions are true, the code inside the innermost block is executed.This block indicates that 
// a collision has been detected between objectA and objectB.
// 
// It’s a common technique used in game development to check whether two objects, like game characters or items, are overlapping 
// or colliding in both horizontal and vertical directions. The technique is called axis - aligned bounding box or 
// AABB collision detection.
// 
// This technique is widely used in 2D graphics and game development due to its computational efficiency(i.e., it’s fast).
// It doesn’t provide precise collision information for irregularly shaped objects or circles, but even for these types of objects, 
// AABB will often be used as a fast initial check before more mathematically intensive checks are made.

int main()
{
	sf::RenderWindow window(MediaQuery::getCurrentVM(), "Pong", sf::Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen
	double batBottomMargin = 0.0185 * MediaQuery::screenHeight();
	int batCenterOrigin = UISizing::batWidth() / 2;
	Bat bat(MediaQuery::centerX() - batCenterOrigin, MediaQuery::screenHeight() - batBottomMargin);

	// Create a ball
	double ballCenterOrigin = UISizing::ballSize() / 2;
	Ball ball(MediaQuery::centerX() - ballCenterOrigin, 0);

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
		ball.update(dt);

		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());

		// BALL - COLLISION DETECTION - START

		// Handle the ball hitting the bottom
		if (ball.getPosition().top > MediaQuery::screenHeight())
		{
			// reverse the ball direction
			ball.reboundBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1) {
				// reset the score
				score = 0;

				// reset the lives
				lives = 3;
			}
		}

		// Handle the ball hitting the top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			// Add a point to the players score
			score++;
		}

		// Handle ball hitting sides
		if ((ball.getPosition().left < 0) ||
			(ball.getPosition().left + ball.getPosition().width) > MediaQuery::screenWidth()) 
		{
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}

		// BALL - COLLISION DETECTION - END

		// Draw bat, ball and HUD
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}