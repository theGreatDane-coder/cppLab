#include "ppm.h"

#include <string.h>
#include <fstream>
#include <iostream>

namespace graphics
{

	void _skipComment(std::ifstream & file)
	{
		char c;
		do
		{	// remove rest of the line 
			c = file.get();
		} while (c != '\n');
	}

	unsigned char * ReadPPM(const std::string & filename, int * w, int * h)
	{
		std::ifstream file(filename.c_str(), std::ifstream::in | std::ifstream::binary);

		if (!file)
			return nullptr;

		int cur_token = 0;
		char tokens[4][32];
		int pos = 0;

		while (cur_token < 4)
		{
			char c;

			do
			{	// remove empty space 
				c = file.get();
				if (c == '#')
				{
					_skipComment(file);
					break;
				}
			} while (c == ' ' || c == '\t' || c == '\n' || c == '\r');

			do
			{	// write characters to token slot
				tokens[cur_token][pos++] = c;
				c = file.get();
				if (c == '#')
				{
					_skipComment(file);
					break;
				}
			} while (c != ' ' && c != '\t' && c != '\n' && c != '\r' && pos < 32);
			tokens[cur_token][pos] = 0;
			cur_token++;
			pos = 0;

		}

		if (strcmp(tokens[0], "P6") != 0)
		{
			std::string msg;
			msg = std::string(tokens[0]) + " - Error: Unsupported format.";
			std::cerr << msg.c_str() << std::endl;
			file.close();
			return nullptr;
		}

		int width = atoi(tokens[1]);
		if (width == 0)
		{
			std::cerr << "Error: Bad image width." << std::endl;
			file.close();
			return nullptr;
		}

		int height = atoi(tokens[2]);
		if (height == 0)
		{
			std::cerr << "Error: Bad image height." << std::endl;
			file.close();
			return nullptr;
		}

		int max_val = atoi(tokens[3]);
		if (max_val > 255)
		{
			std::cerr << "Error: Only 8bit per pixel images are supported." << std::endl;
			file.close();
			return nullptr;
		}

		// header ok, read image chunk
		size_t sz = width * height * 3;
		unsigned char * buffer = new unsigned char[sz];

		file.read((char*)buffer, sz);
		size_t count = size_t(file.gcount());
		if (count < sz)
		{
			std::cerr << "Error: Could not read all pixels.\n";
			file.close();
			delete[] buffer;
			return nullptr;
		}

		file.close();

		*w = width;
		*h = height;
		return buffer;
	}


	bool WritePPM(const unsigned char * data, int w, int h, std::string filename)
	{
		std::ofstream file(filename.c_str(), std::ofstream::out | std::ofstream::binary);

		if (!file)
			return false;

		// write header;
		file << "P6" << " " << w << " " << h << " 255 ";

		//prepare data for output
		size_t sz = 3 * w * h;
				
		file.write((char*)data, sz);
		file.close();

		return true;
	}
}