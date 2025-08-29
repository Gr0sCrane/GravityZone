#include <iostream>
#include "view.h"

void View::DebugInfo(Body& b,std::vector<Body> bodies){

    auto speedX = b.speed.x;
    auto speedY = b.speed.y;
    auto posX = b.pos.x;
    auto posY = b.pos.y;
    bool isCollising = collisionCheck(b,bodies[1]);

    std::string sX = std::to_string(speedX);
    std::string sY = std::to_string(speedY);
    std::string pX = std::to_string(posX);
    std::string pY = std::to_string(posY);
    std::string check = std::to_string(isCollising);

    DrawText(("X coord speed: " + sX).c_str(), 10, 10, 10, BLUE);
    DrawText(("Y coord speed: " + sY).c_str(), 10, 40, 10, BLUE);
    DrawText(("X position: " + pX).c_str(), 10, 70, 10, BLUE);
    DrawText(("Y position: " + pY).c_str(), 10, 100, 10, BLUE);
    DrawText(("Collision: " + check).c_str(), 10, 130, 10, BLUE);
}