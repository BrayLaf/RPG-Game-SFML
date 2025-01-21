#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
    boundRect.setFillColor(sf::Color::Transparent);
    boundRect.setOutlineColor(sf::Color::Blue);
    boundRect.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}


void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "skel image loaded\n";
        sprite.setTexture(texture);
        sprite.setPosition(400, 100);

        int xIndex = 0, yIndex = 2;

        sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
        sprite.scale(sf::Vector2f(3, 3));
        boundRect.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else {
        std::cout << "skel image failed to load\n";
    }
}

void Skeleton::Update(float deltaTime)
{
    boundRect.setPosition(sprite.getPosition());

}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundRect);
}
