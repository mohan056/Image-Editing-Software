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

#include "imagetools/filter_motion_blur.h"
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {


MotionBlurFilter::MotionBlurFilter() {}

MotionBlurFilter::MotionBlurFilter(int radius, std::string dir)
  : radius_(radius),
    dir_(dir) {}


MotionBlurFilter::~MotionBlurFilter() {}


FloatMatrix* MotionBlurFilter::CreateKernel() {
  if (dir_ == "North/South") {
    FloatMatrix *kernel = CreateNorthSouthKernel();
    return kernel;
  } else if (dir_ == "East/West") {
    FloatMatrix *kernel = CreateEastWestKernel();
    return kernel;
  } else if (dir_ == "Northeast/Southwest") {
    FloatMatrix *kernel = CreateNorthEastKernel();
    return kernel;
  } else {
    FloatMatrix *kernel = CreateNorthWestKernel();
    return kernel;
  }
}


FloatMatrix *MotionBlurFilter::CreateNorthSouthKernel() {
  FloatMatrix *kernel = new FloatMatrix(radius_);
  int height = kernel->height();
  int width = kernel->width();
  // dividing by height to ensure normalization
  float value = 1.0f/height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // condition for middle column
      if (j != radius_) {
        kernel->set_value(j, i, 0.0f);
      } else {
        kernel->set_value(j, i, value);
      }
    }
  }
  return kernel;
}


FloatMatrix *MotionBlurFilter::CreateEastWestKernel() {
  FloatMatrix *kernel = new FloatMatrix(radius_);
  int height = kernel->height();
  int width = kernel->width();
  // diving by height to ensure normalization
  float value = 1.0f/height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // condition for middle row
      if (i != radius_) {
        kernel->set_value(j, i, 0.0f);
      } else {
        kernel->set_value(j, i, value);
      }
    }
  }
  return kernel;
}


FloatMatrix *MotionBlurFilter::CreateNorthEastKernel() {
  FloatMatrix *kernel = new FloatMatrix(radius_);
  int height = kernel->height();
  int width = kernel->width();
  // dividing by height to ensure normalization
  float value = 1.0f/height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // condition for diagonal
      if ((i+j) != (2*radius_)) {
        kernel->set_value(j, i, 0.0f);
      } else {
        kernel->set_value(j, i, value);
      }
    }
  }
  return kernel;
}


FloatMatrix *MotionBlurFilter::CreateNorthWestKernel() {
  FloatMatrix *kernel = new FloatMatrix(radius_);
  int height = kernel->height();
  int width = kernel->width();
  // dividing by height to ensure normalization
  float value = 1.0f/height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // condition for diagonal
      if (i != j) {
        kernel->set_value(j, i, 0.0f);
      } else {
        kernel->set_value(j, i, value);
      }
    }
  }
  return kernel;
}

}  // namespace image_tools
