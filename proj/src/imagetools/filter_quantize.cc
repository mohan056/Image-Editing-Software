/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/filter_quantize.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


QuantizeFilter::QuantizeFilter()
  : bin_(1) {}

QuantizeFilter::QuantizeFilter(int bin)
  : bin_(bin) {}

QuantizeFilter::~QuantizeFilter() {}

void QuantizeFilter::SetupFilter() {}

ColorData QuantizeFilter::CalculateFilteredPixel(PixelBuffer *buffer,
  int x, int y) {
  ColorData current_pixel = buffer->pixel(x, y);
  if (bin_ == 1) {
    return current_pixel;
  }
  float red = current_pixel.red();
  float green = current_pixel.green();
  float blue = current_pixel.blue();
  float adjusted_red = red, adjusted_green = green, adjusted_blue = blue;
  int difference = 100/(bin_-1);
  for (int i = 0; i < bin_-1; i++) {
    float lower_bound = difference * i * 0.01;
    float upper_bound = difference * (i+1) * 0.01;
    if ((upper_bound < 1.00f) && (i == bin_-1)) {
      upper_bound = 1.00f;
    }
    // If conditions to check if hue falls in the bin
    if ((red <= upper_bound) && (red >= lower_bound)) {
      if ((upper_bound - red) > (red - lower_bound)) {
        adjusted_red = lower_bound;
      } else {
        adjusted_red = upper_bound;
      }
    }

    if ((green <= upper_bound) && (green >= lower_bound)) {
      if ((upper_bound - green) > (green - lower_bound)) {
        adjusted_green = lower_bound;
      } else {
        adjusted_green = upper_bound;
      }
    }

    if ((blue <= upper_bound) && (blue >= lower_bound)) {
      if ((upper_bound - blue) > (blue - lower_bound)) {
        adjusted_blue = lower_bound;
      } else {
        adjusted_blue = upper_bound;
      }
    }
  }
  ColorData adjusted_pixel = ColorData(adjusted_red, adjusted_green,
    adjusted_blue);
  return adjusted_pixel;
}

void QuantizeFilter::CleanUpFilter() {}

}  // namespace image_tools
