#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game() = default;
	Game(sf::RenderWindow& window);
	sf::Text setting_text(sf::Font &font, const std::string text_message, sf::RenderWindow& window, int character_size, float x, float y);
	void draw(sf::RenderWindow& window);
	void draw_points(sf::RenderWindow& window, int& left, int& right);
	bool is_game_started = false;
	sf::Text left_counting;
	sf::Text right_counting;

private:
	sf::Font starting_font;
	sf::Text starting_text;
	sf::Text press_key_text;
	sf::Font counting_font;

};

