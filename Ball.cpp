#include "Ball.h"

Ball::Ball(sf::RenderWindow& window)
{
	sf::FloatRect getBounds = ball.getGlobalBounds();
	ball.setOrigin(getBounds.width / 2.f, getBounds.height / 2.f);
	ball.setRadius(10.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	std::srand(std::time(nullptr));
	angle = rand() % 45;
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

void Ball::move(sf::RenderWindow& window, int &left, int &right)
{
	radians = angle * 3.14159f / 180.f;
	velocity.x = std::cos(radians);
	velocity.y = std::sin(radians);
	ball.move(velocity.x * move_x, velocity.y * move_y);
	

	if (ball.getPosition().y + ball.getGlobalBounds().height >= window.getSize().y) {
		move_y = -3.5f;
	}
	else if (ball.getPosition().y <= 0) {
		move_y = 3.5f;
	}
	else if (ball.getPosition().x + ball.getGlobalBounds().height >= window.getSize().x + 30) {
		left += 1;
		restart_ball(window);
		move_x = -3.5f;
	}
	else if (ball.getPosition().x <= -30) {
		right += 1;
		restart_ball(window);
		move_x = 3.5f;
	}

}

void Ball::restart_ball(sf::RenderWindow& window) {
	ball.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
	move_x = 3.5f;
	angle = rand() % 45;
	sf::sleep(sf::seconds(2));
}

sf::FloatRect Ball::getting_bounds()
{
	return ball.getGlobalBounds();
}

void Ball::ball_paddle_hit()
{
	move_x *= -1;
	angle = rand() % 45;
	if (move_x > 0)
		move_x += speed_increase;
	else
		move_x = -1 * (std::abs(move_x) + speed_increase);
}
