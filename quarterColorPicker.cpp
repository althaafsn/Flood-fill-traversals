/**
 * @file quarterColorPicker.cpp
 * @description Implements the QuarterColorPicker constructor and () function
 *              for CPSC 221 PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "quarterColorPicker.h"

QuarterColorPicker::QuarterColorPicker(PNG& inputimg, unsigned char b_amount)
{
    // Complete your implementation below
	referenceimg = inputimg;
    brightamount = b_amount;
}

/**
 * Picks the color for pixel (x, y).
 *
 * Using the private reference image, scale each dimension by half
 * and tile the smaller image in a 2 x 2 grid over the original dimensions
 * of the image, and return the pixel at the appropriate coordinate from
 * the tiled image, brightened on each R/G/B channel by the required amount.
 * 
 * The value of each pixel in the scaled image will be a bilinear interpolation
 * of a 2x2 pixel region from the original image, with each of the R/G/B/A channels
 * processed individually. Interpolate over the x-axis before the y-axis.
 * Truncate any fractional values on the R/G/B channels. Brighten each color channel
 * as the final step.
 * 
 * @pre referenceimg width and height are both even
 */
RGBAPixel QuarterColorPicker::operator()(PixelPoint p)
{
    // Replace the line below with your implementation
    // return RGBAPixel();

    RGBAPixel result;
    unsigned char avg_red;
    unsigned char avg_green;
    unsigned char avg_blue;
    unsigned char avg_alpha;

    RGBAPixel *top_left = referenceimg.getPixel(((p.x * 2) % referenceimg.width()), ((p.y * 2) % referenceimg.height()));
    RGBAPixel *top_right = referenceimg.getPixel(((p.x * 2) % referenceimg.width()) + 1, ((p.y * 2) % referenceimg.height()));
    RGBAPixel *bot_left = referenceimg.getPixel(((p.x * 2)% referenceimg.width()), ((p.y * 2) % referenceimg.height()) + 1);
    RGBAPixel *bot_right = referenceimg.getPixel(((p.x * 2) % referenceimg.width()) + 1, ((p.y * 2) % referenceimg.height()) + 1);
    avg_red = (top_left->r + top_right->r + bot_left->r + bot_right->r) / 4;
    avg_green = (top_left->g + top_right->g + bot_left->g + bot_right->g) / 4;
    avg_blue = (top_left->b + top_right->b + bot_left->b + bot_right->b) / 4;
    avg_alpha = (top_left->a + top_right->a + bot_left->a + bot_right->a) / 4;
    
    result = RGBAPixel(min(avg_red + brightamount, 255), min(avg_green + brightamount, 255), min(avg_blue + brightamount, 255), avg_alpha);
    return result;

}

/**
 * Add your private QuarterColorPicker function implementations below
 */
