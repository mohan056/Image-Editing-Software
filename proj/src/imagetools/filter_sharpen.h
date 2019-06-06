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

#ifndef IMAGETOOLS_FILTER_SHARPEN_H_
#define IMAGETOOLS_FILTER_SHARPEN_H_


#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/color_data.h"
#include "imagetools/filter.h"
#include "imagetools/filter_convolution.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/float_matrix.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

/** @brief This class is resposnible for defining a filter and sharpening
the edges of the image provided. It inherits from class ConvolutionFilter */
class SharpenFilter : public ConvolutionFilter {
 public:
  SharpenFilter();
  explicit SharpenFilter(int radius);

  ~SharpenFilter();

  FloatMatrix *CreateKernel() override;

 private:
  // private instance variable to store the radius of the kernel
  int radius_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SHARPEN_H_
