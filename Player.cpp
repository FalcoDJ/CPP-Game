#include "Player.h"
#include "TextureHolder.h"

Player::Player()
{
  //Starter Stuff
  m_Health = 100;

  //Texture and Sprite
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Player/sprite.png"));
}

Sprite Player::getSprite()
{
  return m_Sprite;
}

FloatRect Player::getPosition()
{
  return m_Sprite.getGlobalBounds();
}
