#include <stdlib.h>
#include <Random.hpp>

int Random::Range(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float Random::Range(float min, float max)
{
    return (max - min) * ((float)rand() / RAND_MAX) + min;
}