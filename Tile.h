#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile
{
private:
  int m_tileSize = 16;
  Vector2f m_Position;
  int m_tileType;

  Sprite m_Sprite;

public:
  Tile(int type, Vector2f tilePosition);

  void update();
  void draw(Vector2f camera);

  Sprite getSprite();

};
