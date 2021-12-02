#pragma once

namespace graphics {
    class ImageStorageTraits {
    protected:
        // Data buffer to contain the raw pixel values of the image
        unsigned char* data = nullptr;

        // The width of the image, in pixels
        int width = 0;

        // The height of the image, in pixels
        int height = 0;

        /*! Returns the buffer location in "data" of the pixel at position (x,y)
		 *
		 *  \return a pointer to the location in the buffer where the requested R,G,B pixel values start.
		 *  The RED color value for the pixel is at the returned memory offset ret_addr, the GREEN value 
		 *  is at the next byte (ret_addr+1) and the BLUE value is next to the GREEN one (ret_addr+2) 
		 *
		 *  \param x is the horizontal coordinate of the pixel (zero-based). Valid values: [0,width-1].
		 *  \param y is the vertical coordinate of the pixel (zero-based). Valid values: [0,height-1].
		 *
		 *  Remark: No bounds are checked. x and y are assumed to be correctly within image extents.
		 *
		 */
        unsigned char* pixel(unsigned int x, unsigned int y) {
            return data + 3 * (width * y + x);
        }
    };
} // namespace graphics