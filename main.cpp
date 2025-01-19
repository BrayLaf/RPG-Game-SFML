#include <iostream>
#include "Player.h"

int main()
{
    //-------------------INITIALIZE------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game", sf::Style::Default, settings);
    window.setFramerateLimit(30);

    Player player;
    player.Initialize();

    Skeleton skeleton;
    skeleton.Initialize();
    //-------------------INITIALIZE------------------

    //----------------------LOAD----------------
    player.Load();
    skeleton.Load();
    // ---------------BACKGROUND---------
    sf::Texture ground;
    sf::Sprite back;
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
        skeleton.Update();
        player.Update(skeleton);

       
       //-----------UPDATE-------------

    //-------------DRAW------
        window.clear(sf::Color::Black);

        window.draw(back);
        skeleton.Draw(window);
        player.Draw(window);
        
      
        window.display();
    //-------------DRAW------
    }
    //--------------GAME LOOP------------
    return 0;
}