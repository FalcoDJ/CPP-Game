#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
  private:
    //Player Variables
    int m_PlayerHeight = 24;
    int m_PlayerWidth = 24;
    Vector2f m_Position;
    int m_groundY;


    float m_Health;

    //Sprite Variables
    Sprite m_Sprite;
    int m_SpriteWidth = 24;
    int m_SpriteHeight = 24;

    int m_activeFrame = 0;

    //Speed
    float m_Speed = 20;
    float m_Xvelocity;
    float m_Yvelocity;
    int m_GravityAcceleration = 60;
    int m_JumpSpeed = 800;

    //Status Variables
    bool m_onGround = false;
    bool m_canJump;
    bool m_leftKey;
    bool m_rightKey;
    bool m_jumpKey;
    bool m_downKey;


  public:
    Player();

    Sprite getSprite();
    Vector2f getPosition();

    //Moving functions
    void moveLeft();
    void moveRight();
    void Jump();
    void Crouch();

    //Stop moving functions
    void stopLeft();
    void stopRight();
    void Stand();
    void Fall();
    int returnWidth();
    int returnHeight();

    void update(float elapsedTime, int groundY);

    void draw(int gameFrameCounter, Vector2f camera);

    //Status functions
    void resetPlayer();
    bool canIJump();
    void healthUpgrade(int healthInt);
    void healthRestoration();

};
