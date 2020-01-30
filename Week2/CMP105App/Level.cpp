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

	drag.setFont(font);
	drag.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(100, 200);

	coords.x = 0;
	coords.y = 0;
	hyp = 0;
	startMouse.x = 0;
	startMouse.y = 0;
	finalCoords.x = 0;
	finalCoords.y = 0;
	hypo.x = 0;
	hypo.y = 0;
	isDragging = false;

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

	if (input->isMouseLDown() && !isDragging) {
		startMouse.x = input->getMouseX();
		startMouse.y = input->getMouseY();
		isDragging = true;
	}
	else if(isDragging && !input->isMouseLDown()) {
		dragCoords.x = input->getMouseX();
		dragCoords.y = input->getMouseY();

		finalCoords.x = dragCoords.x - startMouse.x;
		finalCoords.y = dragCoords.y - startMouse.y;

		hypo.x = pow(finalCoords.x, 2);
		hypo.y = pow(finalCoords.y, 2);
		
		hyp = hypo.x + hypo.y;
		std::cout << hyp;
		hyp = abs(hyp);		
		hyp = sqrt(hyp);

		isDragging = false;
	}

	coords.x = input->getMouseX();
	coords.y = input->getMouseY();

	
}

// Update game objects
void Level::update()
{
	string output = "Coords: " + std::to_string(coords.x)+ ", " + std::to_string(coords.y);
	text.setString(output);

	string hypotenuse = "Drag distance: " + std::to_string(hyp);
	drag.setString(hypotenuse);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(drag);
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