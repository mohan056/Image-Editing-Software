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

#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_


#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>

#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/float_matrix.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

/** @brief This class is resposnible for defining a filter and */
class Filter {
 public:
  Filter();
  virtual ~Filter();

  /** This function is responsible for taking a pixel buffer and then finding
  the filtered value for the pixel. This method is defined in the subclass */
  void ApplytoBuffer(PixelBuffer *buffer);

  /** This function is responsible for setting up the filter for each subclass
  which is a filter */
  virtual void SetupFilter() = 0;

  /** This function is responsible for calculating the filtered value of
  a pixel. It takes the value of a pixel buffer and the indices' value of
  the pixel and applies the algorithm to the pixel based on the filter. Each
  filter has a different algorthm for calculating the filtered pixel. */
  virtual ColorData CalculateFilteredPixel
  (PixelBuffer *buffer, int x, int y) = 0;

  /** This function is resposible for cleaning up the filter once it is
  implemented and is done being used */
  virtual void CleanUpFilter() = 0;

  /** This function is responsible for checking if we can calculate
  a pixel in its place or not or do we need a kernel to find the filtered
  version of it */
  virtual bool can_calculate_in_place() { return true; }
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_H_
