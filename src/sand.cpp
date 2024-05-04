#include <raylib.h>

struct GrainOfSand {
    Vector2 pos, spd;
    Color color;
};

GrainOfSand newGrainOfSand(float x, float y, Color color) {
    return GrainOfSand {
        .pos = Vector2 { x, y },
        .spd = Vector2 { 0.0f, 0.0f },
        .color = color
    };
}

void drawGrainOfSand(GrainOfSand grain) {
    DrawPixel(grain.pos.x, grain.pos.y, grain.color);
}
