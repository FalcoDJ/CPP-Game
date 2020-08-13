#include <SFML/Graphics.hpp>
#include "Collisions.h"

using namespace sf;

bool CollisionY(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height)
{
  if (Obj1.y <= (Obj2.y + Obj2Height) && (Obj1.y + Obj1Height) >= Obj2.y)
  {
    return true;
  }
  else if  (Obj1.y >= (Obj2.y + Obj2Height) && (Obj1.y + Obj1Height) <= Obj2.y)
  {
    return true;
  }
  else
  {
    return false;
  }
}
