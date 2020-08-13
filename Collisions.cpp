#include <SFML/Graphics.hpp>
#include "Collisions.h"

using namespace sf;

bool CollisionsGround(Vector2f Obj1, int Obj1Height, Vector2f Obj2)
{
  if (Obj1.y >= Obj2.y - Obj1Height)
  {
    return true;
  }
  else
    return false;
}

//Y coords

bool CollisionY(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height)
{
  if (CollisionBottom(Obj1, Obj1Height, Obj2, Obj2Height)
   || CollisionTop(Obj1, Obj1Height, Obj2, Obj2Height))
   {
     return true;
   }
   else
   {
     return false;
   }
}

bool CollisionBottom(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height)
{
  if (Obj1.y <= (Obj2.y + Obj2Height) && (Obj1.y + Obj1Height) >= Obj2.y)
    return true;
  else
    return false;
}
bool CollisionTop(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height)
{
  if  (Obj1.y >= (Obj2.y + Obj2Height) && (Obj1.y + Obj1Height) <= Obj2.y)
    return true;
  else
    return false;
}


//X coords

bool CollisionX(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width)
{
  if (CollisionLeft(Obj1, Obj1Width, Obj2, Obj2Width)
   || CollisionRight(Obj1, Obj1Width, Obj2, Obj2Width))
   {
     return true;
   }
   else
   {
     return false;
   }
}

bool CollisionLeft(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width)
{
  if (Obj1.x <= (Obj2.x + Obj2Width) && (Obj1.x + Obj1Width) >= Obj2.x)
    return true;
  else
    return false;
}
bool CollisionRight(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width)
{
  if  (Obj1.x >= (Obj2.x + Obj2Width) && (Obj1.x + Obj1Width) <= Obj2.x)
    return true;
  else
    return false;
}
