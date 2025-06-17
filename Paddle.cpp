#include "Paddle.h"

Paddle::Paddle(float x, sf::RenderWindow& window, char side)
{
	paddle.setSize(sf::Vector2f(25.f, 100.f));
	sf::FloatRect getBounds = paddle.getGlobalBounds();
	paddle.setOrigin(getBounds.width / 2.f, getBounds.height / 2.f);
	paddle.setPosition(x, window.getSize().y / 2.f);
	which_side = side;

}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(paddle);
}

void Paddle::move_paddle(Ball &ball) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && which_side == 'l' && paddle.getPosition().y - paddle.getGlobalBounds().height / 2.f >= 0) {
		paddle.move(0.f, -paddle_move_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && which_side == 'l' && paddle.getPosition().y + paddle.getGlobalBounds().height / 2.f <= 768) {
		paddle.move(0.f, paddle_move_speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && which_side == 'r' && paddle.getPosition().y - paddle.getGlobalBounds().height / 2.f >= 0) {
		paddle.move(0.f, -paddle_move_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && which_side == 'r' && paddle.getPosition().y + paddle.getGlobalBounds().height / 2.f <= 768) {
		paddle.move(0.f, paddle_move_speed);
	}

	if (paddle.getGlobalBounds().intersects(ball.getting_bounds())) {
		ball.ball_paddle_hit();
	}
}
