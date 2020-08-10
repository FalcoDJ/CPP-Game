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

    //Speed
    float m_Speed = 100;
    int m_YSpeed = 0;
    int m_JumpSpeed = 500;

    int m_playerYacceleration = 1;

    float m_Health;

    //Status Variables
    bool m_canJump;
    bool m_leftKey;
    bool m_rightKey;
    bool m_jumpKey;
    bool m_downKey;


  public:
    Player();

    void resetPlayer();

    Sprite getSprite();

    Vector2f getPosition();

    void moveLeft();
    void moveRight();
    void Jump();
    void Crouch();

    void stopLeft();
    void stopRight();
    void Fall();
    void Stand();

    bool canIJump();
    void update(float elapsedTime, Vector2f camera);

    void healthUpgrade(int healthInt);
    void healthRestoration();

};
