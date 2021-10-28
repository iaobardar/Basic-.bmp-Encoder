#include "bmp.h"

#include <stdint.h>
#include <stdio.h>

int write_bmp24(const char* filename, uint16_t width, uint16_t height, uint8_t* pixel_data)
{
	FILE* bmp_file = fopen(filename, "w");
	if (!bmp_file)
		return 0;

	// file header
	uint8_t header[14] = {0x42, 0x4D};
	header[2] = (uint32_t)(14 + 12 + width * height * 3);
	header[10] = (uint32_t)(14 + 12);
	fwrite(header, sizeof(uint8_t), 14, bmp_file);

	// bitmap info header
	uint8_t info[12] = {0};
	info[0] = (uint32_t) 12;
	info[4] = width;
	info[6] = height;
	info[8] = (uint16_t) 1;
	info[10] = (uint16_t) 24;
	fwrite(info, sizeof(uint8_t), 12, bmp_file);

	// pixel array
	uint8_t row_padding = 3 - (3*width-1)%4;
	
	uint8_t* pix = pixel_data;
	for (uint16_t y = 0; y < height; ++y)
	{
		fwrite(pix, sizeof(uint8_t), width * 3, bmp_file);
		for (int i = 0; i < row_padding; i++)
			putc(0, bmp_file);
		pix += width * 3;
	}

	fclose(bmp_file);
}