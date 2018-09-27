#include "brick.h"

// Constructor
Brick::Brick(float xPos, float yPos, sf::Color color) {
    pos.x = xPos;
    pos.y = yPos;

    Color outlineColor(Color::Black);

    brickShape.setSize(sf::Vector2f(100, 20));  // bricks are 100px * 20px rectangles
    brickShape.setPosition(pos);
    brickShape.setFillColor(color);
    //brickShape.setOutlineColor(outlineColor);
    //brickShape.setOutlineThickness(1);
}

// return position of the brick
FloatRect Brick::getPos() {
    return brickShape.getGlobalBounds();
}

//  return the shape of the brick
RectangleShape Brick::getShape() {
    return brickShape;
}

// when a brick gets hit, set it to broken
void Brick::gotHit() {
    isBroken = true;
}

// return whether or not the brick is broken
bool Brick::getStatus() {
    return isBroken;
}