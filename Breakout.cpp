#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "levels.h"
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace sf;  // sfml namespace

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
    window.setFramerateLimit(60);

    int score = 0;
    int lives = 3;

    // create paddle and ball objects
    Paddle paddle(windowWidth / 2-75, windowHeight - 20);
    Ball ball(windowWidth / 2, windowHeight/2);
    std::vector<std::vector<Brick>> bricks;
    bricks = level1(bricks);    // set 2d vector of bricks to the first level layout

    // count the number of bricks
    int numBricks = 0;

    for (int i = 0; i < bricks.size(); i++) {
        for (int j = 0; j < bricks[i].size(); j++) {
            numBricks++;
        }
    }

    // text to show score and reamining lives
    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color(200,200,200,255));
    hud.setPosition(0, -20);

    // text that shows up when the level is won
    Text winScreen;
    winScreen.setFont(font);
    winScreen.setCharacterSize(200);
    winScreen.setFillColor(Color(200,200,200,255));
    winScreen.setPosition(200, 400);

    while (window.isOpen()) {

        // controls are a and d for movement and escape to close the game
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

        // if the ball hits the bottom of the screen, subtract a life
        if (ball.getPos().top > windowHeight) {
            ball.hitBottom();
            lives--;
            // if the player runs out of lives, reset the score and reload the level
            if (lives < 1) {
                score = 0;
                lives = 3;
                bricks.clear();
                bricks = level1(bricks);
            }
        }

        // rebound the ball off of the top of the screen
        if (ball.getPos().top < 0) {
            ball.reboundBrickOrTop();
        }

        // rebound the ball off of the edges of the screen
        if (ball.getPos().left < 0 || ball.getPos().left+10 > windowWidth) {
            ball.reboundSides();
        }

        // rebound ball off of paddle
        if (ball.getPos().intersects(paddle.getPosition())) {
            ball.reboundPaddle(paddle);
        }

        // check if the ball has hit any of the bricks that aren't destroyed
        for (int i = 0; i < bricks.size(); i++) {
            for (int j = 0; j < bricks[i].size(); j++) {
                if (ball.getPos().intersects(bricks[i][j].getPos()) && !(bricks[i][j].getStatus())) {
                    bricks[i][j].gotHit();
                    ball.reboundBrickOrTop();
                    score++;
                }
            }
        }

        // clear the window
        window.clear(Color(50, 50, 50, 255));

        // draw the score
        std::stringstream ss;
        ss << "Score:" << score << "    Lives:" << lives;
        hud.setString(ss.str());
        window.draw(hud);

        // if the user hasn't won yet continue updating the paddle and ball movements
        if (score != numBricks) {
            ball.update();
            paddle.update();
        }

        // if the user has won display the win message
        else {
            std::stringstream winss;
            winss << "You Win!";
            winScreen.setString(winss.str());
            window.draw(winScreen);
        }
        

        
        // draw the ball, paddle, and bricks
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