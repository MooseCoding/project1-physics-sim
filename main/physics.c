#include "physics.h"

void update_particles(Particle* particles, int number, double time_step, double g, int width, int height) {
    for(int i = 0; i < number; i++) {
        particles[i].vy -= g * time_step;

        particles[i].x += particles[i].vx * time_step;
        particles[i].y += particles[i].vy * time_step;

        if(particles[i].y <= 0 || particles[i].y >= height) {
            particles[i].visible = 0; 
        }
        else {
            particles[i].visible = 1; 
        }

        if(particles[i].x <= 0 || particles[i].x >= width) {
            particles[i].visible = 0; 
        }
        else {
            particles[i].visible = 1; 
        }

        // Electric force time

        double sumeFx = 0; 
        double sumeFy = 0; 

        for(int n = 0; n < number; n++) {
            if (n != i && particles[n].x != particles[i].x) {
                double dx = particles[i].x - particles[n].x;
                sumeFx += (particles[i].charge*particles[n].charge)/dx * 1/dx;

                double dy = particles[i].y - particles[n].y;
                sumeFy += (particles[i].charge*particles[n].charge)/dy * 1/dy;
            }
        }

        particles[i].vx += sumeFx/particles[i].mass * time_step;
        particles[i].vy += sumeFy/particles[i].mass * time_step; 
    }
}
