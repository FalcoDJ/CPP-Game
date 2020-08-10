#include <iostream>
#include "Player.h"
#include "TextureHolder.h"
#include "SpriteAnimator.h"

Player::Player()
{
  //Starter Stuff
  m_Health = 100;

  //Texture and Sprite
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Player/Sheet Test.png"));
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
  m_downKey = false;
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

bool Player::canIJump()
{
  return m_canJump;
}

void Player::update(float elapsedTime, Vector2f camera)
{
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
  //Moving

  //Jumping
  m_Position.y += m_YSpeed;
  m_YSpeed += m_playerYacceleration;
  if (m_Position.y >= 140)
  {
    m_YSpeed  = 0;
    m_canJump = true;
  }
  if (m_jumpKey)
  {
    m_YSpeed = -(m_JumpSpeed * elapsedTime);
    m_canJump = false;
    m_jumpKey = false;
  }

  //Left

  if (m_leftKey)
  {
    m_Position.x -= m_Speed * elapsedTime;
  }

  //Right
  if (m_rightKey)
  {
    m_Position.x += m_Speed * elapsedTime;
  }

  if (m_jumpKey)
  {
    m_Position.y += m_JumpSpeed * elapsedTime;
  }
}

void Player::draw(int gameFrameCounter)
{
  //Animation
  SpriteAnimator(m_Sprite, m_SpriteWidth, m_SpriteHeight, 10, 1, m_activeFrame);
  //Temp Frame changer
  if (gameFrameCounter % 5 == 0)
  {
    m_activeFrame += 1;
  }
  if (m_activeFrame >= 10)
  {
    m_activeFrame -= 10;
  }
}
