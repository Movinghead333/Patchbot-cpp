#ifndef __TEXTURE_H_DEFINED__
#define __TEXTURE_H_DEFINED__

#include <vector>
#include <iostream> // debug

typedef unsigned char uchar;

struct Header
{
	Header(
		uchar p_image_id_length,
		uchar p_color_map_type,
		uchar p_image_type_code,
		uchar p_color_map_origin,
		uchar p_color_map_length,
		uchar p_color_map_entry_size,
		uchar p_x_origin,
		uchar p_y_origin,
		uchar p_image_width,
		uchar p_image_height,
		uchar p_bits_per_pixel
	);

	const uchar m_image_id_length;
	const uchar m_color_map_type;
	const uchar m_image_type_code;
	const uchar m_color_map_origin;
	const uchar m_color_map_length;
	const uchar m_color_map_entry_size;
	const uchar m_x_origin;
	const uchar m_y_origin;
	const uchar m_image_width;
	const uchar m_image_height;
	const uchar m_bits_per_pixels;
};

struct Pixel
{
	Pixel(
		uchar p_red,
		uchar p_green,
		uchar p_blue,
		uchar p_alpha
	);

	const uchar m_red;
	const uchar m_green;
	const uchar m_blue;
	const uchar m_alpha;
};

class Texture
{
public:
	Texture();

	static const Texture loadTexture(char* filename);

private:
	//Header m_header;
	//std::vector<Pixel> m_pixels;
};

#endif 
