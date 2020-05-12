#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include <functional>
#include <tuple>

namespace d34d {
	class Window
	{
	private:

		uint32_t width;
		uint32_t height;
		uint32_t frameRateLimit;

		sf::Event evnt;

		sf::RenderWindow* windowPtr;

		std::vector<sf::Sprite> staticSprites;

		std::unordered_multimap<sf::Event::EventType, std::function<bool(sf::Event&)>> eventFunctionsMap;

	public:
		Window(uint32_t width, uint32_t height, uint32_t frameRateLimit, std::string title);
		~Window();

		void addStaticSprite(sf::Sprite& sprite);
		void display();
		void clear(sf::Color clearColor = sf::Color::Black);
		void handleEvents();
		
		void registerEventFunction(sf::Event::EventType eventType, std::function<bool(sf::Event&)>);

		sf::RenderWindow* getWindowPtr();
		void setFrameRateLimit(uint32_t frameRate);
		bool isOpen();

		void close();
	};
}

