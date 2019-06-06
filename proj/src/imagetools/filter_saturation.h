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

#ifndef IMAGETOOLS_FILTER_SATURATION_H_
#define IMAGETOOLS_FILTER_SATURATION_H_


#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/float_matrix.h"
#include "imagetools/filter.h"

namespace image_tools {

/** @brief This class is resposnible for defining a filter that increases
the saturation of the filter and inherits from Filter class*/
class SaturationFilter : public Filter {
 public:
  SaturationFilter();
  explicit SaturationFilter(float scale);

  virtual ~SaturationFilter();

  void SetupFilter() override;

  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  void CleanUpFilter() override;

 private:
  // private instance variable to store the saturation scale
  float scale_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SATURATION_H_
