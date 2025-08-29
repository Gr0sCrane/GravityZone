#include <iostream>
#include "body.h"


Body::Body(Position pos, double mass, float radius) : 
pos(pos),mass(mass),radius(radius) {}

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
    double posYTop = pos.y - radius;

    if (posY >= 720/scale){
        has_touched_low_ledge = true;
    } else if (posYTop <= 0){
        has_touched_top_ledge = true;
    } else {
        has_touched_low_ledge = false;
        has_touched_top_ledge = false;
    }
}

void appgravity(Body& b){

    //b.speed.y += 0.5;

    b.pos.y += b.speed.y;

    if (b.oldPositions.size() >= b.MAXOLDPOS){
        b.oldPositions.clear();
    }

    b.oldPositions.push_back(b.pos);

    b.check_touched_ledge();

    if (b.has_touched_low_ledge) {
        b.pos.y = (720 / scale) - b.radius;
        b.speed.y *= -0.7;
    }

    if (b.has_touched_top_ledge) {
        b.pos.y = b.radius;
        b.speed.y *= -0.7;
    }
}