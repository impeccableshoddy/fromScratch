#include "ppm.h"
#include "raytracer.h"

int main(void)
{
    Color canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
    
    const float VIEWPORT_WIDTH  = 1.0f; // Viewport -
    const float VIEWPORT_HEIGHT = 1.0f; // dimensions;
    const float d               = 1.0f; // Projection Plane d;

    Vec3 D;
    Vec3 O = { 0, 0, 0 };

    Sphere S[] = {
        { .center = { 0, -1, 3 }, .rad = 1.0f, .color = {255, 0, 0} },
        { .center = { 2, 0, 4 },  .rad = 1.0f, .color = {0, 0, 255} },
        { .center = { -2, 0, 4 }, .rad = 1.0f, .color = {0, 255, 0} }
    };

    for (int py = 0; py < CANVAS_HEIGHT; py++) {
        for (int px = 0; px < CANVAS_WIDTH; px++)
        {            
            const float Cx = px - CANVAS_WIDTH / 2.0f;
            const float Cy = CANVAS_HEIGHT / 2.0f - py;

            D = canvas_to_viewport(Cx, Cy, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, d);

            Color color = trace_ray(O, D, S, 3, 1.0f, INFINITY);

            put_pixel(canvas, px, py, color);
        }
    }

    write_ppm("output.ppm", canvas);
    printf("\nRendered\n");

    return 0;
}

Vec3 canvas_to_viewport (float Cx, float Cy, float VIEWPORT_WIDTH, float VIEWPORT_HEIGHT, float d)
{
    float Dx = Cx * VIEWPORT_WIDTH / CANVAS_WIDTH;
    float Dy = Cy * VIEWPORT_HEIGHT / CANVAS_HEIGHT;

    return (Vec3){ Dx, Dy, d};
}

float vec3_dot (Vec3 A, Vec3 B) {
    return (float)A.x * B.x + A.y * B.y + A.z * B.z;
}

Vec3 vec3_sub (Vec3 A, Vec3 B) {
    return (Vec3){ A.x - B.x, A.y - B.y, A.z - B.z };
}

void intersect_ray_sphere (Vec3 O, Vec3 D, Sphere *S, float *t1, float *t2)
{
    Vec3 C = S -> center;
    float r = S -> rad;
    
    float a = vec3_dot(D, D);
    float b = 2 * vec3_dot(vec3_sub(O, C), D);
    float c = vec3_dot(vec3_sub(O, C), vec3_sub(O, C)) - r*r;

    float discriminant = b*b - 4 * a * c;

    if (discriminant >= 0) 
    {
        *t1 = (-b + sqrt(discriminant)) / (2 * a);
        *t2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    else *t1 = INFINITY, *t2 = INFINITY;
}

Color trace_ray (Vec3 O, Vec3 D, Sphere *S, int num_of_spheres, float t_min, float t_max) 
{    
    Color BG_COLOR = { 254, 254, 254 };
    
    float closest_t = t_max;
    Sphere *closest_sphere = NULL;
    float t1, t2;

    for (int i = 0; i < num_of_spheres; i++) 
    {
        intersect_ray_sphere(O, D, &S[i], &t1, &t2);

        if (t_min < t1 && t1 < t_max && t1 < closest_t) {
            closest_t = t1;
            closest_sphere = &S[i];
        }
        if (t_min < t2 && t2 < t_max && t2 < closest_t) {
            closest_t = t2;
            closest_sphere = &S[i];
        }
    }

    if (closest_sphere == NULL) return BG_COLOR;

    return closest_sphere -> color;    
}