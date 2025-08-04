#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "constant.h"


int main() {

    InitWindow(1280, 720, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    Position pos = {10,5};
    Position pos2 = {20,5};

    Body planet = Body(pos,50,1);
    Body planet2 = Body(pos2,50,2);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw(WHITE);
        planet2.draw(BLUE);

        if (collisionCheck(planet,planet2)){
            std::cout<< "Yes" << "\n";
        } else {
            std::cout << "No" << "\n";
        }
        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}