#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "constant.h"
#include "view.h"
#include <memory>
#include <vector>



int main() {

    const int HEIGHT = 720;
    const int LENGTH = 1280;

    InitWindow(LENGTH, HEIGHT, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    std::vector<Body> bodies;

    Position pos = {20,20};
    Position pos2 = {30,20};

    Body planet = Body(pos,50,1,Velocity(1,1));
    Body planet2 = Body(pos2,50,1,Velocity(1,1));

    View v;

    bodies.push_back(planet);
    bodies.push_back(planet2);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw(WHITE);
        planet2.draw(BLUE);

        v.DebugInfo(planet,bodies);

        appgravity(planet);
        appgravity(planet2);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}