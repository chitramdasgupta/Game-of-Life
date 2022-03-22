#ifndef LOGIC_H_
#define LOGIC_H_

#include "constants.h"

int ** generate_random_world();

int number_of_alive_neighbours(int ** world, int i, int j);

void update_world_state(int ** world, int ** new_world);

#endif
