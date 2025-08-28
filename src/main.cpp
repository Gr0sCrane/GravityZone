#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "constant.h"
#include <memory>
#include <vector>

std::vector<Body> bodies;


int main() {

    const int HEIGHT = 720;
    const int LENGTH = 1280;

    InitWindow(LENGTH, HEIGHT, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    Position pos = {10,5};
    Position pos2 = {20,5};

    Body planet = Body(pos,50,1);
    Body planet2 = Body(pos2,50,1);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw(WHITE);
        planet2.draw(BLUE);

        appgravity(planet,HEIGHT);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}