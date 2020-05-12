#include "Window.h"



d34d::Window::Window(uint32_t width, uint32_t height, uint32_t frameRateLimit, std::string title) : width(width), height(height), frameRateLimit(frameRateLimit)
{
	windowPtr = new sf::RenderWindow(sf::VideoMode(width, height), title);
	windowPtr->setFramerateLimit(frameRateLimit);
}


d34d::Window::~Window()
{
	delete windowPtr;
}

void d34d::Window::addStaticSprite(sf::Sprite & sprite)
{
	
}

void d34d::Window::display()
{
	windowPtr->display();
}

void d34d::Window::clear(sf::Color clearColor)
{
	windowPtr->clear(clearColor);
}

void d34d::Window::handleEvents()
{
	sf::Event evnt;
	while (windowPtr->pollEvent(evnt)) {
		auto matchedFunctions = eventFunctionsMap.equal_range(evnt.type);
		for (auto it = matchedFunctions.first; it != matchedFunctions.second; ++it)
			it->second(evnt);
	}
}

void d34d::Window::registerEventFunction(sf::Event::EventType eventType, std::function<bool(sf::Event&)> eventFunction)
{
	eventFunctionsMap.emplace(eventType, eventFunction);
}

sf::RenderWindow* d34d::Window::getWindowPtr()
{
	return windowPtr;
}

void d34d::Window::setFrameRateLimit(uint32_t frameRate)
{
	frameRateLimit = frameRate;
	windowPtr->setFramerateLimit(frameRate);
}

bool d34d::Window::isOpen()
{
	return windowPtr->isOpen();
}

void d34d::Window::close()
{
	windowPtr->close();
}
