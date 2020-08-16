#include <iostream>
#include "Player.h"
#include "TextureHolder.h"
#include "SpriteAnimator.h"
#include "Collisions.h"

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

//On/Off ground
void Player::Stand()
{
  m_onGround = true;
}
void Player::Fall()
{
  m_onGround = false;
}

bool Player::canIJump()
{
  return m_canJump;
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

int Player::returnWidth()
{
  return m_PlayerWidth;
}

int Player::returnHeight()
{
  return m_PlayerHeight;
}

void Player::spawn()
{
  m_Position.y = 0;
  m_Position.x = 0;
}

void Player::resetPlayer()
{
  m_Health = m_MaxHealth;
  m_Xvelocity = 0;
  m_Yvelocity = 0;
  m_activeFrame = 0;
  m_onGround = false;
}

void Player::update(float elapsedTime, int groundY)
{
  //Moving

  //Y Coord
  m_Yvelocity += m_GravityAcceleration * elapsedTime;

  if (m_Position.y >= (groundY - m_SpriteHeight) && m_onGround)
  {
    m_Yvelocity = 0;
    m_Position.y = (groundY  - m_SpriteHeight);
    m_canJump = true;
  }

  if (m_jumpKey)
  {
    m_Yvelocity = -(m_JumpSpeed * elapsedTime);
    m_onGround = false;
    m_jumpKey = false;
    m_canJump = false;
  }

  m_Position.y += m_Yvelocity;

  //X Coord
  //Left
  if (m_leftKey)
  {
    m_Xvelocity -= m_Speed * elapsedTime;
  }
  //Right
  if (m_rightKey)
  {
    m_Xvelocity += m_Speed * elapsedTime;
  }
  if (m_Xvelocity > m_MaxXvelocity)
  {
    m_Xvelocity = m_MaxXvelocity;
  }
  if (m_Xvelocity < -m_MaxXvelocity)
  {
    m_Xvelocity = -m_MaxXvelocity;
  }

  //Friction for running slows player down
  if (!m_rightKey && !m_leftKey && m_Xvelocity != 0)
  {
    if (m_Xvelocity > 0 && m_Xvelocity >= 60)
    {
      m_Xvelocity -= 60;
    }
    else if (m_Xvelocity < 0 && m_Xvelocity <= -60)
    {
      m_Xvelocity += 60;
    }
    else
    {
      m_Xvelocity = 0;
    }
  }

  m_Position.x += m_Xvelocity;
}

void Player::draw(int gameFrameCounter, Vector2f camera)
{
  //Sprite position in relation to camera
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);

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
