#include <iostream>
#include "object.h"

int cellSize = 30;
int cellCount = 25;

Object::Object(Position pos, double mass, float radius) : 
pos(pos),mass(mass),radius(radius) {}

void Object::draw() const {
    DrawCircle(pos.x * cellSize, pos.y * cellSize, radius,WHITE);
}

Position Object::getPosition() const {
    return pos;
}

double Object::getMass() const {
    return mass;
}

float Object::getRadius() const {
    return radius;
}