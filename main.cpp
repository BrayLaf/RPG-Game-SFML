#include <iostream>
#include "Player.h"

int main()
{
    //-------------------INITIALIZE------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game", sf::Style::Default, settings);
    window.setFramerateLimit(360);

    Player player;
    player.Initialize();

    Skeleton skeleton;
    skeleton.Initialize();
    //-------------------INITIALIZE------------------

    //----------------------LOAD----------------
    player.Load();
    skeleton.Load();
    //--------------LOAD-----------------------
    //------------------GAME LOOP------------

    sf::Clock clock;

    while (window.isOpen())
    {
        // ----------------UPDATE------------
        
        sf::Time deltaTimer = clock.restart();
        float deltaTime = deltaTimer.asMilliseconds();
        float fps = 1.0f / deltaTimer.asSeconds();

        std::cout << fps << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        skeleton.Update(deltaTime);
        player.Update(deltaTime, skeleton);
       //-----------UPDATE-------------

    //-------------DRAW------
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);
        
        window.display();
    //-------------DRAW------

    }
    //------------------GAME LOOP------------
    return 0;
}