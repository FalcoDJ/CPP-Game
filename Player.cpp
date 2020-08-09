#include "Player.h"
#include "TextureHolder.h"

Player::Player()
{
  //Starter Stuff
  m_Health = 100;

  //Texture and Sprite
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Player/sprite.png"));
}

void Player::moveLeft()
{
  leftKey = true;
}

void Player::moveRight()
{
  rightKey = true;
}

void Player::Jump()
{
  jumpKey = true;
}

void Player::Crouch()
{
  downKey = true;
}

Sprite Player::getSprite()
{
  return m_Sprite;
}

FloatRect Player::getPosition()
{
  return m_Sprite.getGlobalBounds();
}
