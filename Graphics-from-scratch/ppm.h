#ifndef PPM_H
#define PPM_H

#include <stdio.h>
#include <math.h>

#define MAX_VAL 255
#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 600

typedef struct { int r, g, b; } Color;
typedef struct { float x, y, z; } Vec3;

void put_pixel(Color pixels[][CANVAS_WIDTH], int x, int y, Color c);
void write_ppm ( const char *filename, Color pixels[][CANVAS_WIDTH]);

#endif