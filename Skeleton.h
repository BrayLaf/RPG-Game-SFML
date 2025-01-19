#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;

	sf::RectangleShape boundRect;

	sf::Vector2i size;
public:
	void Initialize();// on start
	void Load();// on start
	void Update();// once per frame
	void Draw(sf::RenderWindow& window);// once per frame
};


