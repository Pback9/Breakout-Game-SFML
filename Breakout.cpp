#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "levels.h"
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
    window.setFramerateLimit(60);


    int score = 0;
    int lives = 3;

    Paddle paddle(windowWidth / 2-75, windowHeight - 20);
    Ball ball(windowWidth / 2, windowHeight/2);
    std::vector<std::vector<Brick>> bricks;
    bricks = level1(bricks);

    int numBricks = 0;

    for (int i = 0; i < bricks.size(); i++) {
        for (int j = 0; j < bricks[i].size(); j++) {
            numBricks++;
        }
    }

    numBricks = 1;

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color(200,200,200,255));
    hud.setPosition(0, -20);

    Text winScreen;
    winScreen.setFont(font);
    winScreen.setCharacterSize(200);
    winScreen.setFillColor(Color(200,200,200,255));
    winScreen.setPosition(200, 400);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A)) {
            paddle.moveLeft();
        }

        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            paddle.moveRight();
        }

        else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (ball.getPos().top > windowHeight) {
            ball.hitBottom();
            lives--;

            if (lives < 1) {
                score = 0;
                lives = 3;
                bricks.clear();
                bricks = level1(bricks);
            }
        }

        if (ball.getPos().top < 0) {
            ball.reboundBrickOrTop();
        }

        if (ball.getPos().left < 0 || ball.getPos().left+10 > windowWidth) {
            ball.reboundSides();
        }

        if (ball.getPos().intersects(paddle.getPosition())) {
            ball.reboundBat(paddle);
        }

        for (int i = 0; i < bricks.size(); i++) {
            for (int j = 0; j < bricks[i].size(); j++) {
                if (ball.getPos().intersects(bricks[i][j].getPos()) && !(bricks[i][j].getStatus())) {
                    bricks[i][j].gotHit();
                    ball.reboundBrickOrTop();
                    score++;
                }
            }
        }

        window.clear(Color(50, 50, 50, 255));

        std::stringstream ss;
        ss << "Score:" << score << "    Lives:" << lives;
        hud.setString(ss.str());
        window.draw(hud);

        if (score != numBricks) {
            ball.update();
            paddle.update();
            
        }
        else {
            std::stringstream winss;
            winss << "You Win!";
            winScreen.setString(winss.str());
            window.draw(winScreen);
        }
        

        

        window.draw(paddle.getShape());
        window.draw(ball.getShape());
        for (int i = 0; i < bricks.size(); i++) {
            for (int j = 0; j < bricks[i].size(); j++) {
                if (bricks[i][j].getStatus() == false) {
                    window.draw(bricks[i][j].getShape());
                }
            }
        }

        window.display();
    }
    return 0;
}