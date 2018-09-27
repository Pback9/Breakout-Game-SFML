#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
private:
    Vector2f pos;
    RectangleShape paddleShape;
    float batSpeed = 5.0f;

public:
    Paddle(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void update();
};