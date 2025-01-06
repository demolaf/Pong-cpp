#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "MediaQuery.h"

int main()
{
	// Create a video mode object
	sf::VideoMode vm = MediaQuery::getCurrentVM();

	printf("Video mode, Width: %d - Height: %d", vm.width, vm.height);

	sf::RenderWindow window(vm, "Pong", sf::Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen


}