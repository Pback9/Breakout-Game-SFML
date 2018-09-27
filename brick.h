#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Brick {
private:
    Vector2f pos;
    RectangleShape brickShape;
    bool isBroken;

public:
    Brick(float xPos, float yPos, Color);
    FloatRect getPos();
    RectangleShape getShape();
    void gotHit();
    bool getStatus();
};