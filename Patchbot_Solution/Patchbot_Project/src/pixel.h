#ifndef __PIXEL_H_DEFINED__
#define __PIXEL_H_DEFINED__

#include "type_definitions.h"

// struct storing alpha, red, green and blue values of a Pixel
struct Pixel
{
	Pixel(
		ubyte p_alpha,
		ubyte p_red,
		ubyte p_green,
		ubyte p_blue
	);

	const ubyte m_alpha;
	const ubyte m_red;
	const ubyte m_green;
	const ubyte m_blue;
};

#endif