#pragma once
#include <string>

namespace graphics
{
	/*! Reads a PPM image file and returns a pointer to a newly allocated unsigned char array containing the image data. 
	 *
	 *  Values in the returned array are in the range [0,255] and for each pixel, three values are stored.
	 *
	 *  \param filename is the string of the name of the file to open.
	 *
	 *  \param w is the address of an integer parameter to return the width of the image into.
	 *
	 *  \param h is the address of an integer parameter to return the height of the image into.
	 *  
	 *  \return a pointer to a new unsigned char array of size 3 X w X h, that contains the image data. 
	 *  If the reading operation fails, the function returns nullptr. 
	 *
	 *  The data in the return buffer are stored in RGB (red,green,blue) triplets, one image row after the other:
	 *
	 *  |--- return_addr
	 *  V
	 *  |------------------- row 0 ------------------------| |-------------------- row 1 -----------------------| ...
	 *    col 0     col 1                           col w-1    col 0     col 1                           col w-1 
	 *  [R, G, B] [R, G, B] ...                    [R, G, B] [R, G, B] [R, G, B] ...                    [R, G, B] ...
	 *  
	 *  Therefore, the red, green and blue values for pixel (col,row) are obtained by:
	 *
	 *  val = return_addr[row*w*3 + col*3 + c], c = 0,1,2 for red, green and blue, respectively
	 *
	 */
	unsigned char * ReadPPM(const std::string & filename, int * w, int * h );

	/*! Writes an image buffer as a PPM file.
	*
	*  \param data contains the image buffer. The data are RGB unsigned char tripplets with values in the range [0,255].
	*  In total, w X h X 3 bytes are expected.
	*
	*  \param w is the width of the image in pixels.
	*
	*  \param h is the height of the image in pixels.
	*
	*  \param filename is the name of the file to create.
	*
	*  \return true if the image save operation was successful, false otherwise. If the data parameter is nulltr, the 
	*  function returns immediately with a false return value.
	*/
	bool WritePPM(const unsigned char * data, int w, int h, std::string filename);

} //namespace graphics

