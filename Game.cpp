#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
{

	if (!starting_font.loadFromFile("Fonts/FFF_Tusj.ttf") || !counting_font.loadFromFile("Fonts/pong_score.ttf"))
		std::cout << "Couldn't load font!" << std::endl;
	else {
		starting_text = setting_text(starting_font,"PongBong", window, 70, window.getSize().x / 2.f, window.getSize().y / 2.f-200.f);
		press_key_text = setting_text(starting_font,"Press Any Button to Start The Game", window, 30, window.getSize().x / 2.f, window.getSize().y / 2.f - 100.f);
		left_counting = setting_text(counting_font, "0", window, 70, window.getSize().x / 4.f, 50.f);
		right_counting = setting_text(counting_font, "0", window, 70, window.getSize().x/2.f + window.getSize().x / 4.f, 50.f);
	}
}

sf::Text Game::setting_text(sf::Font &font, const std::string text_message, sf::RenderWindow& window, int character_size, float x, float y)
{
	sf::Text text;
	text.setFont(font);
	text.setString(text_message);
	text.setCharacterSize(character_size);
	text.setLetterSpacing(2.f);
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
	text.setPosition(x, y);

	return text;
}

void Game::draw(sf::RenderWindow& window) {
	if (!is_game_started) {

	window.draw(starting_text);
	window.draw(press_key_text);

	}
}

void Game::draw_points(sf::RenderWindow& window, int &left, int &right)
{
	left_counting.setString(std::to_string(left));
	right_counting.setString(std::to_string(right));
	window.draw(left_counting);
	window.draw(right_counting);
}

