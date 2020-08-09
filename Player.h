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

    //Status Variables
    bool leftKey;
    bool rightKey;
    bool jumpKey;
    bool downKey;

  public:
    Player();

    void resetPlayer();

    Sprite getSprite();

    FloatRect getPosition();

    void moveLeft();
    void moveRight();
    void Jump();
    void Crouch();

    void stopLeft();
    void stopRight();

    void update(float elapsedTime);

    void healthUpgrade(int healthInt);
    void healthRestoration();

};
