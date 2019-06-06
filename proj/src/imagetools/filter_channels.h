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

#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_


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

/** @brief This class is resposnible for defining a filter and scaling the
individual values of the red, green and blue. It inherits from the
Filter class*/
class ChannelsFilter : public Filter {
 public:
  ChannelsFilter();
  ChannelsFilter(float red, float green, float blue);

  virtual ~ChannelsFilter();

  void SetupFilter() override;

  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  void CleanUpFilter() override;

 private:
  /** private instance variables to store the scaling factors */
  float red_scale_;
  float green_scale_;
  float blue_scale_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_
