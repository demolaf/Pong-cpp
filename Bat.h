#pragma once // this prevents the compiler from processing this file more than once.
#include <SFML/Graphics.hpp>

class Bat
{
private:
	sf::Vector2f m_Position;

	// A RectangleShape object, this holds the bat shape rectangle.
	sf::RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;

public:
	Bat(float startX, float startY);

	// this represents the four points that define a rectangle.
	sf::FloatRect getPosition();

	// this returns the bat shape "m_Shape" so it can be drawn in the main game loop.
	sf::RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	// this function will be called once at each frame of the game in the main function and will be used 
	// to calculate how much to move the bat in each frame.
	void update(sf::Time dt);
};