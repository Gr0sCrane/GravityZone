#include <iostream>
#include "utils.h"

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