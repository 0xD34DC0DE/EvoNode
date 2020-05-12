#include "SFML/Graphics.hpp"
#include "Window.h"

int main()
{
	d34d::Window window(512, 512, 60, "EvoNodes");

	std::function<bool(sf::Event&)> closeFunction = [&window](sf::Event evnt) {
		window.close();
		return true;
	};

	window.registerEventFunction(sf::Event::Closed, closeFunction);

	while (window.isOpen()) {
		
		window.handleEvents();

		window.clear();
		window.display();
	}


	return 0;
}