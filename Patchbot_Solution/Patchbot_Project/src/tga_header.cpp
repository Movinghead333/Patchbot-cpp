#include "tga_header.h"

Header::Header(
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
	ubyte p_bits_per_pixel)
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