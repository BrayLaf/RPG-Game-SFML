#pragma once
#include "Skeleton.h"

class Player{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 5.0f;
	float playerSpeed = 2.0f;
	sf::RectangleShape boundRect;

	sf::Vector2i size;
public:
	sf::Sprite sprite;
public:
	void Initialize();// on start
	void Load();// on start
	void Update(float deltaTime, Skeleton& skeleton);// once per frame
	void Draw(sf::RenderWindow& window);// once per frame
};