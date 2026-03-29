#include "ppm.h"

int main(void)
{
    Color pixels[HEIGHT][WIDTH], c = {0, 0, 0}, red = {255, 0, 0};

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++) put_pixel(pixels, x, y, c);

    put_pixel(pixels, WIDTH / 2, HEIGHT / 2, red);

    write_ppm("output.ppm", pixels);
    printf("\nRendered\n");

    return 0;
}