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

#include "imagetools/filter_sharpen.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


SharpenFilter::SharpenFilter() {}

SharpenFilter::SharpenFilter(int radius)
  : radius_(radius) {}

SharpenFilter::~SharpenFilter() {}

FloatMatrix* SharpenFilter::CreateKernel() {
  int size = round(radius_ * 2.0) + 1;
  FloatMatrix *kernel = new FloatMatrix(size, size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int x = i - kernel->width() / 2;
      int y = j - kernel->height() / 2;
      float dist = sqrt(x * x + y * y);
      float intensity = ImageToolsMath::Gaussian(dist, radius_);
      kernel->set_value(i, j, intensity);
    }
  }
  kernel->Normalize();
  kernel->Scale(-1.0);

  float middle_value = kernel->value(kernel->width()/ 2, kernel->height() / 2);
  kernel->set_value(kernel->width() / 2, kernel->height() / 2,
                    middle_value + 2.0);
  return kernel;
}


}  // namespace image_tools
