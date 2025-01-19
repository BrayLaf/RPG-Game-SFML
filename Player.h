#pragma once
#include "Skeleton.h"

class Player{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 20.0f;

	sf::RectangleShape boundRect;

	sf::Vector2i size;
public:
	sf::Sprite sprite;
public:
	void Initialize();// on start
	void Load();// on start
	void Update(Skeleton& skeleton);// once per frame
	void Draw(sf::RenderWindow& window);// once per frame
};