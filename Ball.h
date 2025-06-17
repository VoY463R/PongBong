#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Game.h"

class Ball
{
public:
	Ball(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void move(sf::RenderWindow& window, int& left, int& right);
	void restart_ball(sf::RenderWindow& window);
	sf::FloatRect getting_bounds();
	void ball_paddle_hit();
private:
	int left_count = 0;
	int right_count = 0;
	sf::CircleShape ball;
	float move_x = 3.5f;
	float move_y = 3.5f;
	int angle;
	float radians = 0.f;
	sf::Vector2f velocity;
	float speed_increase = 0.2f;


};

