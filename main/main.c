#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "physics.h"

int main() {
    char buffer[100]; 
    printf("How many iterations of particles would you like?\n");
    int n = 0;
    scanf("%d", &n);
    printf("\nRunning particle motion with the particle list in the code.\n");

    Particle* particles = (Particle*)malloc(sizeof(Particle) * 10);

    for (int i = 0; i < 10; i++) {
        particles[i] = (Particle){10, 10, 0, 0, 10, -5, true};
    }

    for (int i = 0; i < n; i++) {
        update_particles(particles, 10, 1, 9.8, 100, 100);
    }

    return 0; 
}