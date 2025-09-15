#include <iostream>
#include "view.h"

void View::DebugInfo(Body& b,Body& b2){

    auto speedX = b.speed.x;
    auto speedY = b.speed.y;
    auto posX = b.pos.x;
    auto posY = b.pos.y;
    bool isCollising = collisionCheck(b,b2);
    auto acc = b.acceleration;

    std::string sX = std::to_string(speedX);
    std::string sY = std::to_string(speedY);
    std::string pX = std::to_string(posX);
    std::string pY = std::to_string(posY);
    std::string check = std::to_string(isCollising);
    std::string accString = std::to_string(acc);

    auto speedX_ = b2.speed.x;
    auto speedY_ = b2.speed.y;
    auto posX_ = b2.pos.x;
    auto posY_ = b2.pos.y;
    bool isCollising_ = collisionCheck(b2,b);
    auto accB2 = b2.acceleration;

    std::string sX_ = std::to_string(speedX_);
    std::string sY_ = std::to_string(speedY_);
    std::string pX_ = std::to_string(posX_);
    std::string pY_ = std::to_string(posY_);
    std::string check_ = std::to_string(isCollising_);
    std::string accB2String = std::to_string(accB2);

    DrawText(("X coord speed: " + sX).c_str(), 10, 10, 13, WHITE);
    DrawText(("Y coord speed: " + sY).c_str(), 10, 40, 13, WHITE);
    DrawText(("X position: " + pX).c_str(), 10, 70, 13,WHITE);
    DrawText(("Y position: " + pY).c_str(), 10, 100, 13, WHITE);
    DrawText(("Collision: " + check).c_str(), 10, 130, 13, WHITE);
    DrawText(("Acceleration: " + accString).c_str(),10,145,13,WHITE);

    DrawText(("X coord speed: " + sX_).c_str(), 10, 160, 13, BLUE);
    DrawText(("Y coord speed: " + sY_).c_str(), 10, 190, 13, BLUE);
    DrawText(("X position: " + pX_).c_str(), 10, 210, 13, BLUE);
    DrawText(("Y position: " + pY_).c_str(), 10, 240, 13, BLUE);
    DrawText(("Collision: " + check_).c_str(), 10, 270, 13, BLUE);
    DrawText(("Acceleration: " + accB2String).c_str(),10,285,13,BLUE);
}