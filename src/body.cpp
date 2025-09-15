#include <iostream>
#include "body.h"


Body::Body(Position pos, double mass, float radius,Velocity speed) : 
pos(pos),mass(mass),radius(radius),speed(speed) {}

bool checkSizeOldPos(std::vector<Position> oldPos,size_t max){

    if(oldPos.size() >= max){
        oldPos.clear();
        return false;
    }
    return true;
}

void Body::draw(Color color) const {
    int screenX = static_cast<int>(pos.x * scale);
    int screenY = static_cast<int>(pos.y * scale);
    float screenRadius = radius * scale;
    DrawCircle(screenX, screenY, screenRadius, color);

    for (auto e : oldPositions){
        DrawCircle(static_cast<int>(e.x * scale) ,static_cast<int>(e.y * scale) ,2,color);
    }
}


void Body::applyGravity(std::vector<Body> bodies) const 
{
    for (auto& b : bodies){
        //code TODO
        std::cout<<"Test"<<"\n";
    }
}

void Body::check_touched_ledge(){
    double posY = pos.y + radius; // Position y of the body
    double posX = pos.x + radius;
    double posXBack = pos.x - radius - 0.15;
    double posYTop = pos.y - radius;

    has_touched_low_ledge = (posY >= 720/scale);
    has_touched_top_ledge = (posYTop <= 0);
    has_touched_left_ledge = (posXBack <= 0);
    has_touched_right_ledge = (posX >= 1280/scale);

}

void appgravity(Body& b,Body& b2){

    b.speed.y += 0.02; // gravity -> a modifier par la constante (default 0.02)

    b.pos.y += b.speed.y;
    b.pos.x += b.speed.x;

    if (b.oldPositions.size() >= b.MAXOLDPOS){
        b.oldPositions.clear();
    }

    b.oldPositions.push_back(b.pos);

    b.check_touched_ledge();

    if (b.has_touched_low_ledge) {
        b.pos.y = (720 / scale) - b.radius;
        b.speed.y *= -0.9;

        b.speed.x *= 0.9;
    }
    if (b.has_touched_top_ledge) {
        b.pos.y = b.radius;
        b.speed.y *= -0.9;
        b.speed.x *= 0.9;
    }
    if (b.has_touched_right_ledge){
        b.pos.x = (1280/scale) - b.radius;
        b.speed.y *= 0.9;
        b.speed.x *= -0.9;
    }
    if (b.has_touched_left_ledge || collisionCheck(b,b2)){
        b.speed.x *= -0.9;
        b.speed.y *= -0.9;
    }
}

double calculateDistance(Body b1, Body b2){

    Position b1Pos = b1.pos;
    Position b2Pos = b2.pos;

    return sqrt((pow(b2Pos.x - b1Pos.x,2) + pow(b2Pos.y - b1Pos.y,2)));
}

bool collisionCheck(Body& b1,Body& b2){

    double distance = calculateDistance(b1,b2);
    float radiusSum = b1.radius + b2.radius;
    return distance <= radiusSum;
}