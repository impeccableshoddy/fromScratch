#include "ppm.h"

void put_pixel(Color pixels[][CANVAS_WIDTH], int x, int y, Color c) {
    pixels[y][x] = c;
}

void write_ppm ( const char *filename, Color pixels[][CANVAS_WIDTH])
{
    FILE *file = fopen(filename, "w");
    if (!file) { printf("Error opening file\n"); return; }

    fprintf(file, "P3\n%d %d\n%d\n", CANVAS_WIDTH, CANVAS_HEIGHT, MAX_VAL);

    for (int i = 0; i < CANVAS_HEIGHT; i++)
        for (int j = 0; j < CANVAS_WIDTH; j++)
            fprintf(file, "%d %d %d\n", pixels[i][j].r,
                                        pixels[i][j].g,
                                        pixels[i][j].b);

    fclose(file);
}