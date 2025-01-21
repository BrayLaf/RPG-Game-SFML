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
    boundRect.setFillColor(sf::Color::Transparent);
    boundRect.setOutlineColor(sf::Color::Red);
    boundRect.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "player image loaded\n";
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(1100, 500));

        sprite.scale(sf::Vector2f(3, 3));
        boundRect.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        std::cout << "player image failed to load\n";
    }
}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.setPosition(position - sf::Vector2f(0, 1) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.setPosition(position - sf::Vector2f(1, 0) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

    }for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::normalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);

    }

    boundRect.setPosition(sprite.getPosition());

    if (Math::CheckRectCollision(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
        std::cout << "collision" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundRect);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}
