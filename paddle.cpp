#include "paddle.h"

using namespace sf;

// constructor
Paddle::Paddle(float startX, float startY) {
    pos.x = startX;
    pos.y = startY;

    paddleShape.setSize(Vector2f(150, 5));
    paddleShape.setPosition(pos);
}

FloatRect Paddle::getPosition() {
    return paddleShape.getGlobalBounds();
}

RectangleShape Paddle::getShape() {
    return paddleShape;
}

void Paddle::moveLeft() {
    pos.x -= batSpeed;
}

void Paddle::moveRight() {
    pos.x += batSpeed;
}

void Paddle::update() {
    paddleShape.setPosition(pos);
}