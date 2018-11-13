#ifndef __TEXTURE_H_DEFINED__
#define __TEXTURE_H_DEFINED__

#include <vector>
#include <iostream> // debug
#include <string>

#include "tga_header.h"
#include "pixel.h"

class Texture
{
public:
	Texture(const Header p_header, const std::vector<Pixel> p_image_data);

	static const Texture load_texture(char* filename);

	static void write_texture_to_file(
		const std::string& filename,
		const Texture& p_texture);

	const Pixel& get_pixel_at_position(int p_x, int p_y) const;

	const Header& get_header() const;

	const std::vector<Pixel>& get_image_data() const;

private:
	// stores the header-information from the tga-file
	Header m_header;

	// stores every pixel from the input image in an ARGB Pixelobject
	std::vector<Pixel> m_image_data; 
};

#endif 
