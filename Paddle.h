#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <iostream>

class Paddle
{
public:
	Paddle(float x, sf::RenderWindow& window, char side);
	void draw(sf::RenderWindow& window);
	void move_paddle(Ball& ball);
	char which_side;
	sf::RectangleShape paddle;
private:
	float paddle_move_speed = 2.f;
};

