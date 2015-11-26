
#include "aw-prng.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fd = fopen("prng.gray", "wb");
	int seed = 0;
	int x, y;

	(void) argc;
	(void) argv;

	for (y = 0; y < 1024; ++y)
	for (x = 0; x < 1024; ++x)
		fputc((int) (prng_zero_to_one(&seed, 0) * 255.f), fd);

	fclose(fd);
	return 0;
}

