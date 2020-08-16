#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
  private:
    //Player Variables
    int m_PlayerHeight = 24;
    int m_PlayerWidth = 24;
    Vector2f m_Position;

    float m_Health;
    int m_MaxHealth = 100;

    //Sprite Variables
    Sprite m_Sprite;
    int m_SpriteWidth = 24;
    int m_SpriteHeight = 24;

    int m_activeFrame = 0;

    //Speed
    float m_Speed = 20;
    float m_Xvelocity;
    int m_MaxXvelocity = 75;
    float m_Yvelocity;
    int m_MaxYvelocity = 120;
    int m_GravityAcceleration = 60;
    int m_JumpSpeed = 700;

    //Status Variables
    bool m_onGround = false;
    bool m_canJump = false;
    bool m_hitAroof = false;
    bool m_leftKey = false;
    bool m_rightKey = false;
    bool m_jumpKey = false;
    bool m_downKey = false;


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

    void spawn();

    void update(float elapsedTime, int groundY);

    void draw(int gameFrameCounter, Vector2f camera);

    //Status functions
    void resetPlayer();
    bool canIJump();
    void healthUpgrade(int healthInt);
    void healthRestoration();

};
