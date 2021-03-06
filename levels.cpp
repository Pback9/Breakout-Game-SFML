#include "levels.h"

using namespace sf;

// create first level layout of the game
std::vector<std::vector<Brick>> level1(std::vector<std::vector<Brick>> brickVector) {
    // vector of colors for each row of bricks
    std::vector<Color> colors;
    colors.push_back(Color(200, 75, 76));
    colors.push_back(Color(197, 108, 57));
    colors.push_back(Color(181, 122, 46));
    colors.push_back(Color(163, 163, 43));
    colors.push_back(Color(81, 160, 68));
    colors.push_back(Color(67, 74, 200));


    // create 6 rows of bricks with 10 bricks in each row
    for (int i = 0; i < 6; i++) {
        std::vector<Brick> brickRow;
        for (int j = 0; j < 10; j++) {
            brickRow.push_back(Brick(j*100+12, i*20+75, colors[i]));
        }
        brickVector.push_back(brickRow);
    }
    return brickVector;
}