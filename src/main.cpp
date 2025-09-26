#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "constant.h"
#include "view.h"
#include <memory>
#include <vector>

#define HEIGHT 720
#define LENGTH 1280


int main() {

    
    InitWindow(LENGTH, HEIGHT, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    std::vector<Body> bodies;

    Position pos = {20,20};
    Position pos2 = {30,20};
    Position pos3 = {40,20};

    Body planet = Body(pos,50,1,Velocity2(1,1.2));
    Body planet2 = Body(pos2,50,1,Velocity2(1,1.3));
    Body planet3 = Body(pos3,50,1,Velocity2(1,1.2));

    View v;

    bodies.push_back(planet);
    bodies.push_back(planet2);
    bodies.push_back(planet3);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw(WHITE);
        planet2.draw(BLUE);
        planet3.draw(GREEN);

        v.DebugInfo(planet,planet2);

        appgravity(planet,planet2);
        appgravity(planet2,planet);
        appgravity(planet3,planet);
        appgravity(planet3,planet2);
        appgravity(planet,planet3);
        appgravity(planet2,planet3);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}