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

#include "imagetools/filter_saturation.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


SaturationFilter::SaturationFilter()
  : scale_(1.0) {}

SaturationFilter::SaturationFilter(float scale)
  : scale_(scale) {}

SaturationFilter::~SaturationFilter() {}

void SaturationFilter::SetupFilter() {}

ColorData SaturationFilter::CalculateFilteredPixel(PixelBuffer *buffer,
  int x, int y) {
  ColorData current_pixel = buffer->pixel(x, y);
  float luminance = current_pixel.Luminance();
  ColorData greyscale_pixel = ColorData(luminance, luminance, luminance);
  // Finding saturated pixel using linear interpolation
  ColorData saturated_pixel = ImageToolsMath::Lerp(greyscale_pixel,
    current_pixel, scale_);
  saturated_pixel.Clamp();
  return saturated_pixel;
}

void SaturationFilter::CleanUpFilter() {}

}  // namespace image_tools
