#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::Text text;
	sf::Text drag;
	sf::Font font;
	sf::Vector2u coords;

	sf::Vector2i startMouse;
	bool isDragging;

	sf::Vector2i dragCoords;
	sf::Vector2i finalCoords;
	sf::Vector2i hypo;
	sf::Int32 hyp;

	// Add your object here

};