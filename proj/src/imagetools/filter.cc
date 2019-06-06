/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#include "imagetools/filter.h"
#include <assert.h>
#include <algorithm>
#include <cmath>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

Filter::Filter() {}

Filter::~Filter() {}

void Filter::ApplytoBuffer(PixelBuffer* buffer) {
  // setting up the filter
  SetupFilter();
  int width = buffer->width();
  int height = buffer->height();
  // checking if it is a simple filter or not
  if (!(can_calculate_in_place())) {
    PixelBuffer *new_buffer = new PixelBuffer(*buffer);
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        ColorData new_pixel = CalculateFilteredPixel(new_buffer, i, j);
        buffer->set_pixel(i, j, new_pixel);
      }
    }
    delete new_buffer;
  } else {
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        ColorData new_pixel = CalculateFilteredPixel(buffer, i, j);
        buffer->set_pixel(i, j, new_pixel);
      }
    }
  }
  // cleaning up filter
  CleanUpFilter();
}

}  // namespace image_tools
