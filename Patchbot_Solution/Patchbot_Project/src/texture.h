#ifndef __TEXTURE_H_DEFINED__
#define __TEXTURE_H_DEFINED__

#include <vector>
#include <iostream> // debug
#include <string>

#include "pixel.h"

// stores the important header and data information from a tga-file in
// suited data-structure
class Texture
{
public:
	// creates a Texture object by passing a width and height of the image
	// as well as a Pixel-vector holding the image-data
	Texture(int p_width, int p_height, const std::vector<Pixel>& p_image_data);

	// load Texture from filename
	static const Texture load_texture(const std::string& p_filename);

	// write a texture to a tga file in local directory
	static void write_texture_to_file(
		const std::string& filename,
		const Texture& p_texture);

	// get Pixel object at given (x, y)-position
	const Pixel& get_pixel_at_position(int p_x, int p_y) const;

	// getter methods
	int get_width();
	int get_height();

	const std::vector<Pixel>& get_image_data() const;

private:
	// width and height of the image
	const int m_image_width;
	const int m_image_height;

	// stores every pixel from the input image in an ARGB Pixelobject
	std::vector<Pixel> m_image_data; 
};

#endif 
