#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace sf;

class Ball {
private:
    Vector2f pos;

    RectangleShape ballShape;

    float xVel = 0.0f;
    float yVel = 5.0f;

public:
    Ball(float startX, float startY);
    FloatRect getPos();
    RectangleShape getShape();
    float getXVel();
    void reboundSides();
    void reboundBrickOrTop();
    void reboundBat(Paddle paddle);
    void hitBottom();
    void update();
};