#ifndef __TGA_HEADER_H_DEFINED__
#define __TGA_HEADER_H_DEFINED__

#include "type_definitions.h"

// struct storing the implementation relevant information of tga file's header
struct Header
{
	Header(
		ubyte p_image_id_length,
		ubyte p_color_map_type,
		ubyte p_image_type_code,
		uword p_color_map_origin,
		uword p_color_map_length,
		ubyte p_color_map_entry_size,
		uword p_x_origin,
		uword p_y_origin,
		uword p_image_width,
		uword p_image_height,
		ubyte p_bits_per_pixel
	);

	const ubyte m_image_id_length;
	const ubyte m_color_map_type;
	const ubyte m_image_type_code;
	const uword m_color_map_origin;
	const uword m_color_map_length;
	const ubyte m_color_map_entry_size;
	const uword m_x_origin;
	const uword m_y_origin;
	const uword m_image_width;
	const uword m_image_height;
	const ubyte m_bits_per_pixels;
};

#endif
