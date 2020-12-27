#include "misc.h"

int coin(int min, int max) {
	int offset = rand() % (max-min);
	return min+offset;
}