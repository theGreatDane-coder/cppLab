#include "Rand.h"
#include <cstdlib>

// Βοηθητικές συναρτήσεις για τον κώδικα της main.

void SetRandomSeed(int seed)
{
	srand(seed);
}

float RandomFloat()
{
	return 2.0f *rand() / (float)RAND_MAX - 1.0f;
}

int RandomInt()
{
	return rand();
}