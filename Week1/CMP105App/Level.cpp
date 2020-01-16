#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Couldn't load a font\n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setPosition(window->getSize().x / 2 - text.getLocalBounds().width/2, 0);
	text.setCharacterSize(24); // in pixels, not points!
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	// initialise game objects
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(window->getSize().x / 2 - 50, window->getSize().y / 2 - 50);
	rect.setFillColor(sf::Color::Red);

	rect1.setSize(sf::Vector2f(60, 60));
	rect1.setPosition(window->getSize().x / 2 - 30, window->getSize().y / 2 - 30);
	rect1.setFillColor(sf::Color::Green);

	rect2.setSize(sf::Vector2f(20, 20));
	rect2.setPosition(window->getSize().x / 2 - 10, window->getSize().y / 2 - 10);
	rect2.setFillColor(sf::Color::Blue);

	rect3.setSize(sf::Vector2f(25, 25));
	rect3.setPosition(window->getSize().x -25, window->getSize().y -25);
	rect3.setFillColor(sf::Color::Green);

	circle.setRadius(65);
	circle.setPosition(window->getSize().x/2-65, window->getSize().y/2-65);
	circle.setFillColor(sf::Color::Yellow);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	rect3.setPosition(window->getSize().x - 25, window->getSize().y - 25);
	circle.setPosition(window->getSize().x / 2 - 65, window->getSize().y / 2 - 65);
	rect2.setPosition(window->getSize().x / 2 - 10, window->getSize().y / 2 - 10);
	rect1.setPosition(window->getSize().x / 2 - 30, window->getSize().y / 2 - 30);
	rect.setPosition(window->getSize().x / 2 - 50, window->getSize().y / 2 - 50);
	text.setPosition(window->getSize().x / 2 - text.getLocalBounds().width / 2, 0);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(rect);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(text);
	
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}