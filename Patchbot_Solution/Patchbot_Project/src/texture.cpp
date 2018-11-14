#include "texture.h"

#include <sstream>
#include <errno.h>
#include <fstream>

#include "exceptions.h"
#include "type_definitions.h"

void read_next_uword(uword& buffer, FILE* file);



Texture::Texture(const Header p_header, const std::vector<Pixel> p_image_data)
	:
	m_header(p_header),
	m_image_data(p_image_data)
{

}

const Texture Texture::load_texture(char * filename)
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

	// read the necessary header info
	ubyte temp_image_id_length = fgetc(input_file);

	ubyte temp_color_map_type = fgetc(input_file);

	ubyte temp_image_type_code = fgetc(input_file);

	uword temp_color_map_origin;
	read_next_uword(temp_color_map_origin, input_file);
	uword temp_color_map_length;
	read_next_uword(temp_color_map_length, input_file);
	ubyte temp_color_map_entry_size = fgetc(input_file);

	uword temp_x_origin;
	read_next_uword(temp_x_origin, input_file);
	uword temp_y_origin;
	read_next_uword(temp_y_origin, input_file);

	uword temp_image_width;
	read_next_uword(temp_image_width, input_file);
	uword temp_image_height;
	read_next_uword(temp_image_height, input_file);

	ubyte temp_bits_per_pixel = fgetc(input_file);

	// create header from input
	Header temp_header = Header(
		temp_image_id_length,
		temp_color_map_type,
		temp_image_type_code,
		temp_color_map_origin,
		temp_color_map_length,
		temp_color_map_entry_size,
		temp_x_origin,
		temp_y_origin,
		temp_image_width,
		temp_image_height,
		temp_bits_per_pixel
	);

	// skip byte with offset 17
	fgetc(input_file);

	// temporal variables for reading the imagedata
	ubyte temp_alpha, temp_red, temp_green, temp_blue;
	std::vector<Pixel> temp_image_data = std::vector<Pixel>();
	temp_image_data.reserve(temp_image_width * temp_image_height);

	// go trough all pixels and read their ARGB values and
	// store them in the temp_image_data vector
	for (int y = 0; y < temp_image_height; y++)
	{
		for (int x = 0; x < temp_image_width; x++)
		{
			temp_alpha = fgetc(input_file);
			temp_red = fgetc(input_file);
			temp_green = fgetc(input_file);
			temp_blue = fgetc(input_file);

			temp_image_data.push_back(
				Pixel( temp_alpha, temp_red, temp_green, temp_blue)
			);
		}
	}

	// free manually allocated memory
	delete(input_file);

	return Texture(temp_header, temp_image_data);
}

void Texture::write_texture_to_file(
	const std::string& p_filename,
	const Texture & p_texture)
{
	// create output-stream
	std::ofstream outputfile(p_filename.c_str(), std::ios::binary);
	if (!outputfile)
	{
		throw Simple_Message_Exception("Cannot open outputstream");
	}

	ubyte raw_header[18] = { 0 };
	Header temp_header = p_texture.get_header();

	// write necessary information to the fileheader
	raw_header[ 2] = temp_header.m_image_type_code;

	raw_header[12] =  temp_header.m_image_width;
	raw_header[13] = (temp_header.m_image_width >> 8) & 0xFF;
	raw_header[14] = temp_header.m_image_height;
	raw_header[15] = (temp_header.m_image_height >> 8) & 0xFF;
	raw_header[16] = temp_header.m_bits_per_pixels;

	outputfile.write((const char*)raw_header, 18);

	// get reference to image-data
	std::vector<Pixel> temp_image_data = p_texture.get_image_data();

	// write the actual image-data
	for (int y = 0; y < temp_header.m_image_height; y++)
	{
		for (int x = 0; x < temp_header.m_image_width; x++)
		{
			Pixel temp_pixel = p_texture.get_pixel_at_position(x, y);
			outputfile.put((char)temp_pixel.m_alpha);
			outputfile.put((char)temp_pixel.m_red);
			outputfile.put((char)temp_pixel.m_green);
			outputfile.put((char)temp_pixel.m_blue);
		}
	}
	

	// Optional file-end 
	static const char file_end[26] =
		"\0\0\0\0"  // no extension area
		"\0\0\0\0"  // no developer directory
		"TRUEVISION-XFILE"  // truevision tag
		".";
	outputfile.write(file_end, 26);
	

	outputfile.close();
}

const Pixel& Texture::get_pixel_at_position(int p_x, int p_y) const
{
	return m_image_data[(p_y * m_header.m_image_height) + p_x];
}

const Header& Texture::get_header() const
{
	return m_header;
}

const std::vector<Pixel>& Texture::get_image_data() const
{
	return m_image_data;
}

void read_next_uword(uword& buffer, FILE* file)
{
	fread(&buffer, 2, 1, file);
}
