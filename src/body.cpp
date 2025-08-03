#include <iostream>
#include "body.h"

int cellSize = 30;
int cellCount = 25;

Body::Body(Position pos, double mass, float radius) : 
pos(pos),mass(mass),radius(radius) {}

void Body::draw() const {
    DrawCircle(pos.x * cellSize, pos.y * cellSize, radius,WHITE);
}

void Body::applyGravity() const {}