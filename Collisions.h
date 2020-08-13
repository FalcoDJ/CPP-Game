#include <SFML/Graphics.hpp>

using namespace sf;

enum class Side {Left, Right, Top, Bottom};

bool CollisionY(Vector2f Obj1, int Obj1Height, Vector2f Obj2, int Obj2Height);
