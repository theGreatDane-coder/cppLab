#pragma once
// Βοηθητικές συναρτήσεις για τον κώδικα της main.

float RandomFloat();
// Επιστρέφει έναν ψευδοτυχαίο δεκαδικό αριθμό στο διάστημα [-1,1]

int   RandomInt();
// Επιστρέφει έναν ψευδοτυχαίο φυσικό αριθμό στο διάστημα [0,RAND_MAX]

template <int N>
unsigned int RandomInteger()
// Επιστρέφει έναν ψευδοτυχαίο φυσικό αριθμό στο διάστημα [0,N-1]
{
	return  (unsigned int) RandomInt() % N;
}

void SetRandomSeed(int seed);
// Αρχικοποιεί τη γεννήτρια τυχαίων αριθμών.