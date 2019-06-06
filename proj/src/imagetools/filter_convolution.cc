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

#include "imagetools/filter_convolution.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


ConvolutionFilter::ConvolutionFilter() {}


ConvolutionFilter::~ConvolutionFilter() {}


void ConvolutionFilter::SetupFilter() {
  kernel_ = CreateKernel();
}


ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer *buffer, int x,
  int y) {
  ColorData new_pixel = ColorData(0.0f, 0.0f, 0.0f);
  int buffer_width = buffer->width();
  int buffer_height = buffer->height();
  int kernel_height = kernel_->height();
  int kernel_width = kernel_->width();
  for (int i = 0; i < kernel_height; i++) {
    for (int j = 0; j < kernel_width; j++) {
      // finding pixel value for the pixel i and j distant from center
      int other_pixel_x = x - (kernel_height-1)/2 + i;
      int other_pixel_y = y - (kernel_width-1)/2 + j;
      float kernel_value = kernel_->value(i, j);
      // checks for edge cases when pixel given is on the edge or corner
      bool check_1 = (other_pixel_x >= 0);
      bool check_2 = (other_pixel_y >= 0);
      bool check_3 = (other_pixel_x < buffer_width);
      bool check_4 = (other_pixel_y < buffer_height);
      if (check_1 && check_2 && check_3 && check_4) {
        ColorData other_pixel = buffer->pixel(other_pixel_x, other_pixel_y);
        new_pixel = new_pixel + (other_pixel * kernel_value);
      }
    }
  }
  new_pixel.Clamp();
  return new_pixel;
}

void ConvolutionFilter::CleanUpFilter() {
  delete kernel_;
  kernel_ = NULL;
}

}  // namespace image_tools
