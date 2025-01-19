#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "skel image loaded\n";
        sprite.setTexture(texture);
        sprite.setPosition(400, 100);
        sprite.setTextureRect(sf::IntRect(0 * 64, 2 * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "skel image failed to load\n";
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
