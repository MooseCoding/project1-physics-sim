#ifndef PHYSICS_H
#define PHYISCS_H

typedef struct {
    double x,y; // m 
    double vx, vy; // m/s
    double mass; // kg
    double charge; // c
    bool visible; 
} Particle;

void update_particle(Particle* particles, int number, double time_step, double g, int width, int height);

#endif 