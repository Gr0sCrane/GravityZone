#pragma once
#include <iostream>
#include <raylib.h>
#include "position.h"

struct Object {

    double size;
    double mass;
    float radius;
    double speed;
    double acceleration;
    Position pos;

    Object(Position pos,double mass,float radius);
    ~Object() = default;

    void draw() const;

    Position getPosition() const;
    double getMass() const;
    float getRadius() const;

};