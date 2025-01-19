#include "Player.h"
#include <iostream>
#include "Math.h"

void animate(int& xIndex, int yIndex) {
    if (xIndex >= 8) {
        xIndex = 0;
    }
    ++xIndex;

}
int xIndex = 0, yIndex = 0;

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "player image loaded\n";
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
        sprite.setPosition(sf::Vector2f(1100, 500));
    }
    else {
        std::cout << "player image failed to load\n";
    }
}

void Player::Update(Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.setPosition(position + sf::Vector2f(10, 0));
        yIndex = 3;
        animate(xIndex, yIndex);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.setPosition(position - sf::Vector2f(0, 10));
        yIndex = 0;
        animate(xIndex, yIndex);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.setPosition(position - sf::Vector2f(10, 0));
        yIndex = 1;
        animate(xIndex, yIndex);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.setPosition(position + sf::Vector2f(0, 10));
        yIndex = 2;
        animate(xIndex, yIndex);
        sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

    }for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::normalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);

    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}
