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

#ifndef IMAGETOOLS_FILTER_CONVOLUTION_H_
#define IMAGETOOLS_FILTER_CONVOLUTION_H_


#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/color_data.h"
#include "imagetools/filter.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/float_matrix.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

/** @brief This class is resposnible for defining a convolution filter. It
builds seperate other filter subclasses. It inherits from the filter class. */
class ConvolutionFilter : public Filter {
 public:
  ConvolutionFilter();
  ~ConvolutionFilter();

  /** This function is responsible for creating a kernel which we plan on using
  later on when we calculate the value for a filtered pixel. */
  virtual FloatMatrix *CreateKernel() = 0;

  void SetupFilter() override;

  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  void CleanUpFilter() override;

  bool can_calculate_in_place() override { return false; }

 private:
  /** private instance variable for creating the kernel */
  FloatMatrix* kernel_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CONVOLUTION_H_
