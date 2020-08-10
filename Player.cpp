#include "Player.h"
#include "TextureHolder.h"

Player::Player()
{
  //Starter Stuff
  m_Health = 100;

  //Texture and Sprite
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Player/sprite.png"));
}

//Moving Functions
//move left
void Player::moveLeft()
{
  m_leftKey = true;
}

//move right
void Player::moveRight()
{
  m_rightKey = true;
}

//Jump
void Player::Jump()
{
  m_jumpKey = true;
}

//Crouch
void Player::Crouch()
{
  m_downKey = true;
}

//Stop Motion Variables

//stop left
void Player::stopLeft()
{
  m_leftKey = false;
}

//stop right
void Player::stopRight()
{
  m_rightKey = false;
}

//stand / stop crouching
void Player::Stand()
{
  m_downKey = true;
}

//Other Variables
Sprite Player::getSprite()
{
  return m_Sprite;
}

Vector2f Player::getPosition()
{
  return m_Position;
}

void Player::update(float elapsedTime, Vector2f camera)
{

  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);

  if (m_rightKey)
  {
    m_Position.x += m_Speed * elapsedTime;
  }
}
