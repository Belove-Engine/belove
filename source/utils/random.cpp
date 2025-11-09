#include "random.hpp"

int get_seed() {
    return seed;
}

void set_seed(long new_seed) {
    srand(new_seed);
}

int rand_range(int min, int max) {
    return rand() % max + min;
}

float rand_frange(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

bool rand_bool() {
    return rand_range(0, 1) ? false : true;
}