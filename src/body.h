#pragma once
#include <iostream>
#include <raylib.h>
#include "position.h"

struct Body {

    double mass;
    float radius;
    double velocity;
    double acceleration;
    Position pos;

    Body(Position pos,double mass,float radius);
    ~Body() = default;

    void draw() const;
    void applyGravity() const;

};