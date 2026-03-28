#include <stdio.h>
#include <stdlib.h>

#define ROW 20
#define COLUMN 60

void draw_point(char grid[][COLUMN], int x, int y, char c);
void draw_line(char grid[][COLUMN], int x1, int y1, int x2, int y2, char c);
void render(char grid[][COLUMN]);

int main(void) {

    char grid[ROW][COLUMN];
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) grid[i][j] = ' ';
    }   // or your use memset(grid, ' ', sizeof(grid)); requires <string.h>

    draw_point(grid, 0, COLUMN/2, '0');
    draw_point(grid, ROW/2, 0, '0');
    draw_point(grid, ROW/2, 59, '0');
    draw_point(grid, 19, COLUMN/2, '0');
    
    draw_line(grid, 0, 0, 19, 59, '0');
    draw_line(grid, 0, 59, 19, 0, '0');

    render(grid);

    return 0;
}

void draw_point(char grid[][COLUMN], int x, int y, char c) {
    if (x > -1 && x < ROW && y > -1 && y < COLUMN) grid[x][y] = c;
}

void draw_line(char grid[][COLUMN], int x1, int y1, int x2, int y2, char c) {
    /* int temp;
    
    if(x1 == x2)
    {
        if(y1 > y2) temp = y1, y1 = y2, y2 = temp;
        for(int j = y1; j <= y2; j++) draw_point(grid, x2, j, c);
    }
    else if (y1 == y2)
    {
        if(x1 > x2) temp = x1, x1 = x2, x2 = temp;
        for(int i = x1; i <= x2; i++) draw_point(grid, i, y2, c);
    } */

    int dx = abs(x2 - x1), sx = (x1 < x2) ? 1 : -1;
    int dy = -abs(y2 - y1), sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        draw_point(grid, x1, y1, c);
        if (x1 == x2 && y1 == y2) break;

        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void render(char grid[][COLUMN]) {
    system("clear");
    
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) putchar(grid[i][j]);
        putchar('\n');
    }
}