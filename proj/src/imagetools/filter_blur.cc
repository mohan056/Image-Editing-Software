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

#include "imagetools/filter_blur.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


BlurFilter::BlurFilter() {}

BlurFilter::BlurFilter(int radius)
  : radius_(radius) {}

BlurFilter::~BlurFilter() {}

FloatMatrix* BlurFilter::CreateKernel() {
  FloatMatrix *kernel = new FloatMatrix(radius_);
  int height = kernel->height();
  int width = kernel->width();
  float height_center = (height - 1)/2;
  float width_center = (width - 1)/2;
  // initializing the sum to 0
  float sum = 0.0f;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // finding the gaussian value for indices using center as mean
      float value_x = ImageToolsMath::Gaussian((i-height_center), radius_);
      float value_y = ImageToolsMath::Gaussian((j-width_center), radius_);
      kernel->set_value(i, j, (value_x * value_y));
      sum += (value_x * value_y);
    }
  }
  kernel->Normalize();
  return kernel;
}


}  // namespace image_tools
