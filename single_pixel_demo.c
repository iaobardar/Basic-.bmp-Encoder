#include "bmp.h"
#include <stdint.h>

int main(int argc, char const *argv[])
{
	uint8_t image[1][1][3] = {128, 128, 128};
	write_bmp24("pixel.bmp", 1, 1, image[0][0]);
	return 0;
}