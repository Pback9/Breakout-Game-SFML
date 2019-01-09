#include "ball.h"
#include <math.h>

// constructor
Ball::Ball(float startX, float startY) {
    pos.x = startX;
    pos.y = startY;

    ballShape.setSize(sf::Vector2f(10, 10)); // ball is a 10px square
    ballShape.setPosition(pos);
}

// get the position of the ball
FloatRect Ball::getPos() {
    return ballShape.getGlobalBounds();
}

// get the shape of the ball
RectangleShape Ball::getShape() {
    return ballShape;
}

// rebound the ball off of a left or right side
void Ball::reboundSides() {
    xVel = -xVel;
}

// rebound the ball off of a brick or the top of the screen
void Ball::reboundBrickOrTop() {
    yVel = -yVel;
}

// rebound the ball off of the paddle
void Ball::reboundPaddle(Paddle paddle) {
    sf::FloatRect paddleLoc = paddle.getPosition();
    sf::FloatRect ballLoc = ballShape.getGlobalBounds();
    
    float ballCenterX = (ballLoc.left + ballLoc.left + ballLoc.width)/2;            // ball x midpoint 
    float paddleCenterX = (paddleLoc.left + paddleLoc.left + paddleLoc.width)/2;    // paddle x midpoint
    float offsetFromCenter = ballCenterX - paddleCenterX;   // how far off center the ball midpoint is from the paddle midpoint


    // x velocity is scaled to how far off center the ball is from the paddle
    // and which side of the paddle is hit
    xVel = offsetFromCenter / 10;
    yVel = -yVel;
}

// ball hits the bottom
void Ball::hitBottom() {
    // reset ball position
    pos.x = 500; 
    pos.y = 500;
    xVel = 0.0f;
    yVel = 5.0f;
}

// update the ball's position
void Ball::update() {
    pos.y += yVel;
    pos.x += xVel;

    ballShape.setPosition(pos);
}