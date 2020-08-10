#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"

using namespace sf;

int main()
{
    //Texture holder instance is required for using texture holders
    TextureHolder holder;

    Clock clock;

    //Player instance
    Player P1;

    //Window
    RenderWindow window(sf::VideoMode(320, 180), "Work in progress game!");
    //Framerate
    window.setFramerateLimit(60);

    float totalGameTime;

    while (window.isOpen())
    {

        P1.moveRight();
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

        //###########
        // Updating
        //###########
        //Update the time delta
				Time dt = clock.restart();
				//Make a decimal fraction of 1 from the delta time
				float dtAsSeconds = dt.asSeconds();

        Vector2f camera;
        camera.x = P1.getPosition().x - 50;
        camera.y = P1.getPosition().y - 100;

        P1.update(dtAsSeconds, camera);

        //###########
        // Drawing
        //###########

        window.clear();
        window.draw(P1.getSprite());
        window.display();
    }

    return 0;
}
