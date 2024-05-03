#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 800;
const int targetFPS = 60;

void loop();

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(screenWidth, screenHeight, "SandSimulation");
    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) loop();
    CloseWindow();

    return 0;
}

void loop() {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
}
