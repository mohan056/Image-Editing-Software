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

#ifndef IMAGETOOLS_FILTER_MOTION_BLUR_H_
#define IMAGETOOLS_FILTER_MOTION_BLUR_H_


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

/** @brief This class is resposnible for defining a filter and blurs the image
in ine specific direction. It inherits from the Convolutionfilter class. */
class MotionBlurFilter : public ConvolutionFilter {
 public:
  MotionBlurFilter();
  MotionBlurFilter(int radius, std::string dir);

  ~MotionBlurFilter();

  FloatMatrix *CreateKernel() override;

 private:
  /** This function is responsible for creating a kernel that blurs in the east
  to west direction. It is private because it is called by the public
  CreateKernel class. */
  FloatMatrix *CreateEastWestKernel();

  /** This function is responsible for creating a kernel that blurs in the
  north-east to south-west direction. It is private because it is called by
  the public CreateKernel class. */
  FloatMatrix *CreateNorthEastKernel();

  /** This function is responsible for creating a kernel that blurs in the north
  to south direction. It is private because it is called by the public
  CreateKernel class. */
  FloatMatrix *CreateNorthSouthKernel();

  /** This function is responsible for creating a kernel that blurs in the
  north-west to south-east direction. It is private because it is called by
  the public CreateKernel class. */
  FloatMatrix *CreateNorthWestKernel();

  // private instance members to store radius and direction of kernel
  int radius_;
  std::string dir_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_MOTION_BLUR_H_
