#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TextureHolder.h"
#include "SpriteAnimator.h"

using namespace sf;

void Tile::update(int type, Vector2f tilePosition)
{
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Tiles.png"));

  m_Position = tilePosition;
  m_Position.x *= m_tileSize;
  m_Position.y *= m_tileSize;

  m_tileType = type;
}


void Tile::draw(Vector2f camera)
{
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
  SpriteAnimator(m_Sprite, m_tileSize, m_tileSize, 5, 1, m_tileType);
}

void Tile::setType(int tileID)
{
  m_tileType = tileID;
}

int Tile::getType()
{
  return m_tileType;
}

Vector2f Tile::getPosition()
{
  return m_Position;
}

int Tile::getSize()
{
  return m_tileSize;
}

Sprite Tile::getSprite()
{
  return m_Sprite;
}
