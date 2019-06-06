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

#include "imagetools/filter_edge_detect.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


EdgeDetectFilter::EdgeDetectFilter() {}

EdgeDetectFilter::~EdgeDetectFilter() {}

FloatMatrix* EdgeDetectFilter::CreateKernel() {
  FloatMatrix *kernel = new FloatMatrix(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      kernel->set_value(i, j, -1.0f);
    }
  }

  // setting the value of the middle spot in the kernel so that it adds to 0
  kernel->set_value(1, 1, 8.0f);
  return kernel;
}


}  // namespace image_tools
