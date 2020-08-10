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

    int tempGround = 140;

    int gameFrameCounter;
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

          //Jump
          if (Keyboard::isKeyPressed(sf::Keyboard::Space) && P1.canIJump())
          {
            P1.Jump();
          }

          if (Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            //Move Left
            P1.moveLeft();
          }
          else
          {
            //Stop Left
            P1.stopLeft();
          }
          if (Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            //Move Right
            P1.moveRight();
          }
          else
          {
            //Stop Right
            P1.stopRight();
          }

        //###########
        // Updating
        //###########
        //Update the time delta
				Time dt = clock.restart();
				//Make a decimal fraction of 1 from the delta time
				float dtAsSeconds = dt.asSeconds();

        gameFrameCounter++;

        Vector2f camera;
        camera.x = 0;
        camera.y = 0;

        P1.update(dtAsSeconds, camera);

        //###########
        // Drawing
        //###########

        window.clear();
        P1.draw(gameFrameCounter);
        window.draw(P1.getSprite());
        window.display();
    }

    return 0;
}
