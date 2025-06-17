#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Game.h"
#include "Paddle.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    window.setFramerateLimit(60);
    Ball ball(window);
    Game starting_screen(window);
    Paddle paddle_left(25.f, window, 'l');
    Paddle paddle_right(window.getSize().x-25.f, window, 'r');
    int left_points = 0;
    int right_points = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && starting_screen.is_game_started == false) {
                starting_screen.is_game_started = true;
            }
        }

        window.clear();
        ball.draw(window);
        paddle_left.draw(window);
        paddle_right.draw(window);
        starting_screen.draw(window);
        starting_screen.draw_points(window, left_points, right_points);
        if (starting_screen.is_game_started) {
            ball.move(window, left_points, right_points);
            paddle_left.move_paddle(ball);
            paddle_right.move_paddle(ball);

        }
        window.display();
    }

    return 0;
}