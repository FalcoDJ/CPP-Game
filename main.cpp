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

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //##########
        // Input
        //##########
          //Escape
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            window.close();
          }

          //Arrow Keys
          if (Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            P1.moveLeft();
          }
          else
          {
            P1.stopLeft();
          }
          if (Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            P1.moveRight();
          }
          else
          {
            P1.stopRight();
          }

        //###########
        // Updating
        //###########
        //Update the time delta
				Time dt = clock.restart();
				//Make a decimal fraction of 1 from the delta time
				float dtAsSeconds = dt.asSeconds();

        Vector2f camera;
        camera.x = 0;
        camera.y = 0;

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
