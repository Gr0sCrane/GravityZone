#pragma once
#include <iostream>
#include <math.h>
#include "body.h"
#include "constant.h"

/* Const */
const double G = (6.67428) * pow(10.0,-11.0);

double calculateDistance(Body b1, Body b2);

bool collisionCheck(Body& b1,Body& b2);