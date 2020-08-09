#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"

using namespace sf;

int main()
{
    //Texture holder instance is required for using texture holders
    TextureHolder holder;

    //Player instance
    Player P1;

    //Window
    RenderWindow window(sf::VideoMode(320, 180), "Work in progress game!");
    //Framerate
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Controlls/Buttons
            if (event.type == Event::KeyPressed)
            {
              //Escape
              if (event.key.code == Keyboard::Escape)
              {
                window.close();
              }
            }
        }

        window.clear();
        window.draw(P1.getSprite());
        window.display();
    }

    return 0;
}
