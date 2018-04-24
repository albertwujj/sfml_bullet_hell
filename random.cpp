#include <random>
#include <windows.h>

//reference: https://stackoverflow.com/questions/9471604/what-is-the-best-way-to-generate-random-numbers-in-c

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 1000000);
rng_type rng;

void seedRand() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	rng_type::result_type const seedval = li.LowPart; // get this from somewhere
	rng.seed(seedval);
}
int getRand() {
	

	rng_type::result_type random_number = udist(rng);

	return random_number;
}