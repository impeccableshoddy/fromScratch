#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "ppm.h"

typedef struct 
    {
        Vec3 center;
        float rad;
        Color color;
        
    } Sphere;   // Struct defining the properties of a sphere;

float vec3_dot  (Vec3 A, Vec3 B);   // Computes dot product of two 3D vectors;
Vec3 vec3_sub   (Vec3 A, Vec3 B);   // Subracts two 3D vectors;

Color trace_ray (Vec3 O, Vec3 D, Sphere *S, int num_of_spheres, float t_min, float t_max);

// Scales pixel points in Canvas ( new axis orientation ) to real world units and gives direction to the ray.
Vec3 canvas_to_viewport   (float Cx, float Cy, float VIEWPORT_WIDTH, float VIEWPORT_HEIGHT, float d);

// Find the point of intersection t (value / values) between the ray coming from the viewport and the objects on canvas.
void intersect_ray_sphere (Vec3 O, Vec3 D, Sphere *S, float *t1, float *t2);

#endif