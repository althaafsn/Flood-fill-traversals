/**
 * @file borderColorPicker.cpp
 * @description Implements the BorderColorPicker constructor and () function
 *              for CPSC 221 PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "borderColorPicker.h"

/**
 * Constructs a new BorderColorPicker.
 *
 * @param width        Number of pixels to color around border.
 * @param inputimage   Image for referencing original image colors.
 * @param bcolor       Color to be used for painting the fill border.
 * @param tol          Tolerance used to determine the border of the fill.
 */
BorderColorPicker::BorderColorPicker(unsigned int width, PNG& inputimage, RGBAPixel scolor, RGBAPixel bcolor, double tol)
{
    // Complete your implementation below
	borderwidth = width; // Number of pixels to use for border
    img = inputimage;                  // Original image used in flood fill algorithm
    seedcolor = scolor;      // Color of seed point, for checking fill region
	bordercolor = bcolor;    // Color used for painting the fill border
    tolerance = tol;         // Tolerance used in flood fill algorithm
}

/**
 * Picks the color for pixel at point. If the x or y coordinate is
 * at or within an Euclidean radius of borderwidth pixels from the border of
 * the fill region, it will be colored with the required border color.
 * Otherwise, its color will not be changed.
 *
 * @param p   The point for which you're picking a color.
 * @return    The color chosen for (p).
 */
RGBAPixel BorderColorPicker::operator()(PixelPoint p)
{
    // Replace the line below with your implementation
    return RGBAPixel();

    // if (p.x == 0 || p.y == 0)
}

/**
 * Add your private BorderColorPicker function implementations below
 */
