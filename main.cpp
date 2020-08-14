#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Player.h"
#include "Tile.h"
#include "Collisions.h"

using namespace sf;

int main()
{
    //Texture holder instance is required for using texture holders
    TextureHolder holder;

    Clock clock;

    //Player instance
    Player P1;

    int gameFrameCounter;
    //Window

    int windowHeight = 176;
    int windowWidth = 320;
    RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Work in progress game!");
    //Framerate
    window.setFramerateLimit(60);

    float totalGameTime;

    //Tile Space
    int levelWidthTiles = 20;
    int levelHeightTiles = 12;
    Tile* tiles = nullptr;
    delete[] tiles;

    int levelMap[levelHeightTiles][levelWidthTiles] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {2,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {2,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                       {2,3,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    while (window.isOpen())
    {
        Tile** tiles = new Tile*[levelHeightTiles];
        for(int i = 0; i < levelHeightTiles; i++)
        {
          tiles[i] = new Tile[levelWidthTiles];
        }
        for (int i = 0; i < levelHeightTiles; i++)
        {
          for (int j = 0; j < levelWidthTiles; j++)
          {
            tiles[i][j].setType(levelMap[i][j]);
          }
        }


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

        totalGameTime += dtAsSeconds;

        Vector2f camera;

        //Update Tiles
        for (int i = 0; i < levelHeightTiles; i++)
        {
          for (int j = 0; j < levelWidthTiles; j++)
          {
            Vector2f tilePosition;
            tilePosition.x = j;
            tilePosition.y = i;
            tiles[i][j].update(tiles[i][j].getType(), tilePosition);

            if (tiles[i][j].getType() != 0)
            {
              if (CollisionsGround(P1.getPosition(), P1.returnHeight(), tiles[i][j].getPosition())
              && CollisionX(P1.getPosition(), P1.returnWidth(), tiles[i][j].getPosition(), tiles[i][j].getSize()))
              {
                P1.Stand();
              }
            }
          }
        }

        //Update Player
        P1.update(dtAsSeconds);

        //Update Camera - Must be last!

        //X coord
        if (P1.getPosition().x < 60)
        {
          camera.x = 0;
        }
        else
        {
          camera.x = P1.getPosition().x - 60;
        }

        //Y coord
        if (P1.getPosition().y < 100)
        {
          camera.y = 0;
        }
        else
        {
          camera.y = P1.getPosition().y - 100;
        }

        //###########
        // Drawing
        //###########

        window.clear();

        //Draw Tiles
        for (int i = 0; i < levelHeightTiles; i++)
        {
          for (int j = 0; j < levelWidthTiles; j++)
          {
            tiles[i][j].draw(camera);
            window.draw(tiles[i][j].getSprite());
          }
        }

        //Character
        P1.draw(gameFrameCounter, camera);
        window.draw(P1.getSprite());

        window.display();
    }
    delete[] tiles;
    return 0;
}
