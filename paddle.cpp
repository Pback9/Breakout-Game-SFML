#include "paddle.h"

using namespace sf;

// constructor
Paddle::Paddle(float startX, float startY) {
    pos.x = startX;
    pos.y = startY;

    paddleShape.setSize(Vector2f(150, 5));
    paddleShape.setPosition(pos);
}

// get the position of the paddle
FloatRect Paddle::getPosition() {
    return paddleShape.getGlobalBounds();
}

// get the shape of the paddle
RectangleShape Paddle::getShape() {
    return paddleShape;
}

// move the paddle left
void Paddle::moveLeft() {
    pos.x -= batSpeed;
}

// move the paddle right
void Paddle::moveRight() {
    pos.x += batSpeed;
}

// update paddle position
void Paddle::update() {
    paddleShape.setPosition(pos);
}