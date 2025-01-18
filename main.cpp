#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>


sf::Vector2f normalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m; 
    normalizedVector.y = vector.y / m;

    return normalizedVector;

}

void animate(int& xIndex, int yIndex) {
    if (xIndex >= 8) {
        xIndex = 0;
    }
    ++xIndex;

}

int main()
{
    //-------------------INITIALIZE------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game", sf::Style::Default, settings);
    sf::Texture ground;
    sf::Sprite back;
    ground.loadFromFile("Assets/Background/background.png");
    window.setFramerateLimit(30);
    //-------------------INITIALIZE------------------
    
    //----------------------LOAD----------------
    // ---------------BACKGROUND---------
    if (ground.loadFromFile("Assets/Background/background.png")) {
        std::cout << "background loaded\n";
        back.setTexture(ground);
        back.setPosition(0, 0);
        back.scale(sf::Vector2f(1, 1));
    }
    else {
        std::cout << "background failed\n";
    }
    // ---------------BACKGROUND---------
    //------------SKELETON--------------
    int xIndex = 0, yIndex = 0;
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;
    if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png")) {
        std::cout << "skel image loaded\n";
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(400, 100);
        skeletonSprite.setTextureRect(sf::IntRect(0 * 64, 2 * 64, 64, 64));
        skeletonSprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "skel image failed to load\n";
    }
    //------------SKELETON----------
    //---------------PLAYER---------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png")) {
        std::cout << "player image loaded\n";
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
        playerSprite.setPosition(sf::Vector2f(1100, 500));
    }
    else {
        std::cout << "player image failed to load\n";
    }
    //---------------PLAYER---------
    // ----------------BULLET
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 20.0f;

    // ----------------BULLET
    //--------------LOAD-----------------------
    //------------------Game loop 
    while (window.isOpen())
    {
        // ---------------- UPDATE
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerSprite.setPosition(position + sf::Vector2f(10, 0));
            yIndex = 3;
            animate(xIndex, yIndex);
            playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerSprite.setPosition(position - sf::Vector2f(0, 10));
            yIndex = 0;
            animate(xIndex, yIndex);
            playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerSprite.setPosition(position - sf::Vector2f(10, 0));
            yIndex = 1;
            animate(xIndex, yIndex);
            playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerSprite.setPosition(position + sf::Vector2f(0, 10));
            yIndex = 2;
            animate(xIndex, yIndex);
            playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());

        }for (size_t i = 0; i < bullets.size(); i++){
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);

        }
       //-----------UPDATE-------------

    //---------------DRAW
        window.clear(sf::Color::Black);
        window.draw(back);
        window.draw(skeletonSprite);
        window.draw(playerSprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();
    //-------------DRAW------
    }
    //--------------GAME LOOP------------
    return 0;
}