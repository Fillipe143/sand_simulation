#include <cmath>
#include <cstdlib>
#include <raylib.h>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;
const int targetFPS = 60;

struct Grain {
    int spd;
    Color color;
};

const int gridWidth = 100;
const int gridHeight = 100;
Grain pixels[gridWidth][gridHeight];
void loop();

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(screenWidth, screenHeight, "SandSimulation");
    SetTargetFPS(targetFPS);

    while (!WindowShouldClose()) loop();
    CloseWindow();

    return 0;
}

int hue = 0;
void loop() {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        // grains.push_back(newGrainOfSand(GetMouseX(), GetMouseY(), ColorFromHSV(hue, 1.0f, 1.0f)));
        int x = GetMouseX() / 8;
        int y = GetMouseY() / 8;
        if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
            if (pixels[x][y].color.a == 0) {
                pixels[x][y] = Grain { 0, ColorFromHSV(hue, 0.4f, 0.85f) };
            }
        }
        //hue = (hue + 1) % 360;
        hue = 20 + rand() % 40;
    }

    for (int x = gridWidth - 1; x >= 0; x--) {
        for (int y = gridHeight - 2; y >= 0; y--) {
            Grain grain = pixels[x][y];
            if (grain.color.a == 0) continue;
            if (pixels[x][y + 1].color.a == 0) {
                if (rand() % 2) {
                    if (rand() % 10 == 0 && x < gridWidth - 1 && pixels[x + 1][y].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x + 1][y + 1] = grain;
                    } else {
                        pixels[x][y].color.a = 0;
                        pixels[x][y + 1] = grain;
                    }
                } else {
                    if (rand() % 10 == 0 && x > 0 && pixels[x - 1][y].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x - 1][y + 1] = grain;
                    } else {
                        pixels[x][y].color.a = 0;
                        pixels[x][y + 1] = grain;
                    }
                }
            } else {
                if (rand() % 2) {
                    if (x < gridWidth - 1 && pixels[x + 1][y + 1].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x + 1][y + 1] = grain;
                    } else if (x > 0 && pixels[x - 1][y + 1].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x - 1][y + 1] = grain;
                    }
                } else {
                    if (x > 0 && pixels[x - 1][y + 1].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x - 1][y + 1] = grain;
                    } else if (x < gridWidth - 1 && pixels[x + 1][y + 1].color.a == 0) {
                        pixels[x][y].color.a = 0;
                        pixels[x + 1][y + 1] = grain;
                    }
                }
            }
        }
    }

    // for (auto &grain : grains) {
    //     grain.spd.y = fmod(grain.spd.y + 10.0f / 60,  100.0f);
    //     grain.pos.y += grain.spd.y;
    //     if (grain.pos.y >= screenHeight - 1) grain.pos.y = screenHeight -1;
    // }

    BeginDrawing();
    ClearBackground(BLACK);
    // Render grains
    // for (auto grain : grains) drawGrainOfSand(grain);
    int width = screenWidth / gridWidth;
    int height = screenHeight / gridHeight;
    for (int x = 0; x < gridWidth; x++) {
        for (int y = 0; y < gridHeight; y++) {
            // DrawPixel(x, y, pixels[x][y].color);
            DrawRectangle(x * width, y * height, width, height, pixels[x][y].color);
        }
    }
    DrawFPS(0, 0);
    EndDrawing();
}
