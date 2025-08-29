#pragma once
#include <iostream>
#include <raylib.h>
#include "position.h"
#include "constant.h"
#include <vector>

struct Velocity {
    double x = 0;
    double y;
};

struct Body {

    double mass;
    float radius;
    Velocity speed;
    double acceleration;
    Position pos;
    bool has_touched_top_ledge = false;
    bool has_touched_low_ledge = false;
    std::vector<Position> oldPositions;
    const size_t MAXOLDPOS = 300;

    Body(Position pos,double mass,float radius);
    ~Body() = default;

    void draw(Color color) const;
    void applyGravity(std::vector<Body> bodies) const;
    void check_touched_ledge();

};

void appgravity(Body& b);