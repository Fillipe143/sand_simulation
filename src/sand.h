#include <raylib.h>

struct GrainOfSand {
    Vector2 pos, spd;
    Color color;
};

GrainOfSand newGrainOfSand(float x, float y, Color color);
void drawGrainOfSand(GrainOfSand grain);
