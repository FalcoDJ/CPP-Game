#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "TextureHolder.h"
#include "SpriteAnimator.h"

using namespace sf;

Tile::Tile(int type, Vector2f tilePosition)
{
  m_Sprite.setTexture(TextureHolder::GetTexture("img/Tiles.png"));

  m_Position = tilePosition;
  m_Position.x *= m_tileSize;
  m_Position.y *= m_tileSize;

  m_tileType = type;
}

void Tile::update()
{

}

void Tile::draw(Vector2f camera)
{
  m_Sprite.setPosition(m_Position.x - camera.x, m_Position.y - camera.y);
  SpriteAnimator(m_Sprite, m_tileSize, m_tileSize, 4, 1, m_tileType);
}

Sprite Tile::getSprite()
{
  return m_Sprite;
}
