#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
  private:
    //Player Variables
    int m_PlayerHeight;
    int m_PlayerWidth;

    Vector2f m_Position;

    Sprite m_Sprite;

    Texture m_Texture;

    float m_Speed;
    int m_JumpHeight;

    float m_Health;
  public:
    Player();

    void resetPlayer();

    Sprite getSprite();

    void moveLeft();
    void moveRight();
    void Jump();

    void stopLeft();
    void stopRight();

    void update(float elapsedTime);

    void healthUpgrade();
    void healthRestoration();

};
