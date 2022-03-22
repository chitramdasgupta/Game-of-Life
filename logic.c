#include <stdlib.h>
#include <time.h>
#include "logic.h"
#include "constants.h"

int ** generate_random_world() {
    int **world = (int **) malloc(N * sizeof(int *)); 

    for (int i = 0; i < N; i++) {
        world[i] = (int *) malloc(N * sizeof(int));
    }

    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            world[i][j] = rand() % 2;

            // For oscillator:
            // if(i == 9 && (j == 8 || j == 9 || j == 10)) {
            //     world[i][j] = 1;
            // } else {
            //     world[i][j] = 0;
            // }
        }
    }

    return world;
}

int number_of_alive_neighbours(int ** world, int i, int j) {
    int count = 0;
    if(j-1 >= 0 && i-1 >= 0 && world[i-1][j-1] == 1)
        count += 1;
    if(j >= 0 && j <= N-1 && i-1 >= 0 && world[i-1][j] == 1)
        count += 1; 
    if(j+1 <= N-1 && i-1 >=0 && world[i-1][j+1] == 1)
            count += 1;
    if(j-1 >= 0 && i >= 0 && i <= N-1 && world[i][j-1] == 1)
            count += 1;
    if(j+1 <= N-1 && i >=0 && i <= N-1 && world[i][j+1] == 1)
            count += 1;
    if(j-1 >= 0 && i+1 <= N-1 && world[i+1][j-1] == 1)
        count += 1;
    if(j >= 0 && i+1 <= N-1 && world[i+1][j] == 1)
        count += 1; 
    if(j+1 <= N-1 && i+1 <= N-1 && world[i+1][j+1] == 1)
            count += 1;

    return count;
}

void update_world_state(int ** world, int ** new_world) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int alive_neighbours = number_of_alive_neighbours(world, i, j);
            if(alive_neighbours < 2 && world[i][j] == 1) {
                new_world[i][j] = 0;
            } else if(alive_neighbours >= 4 && world[i][j] == 1) {
                new_world[i][j] = 0;
            } else if((alive_neighbours == 2 || alive_neighbours == 3) && world[i][j] == 1) {
                new_world[i][j] = 1;
            } else if(alive_neighbours == 3 && world[i][j] == 0) {
                new_world[i][j] = 1;
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            world[i][j] = new_world[i][j];
        }
    }

}
