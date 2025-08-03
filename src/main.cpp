#include <iostream>
#include <raylib.h>
#include "body.h"
#include "utils.h"

int main() {

    InitWindow(1280, 720, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    Position pos = {5,5};
    
    std::cout << G << "\n";

    Body planet = Body(pos,50,50);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}