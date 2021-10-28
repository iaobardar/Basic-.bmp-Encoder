#include "bmp.h"
#include <math.h>
#include <stdint.h>

double clamp(double x, double min, double max)
{
	return (x < min) ? min : (x > max) ? max : x;
}

#define WIDTH 100
#define HEIGHT 100
#define RADIUS 40.0

int main(int argc, char const *argv[])
{
	uint8_t image[HEIGHT][WIDTH][3] = {0};

	for (uint16_t x = 0; x < WIDTH; ++x)
		for (uint16_t y = 0; y < HEIGHT; ++y)
		{
			double rx = x - (WIDTH / 2.0), ry = y - (HEIGHT / 2.0);
			double dist = sqrt(rx * rx + ry * ry);

			image[y][x][0] = image[y][x][1] = image[y][x][2] = round(clamp(RADIUS - dist, 0, 1) * 255);
		}

	write_bmp24("circle.bmp", WIDTH, HEIGHT, image[0][0]);
	return 0;
}

