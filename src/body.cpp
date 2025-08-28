#include <iostream>
#include "body.h"


Body::Body(Position pos, double mass, float radius) : 
pos(pos),mass(mass),radius(radius) {}

void Body::draw(Color color) const {
    int screenX = static_cast<int>(pos.x * scale);
    int screenY = static_cast<int>(pos.y * scale);
    float screenRadius = radius * scale;
    DrawCircle(screenX, screenY, screenRadius, color);
}

void Body::applyGravity(std::vector<Body> bodies) const 
{
    for (auto& b : bodies){
        //code TODO
        std::cout<<"Test"<<"\n";
    }
}

void appgravity(Body& b, int height){

    int posY_b = b.pos.y + b.radius; // Position y of the body

    if (posY_b >= height/scale) {
        b.pos.y--;
    } else {
        b.pos.y++;
    }
}