#include <iostream>
#include <raylib.h>
#include "object.h"

int main() {

    
    InitWindow(1280, 720, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    Position pos = {5,5};

    Object planet = Object(pos,50,50);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello test !", 190, 280, 20, WHITE);
        planet.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}