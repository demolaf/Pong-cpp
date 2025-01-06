#include "Bat.h"
#include "MediaQuery.h"
#include "UISizing.cpp"

// this is the constructor and it's called when we instantiate the class
Bat::Bat(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(UISizing::batWidth(), UISizing::batHeight()));
	m_Shape.setPosition(m_Position);
}

// We will call this function from the main function when we are 
// determining whether the ball has hit the bat.
sf::FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

// getter function to draw the bat in the main function 
sf::RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_MovingLeft = true;
}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;
}

void Bat::stopRight()
{
	m_MovingRight = false;
}

void Bat::update(sf::Time dt)
{
	if (m_MovingLeft) {
		// The code multiplies the speed by the delta time and then adds or subtracts it 
		// from the position.This causes the bat to move relative to how long the frame 
		// took to update.
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}