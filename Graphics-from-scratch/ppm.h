#ifndef PPM_H
#define PPM_H

#include <stdio.h>

#define MAX_VAL 255
#define WIDTH 800
#define HEIGHT 600

typedef struct { int r, g, b; } Color;

void put_pixel(Color pixels[][WIDTH], int x, int y, Color c);
void write_ppm ( const char *filename, Color pixels[][WIDTH]);

#endif