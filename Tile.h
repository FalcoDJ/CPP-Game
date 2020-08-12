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


  void update(int type, Vector2f tilePosition);
  void draw(Vector2f camera);

  int setType(int tileID);
  int getType();

  Sprite getSprite();

};
