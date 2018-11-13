#include "texture.h"

#include <sstream>
#include <string>
#include <errno.h>

#include "exceptions.h"




Header::Header(
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
	uchar p_bits_per_pixel)
	:
	m_image_id_length(p_image_id_length),
	m_color_map_type(p_color_map_type),
	m_image_type_code(p_image_type_code),
	m_color_map_origin(p_color_map_origin),
	m_color_map_length(p_color_map_length),
	m_color_map_entry_size(p_color_map_entry_size),
	m_x_origin(p_x_origin),
	m_y_origin(p_y_origin),
	m_image_width(p_image_width),
	m_image_height(p_image_height),
	m_bits_per_pixels(p_bits_per_pixel)
{
}

Pixel::Pixel(
	uchar p_red,
	uchar p_green,
	uchar p_blue,
	uchar p_alpha)
	:
	m_red(p_red),
	m_green(p_green),
	m_blue(p_blue),
	m_alpha(p_alpha)
{
}

Texture::Texture()
{
}

const Texture Texture::loadTexture(char * filename)
{
	std::cout << "Loading tga-file: " << filename << std::endl;

	// create file-pointer
	FILE* input_file;

	// holds the error code returned from a failed fopen_s
	errno_t err;

	// try to open the input-file if it fails throw an exception
	if ( (err = fopen_s(&input_file, filename, "r")) != 0)
	{
		std::stringstream temp_stream;
		temp_stream << "Could not open file: ";
		temp_stream << filename;
		throw Simple_Message_Exception(temp_stream.str());
	}
	for (int i = 0; i < 50; i++)
	{
		int cb = fgetc(input_file);
		std::cout << i << ": " << cb << std::endl;
	}

	return Texture();
}
