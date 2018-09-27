#include "brick.h"

// Constructor
Brick::Brick(float xPos, float yPos, sf::Color color) {
    pos.x = xPos;
    pos.y = yPos;

    Color outlineColor(Color::Black);

    brickShape.setSize(sf::Vector2f(100, 20));
    brickShape.setPosition(pos);
    brickShape.setFillColor(color);
    //brickShape.setOutlineColor(outlineColor);
    //brickShape.setOutlineThickness(1);
}

FloatRect Brick::getPos() {
    return brickShape.getGlobalBounds();
}

RectangleShape Brick::getShape() {
    return brickShape;
}

void Brick::gotHit() {
    isBroken = true;
}

bool Brick::getStatus() {
    return isBroken;
}