#include <iostream>
#include <raylib.h>

int main() {
    
    InitWindow(800, 600, "GravityZone-alphaBuild");

    // Définit le nombre de frames par seconde
    SetTargetFPS(60);

    // Boucle principale
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello test !", 190, 280, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}