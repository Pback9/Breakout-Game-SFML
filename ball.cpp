#include "ball.h"
#include <math.h>
// constructor
Ball::Ball(float startX, float startY) {
    pos.x = startX;
    pos.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(pos);
}

FloatRect Ball::getPos() {
    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
    return ballShape;
}

float Ball::getXVel() {
    return xVel;
}

void Ball::reboundSides() {
    xVel = -xVel;
}

void Ball::reboundBrickOrTop() {
    yVel = -yVel;
}

void Ball::reboundBat(Paddle paddle) {
    sf::FloatRect paddleLoc = paddle.getPosition();
    sf::FloatRect ballLoc = ballShape.getGlobalBounds();
    
    float ballCenterX = (ballLoc.left + ballLoc.left + ballLoc.width)/2;
    float paddleCenterX = (paddleLoc.left + paddleLoc.left + paddleLoc.width)/2;
    float offsetFromCenter = ballCenterX - paddleCenterX;


    // std::cout << ballCenterX << "\n" << paddleCenterX << "\n" << offsetFromCenter << "\n\n";
    // velocity is 3 for each
    // paddle size is 150
    xVel = offsetFromCenter / 10;
    yVel = -yVel;
}

void Ball::hitBottom() {
    pos.x = 500; 
    pos.y = 500;
    xVel = 0.0f;
    yVel = 5.0f;
}

void Ball::update() {
    pos.y += yVel;
    pos.x += xVel;

    ballShape.setPosition(pos);
}