#pragma once
#include <iostream>
#include <raylib.h>
#include "position.h"
#include "constant.h"
#include <vector>

struct Body {

    double mass;
    float radius;
    double velocity;
    double acceleration;
    Position pos;

    Body(Position pos,double mass,float radius);
    ~Body() = default;

    void draw(Color color) const;
    void applyGravity(std::vector<Body> bodies) const;

};

void appgravity(Body& b, int height);