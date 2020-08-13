#include <SFML/Graphics.hpp>

using namespace sf;

enum class Side {Left, Right, Top, Bottom};

bool CollisionsGround(Vector2f Obj1, int Obj1Height, Vector2f Obj2);

bool CollisionY(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height);

bool CollisionBottom(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height);
bool CollisionTop(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height);

bool CollisionX(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width);

bool CollisionLeft(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width);
bool CollisionRight(Vector2f Obj1, int Obj1Width, Vector2f Obj2, int Obj2Width);
