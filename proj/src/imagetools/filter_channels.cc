/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  Daniel Keefe, 2018, UMN -- ported to MinGfx
  ...
*/

#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/filter_channels.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


ChannelsFilter::ChannelsFilter()
  : red_scale_(1.0),
    green_scale_(1.0),
    blue_scale_(1.0) {}

ChannelsFilter::ChannelsFilter(float red, float green, float blue)
  : red_scale_(red),
    green_scale_(green),
    blue_scale_(blue) {}

ChannelsFilter::~ChannelsFilter() {}

void ChannelsFilter::SetupFilter() {}

ColorData ChannelsFilter::CalculateFilteredPixel(PixelBuffer *buffer,
  int x, int y) {
  ColorData current_pixel = buffer->pixel(x, y);

  // scaling each hue in the pixel by the factor given
  float adjusted_red = current_pixel.red() * red_scale_;
  float adjusted_green = current_pixel.green() * green_scale_;
  float adjusted_blue = current_pixel.blue() * blue_scale_;
  ColorData adjusted_pixel = ColorData(adjusted_red, adjusted_green,
    adjusted_blue);
  adjusted_pixel.Clamp();
  return adjusted_pixel;
}

void ChannelsFilter::CleanUpFilter() {}

}  // namespace image_tools
