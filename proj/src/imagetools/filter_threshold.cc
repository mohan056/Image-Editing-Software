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

#include "imagetools/filter_threshold.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {


ThresholdFilter::ThresholdFilter()
  : threshold_(0.5) {}

ThresholdFilter::ThresholdFilter(float threshold)
  : threshold_(threshold) {}

ThresholdFilter::~ThresholdFilter() {}

void ThresholdFilter::SetupFilter() {}

ColorData ThresholdFilter::CalculateFilteredPixel(PixelBuffer *buffer, int x,
  int y) {
  ColorData current_pixel = buffer->pixel(x, y);
  float average = (current_pixel.red() + current_pixel.blue() +
  current_pixel.green())/3;
  // condition to check if average value for pxel is above or below threshold
  if (average > threshold_) {
    ColorData new_pixel = ColorData(1.0, 1.0, 1.0);
    return new_pixel;
  } else {
    ColorData new_pixel = ColorData(0.0, 0.0, 0.0);
    return new_pixel;
  }
}

void ThresholdFilter::CleanUpFilter() {}

}  // namespace image_tools
