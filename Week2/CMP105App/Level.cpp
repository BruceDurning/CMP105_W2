#include "Level.h"
#include <iostream>
using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	
	// initialise game objects
if (!font.loadFromFile("font/arial.ttf")) {

		std::cout << "can not find the font!!";
	}
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(100, 100);
	coordX = 0;
	coordY = 0;

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W)) {
		
		input->setKeyUp(sf::Keyboard::W);

		cout << "W has been pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {

		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);

		cout << "J, K, and L have been pressed\n";
	}
	input->setMousePosition();
}

// Update game objects
void Level::update()
{

	text.setString(coordX + ", " + coordY);
}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}