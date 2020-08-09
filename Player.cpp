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
  leftKey = true;
}

//move right
void Player::moveRight()
{
  rightKey = true;
}

//Jump
void Player::Jump()
{
  jumpKey = true;
}

//Crouch
void Player::Crouch()
{
  downKey = true;
}

//Stop Motion Variables

//stop left
void Player::stopLeft()
{
  leftKey = false;
}

//stop right
void Player::stopRight()
{
  rightKey = false;
}

//stand / stop crouching
void Player::Stand()
{
  downKey = true;
}

//Other Variables
Sprite Player::getSprite()
{
  return m_Sprite;
}

FloatRect Player::getPosition()
{
  return m_Sprite.getGlobalBounds();
}
