/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#include "imagetools/pixel_buffer.h"
#include <mingfx.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include "imagetools/color_data.h"
#include "imageio/image_manager.h"
#include "imageio/image.h"

using std::cerr;
using std::endl;
namespace image_tools {

PixelBuffer::PixelBuffer(int w, int h, ColorData background_color)
    : width_(w), height_(h), background_color_(background_color) {
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      pixels_.push_back(background_color.red());
      pixels_.push_back(background_color.green());
      pixels_.push_back(background_color.blue());
      pixels_.push_back(background_color.alpha());
    }
  }
}

PixelBuffer::PixelBuffer(const std::string &filename)
    : width_(0), height_(0), background_color_(ColorData(1, 1, 1)) {
  LoadFromFile(filename);
}

PixelBuffer::PixelBuffer(const PixelBuffer &rhs)
    : PixelBuffer(rhs.width_, rhs.height_, rhs.background_color_) {
  std::copy(rhs.pixels_.begin(), rhs.pixels_.end(), pixels_.begin());
}

PixelBuffer::~PixelBuffer() {}

ColorData PixelBuffer::pixel(int x, int y) const {
  ColorData pixel_data;

  if ((x < 0) || (x >= width_) || (y < 0) || (y >= height_)) {
    cerr << "pixel(x,y): out of range: " << x << " " << y << endl;
  } else {
    int index = 4 * (x + width_ * y);
    pixel_data = ColorData(pixels_[index + 0], pixels_[index + 1],
                           pixels_[index + 2], pixels_[index + 3]);
  }
  return pixel_data;
}

void PixelBuffer::set_pixel(int x, int y, const ColorData &new_pixel) {
  if ((x < 0) || (x >= width_) || (y < 0) || (y >= height_)) {
    cerr << "setPixel: x,y out of range: " << x << " " << y << endl;
  } else {
    int index = 4 * (x + width_ * y);  // x + width*(height-(y+1));
    pixels_[index + 0] = new_pixel.red();
    pixels_[index + 1] = new_pixel.green();
    pixels_[index + 2] = new_pixel.blue();
    pixels_[index + 3] = new_pixel.alpha();
  }
}

PixelBuffer &PixelBuffer::operator=(const PixelBuffer &rhs) {
  /* Check for self-assignment! */
  if (this == &rhs) {
    return *this;
  }
  this->width_ = rhs.width_;
  this->height_ = rhs.height_;
  this->pixels_ = rhs.pixels_;
  this->background_color_ = rhs.background_color_;

  return *this;
} /* operator=() */

void PixelBuffer::Resize(int new_width, int new_height) {
  PixelBuffer tmp(new_width, new_height, background_color_);
  for (int y = 0; y < new_height; y++) {
    for (int x = 0; x < new_width; x++) {
      if ((x < width_) && (y < height_)) {
        tmp.set_pixel(x, y, pixel(x, y));
      } else {
        tmp.set_pixel(x, y, background_color_);
      }
    }
  }
  *this = tmp;
}

void PixelBuffer::SaveToFile(const std::string &filename) {
  imageio::Image* new_image = new imageio::Image(width_, height_, 4);
  for (int i = 0; i < new_image->Width(); i++) {
    for (int j = 0; j < new_image->Height(); j++) {
      ColorData pixel_at_point = pixel(i, j);
      new_image->SetFloatValue(i, j, 0, pixel_at_point.red());
      new_image->SetFloatValue(i, j, 1, pixel_at_point.green());
      new_image->SetFloatValue(i, j, 2, pixel_at_point.blue());
      new_image->SetFloatValue(i, j, 3, pixel_at_point.alpha());
    }
  }
  imageio::ImageManager::instance().SaveToFile(filename, *new_image);
  (void)filename;
}

void PixelBuffer::LoadFromFile(const std::string &filename) {
  imageio::Image* image =
  imageio::ImageManager::instance().LoadFromFile(filename);
  int width = image->Width();
  int height = image->Height();
  // ensuring that the fileexists by calling FileExists function
  if (!mingfx::Platform::FileExists(filename)) {
    // setting width to -1 to indicate there is no file at specified path
    width_ = -1;
    return;
  }
  // making a new tmp object to be assigned as a new object
  PixelBuffer tmp(width, height, background_color_);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      float image_red = image->FloatValue(i, j, 0);
      float image_green = image->FloatValue(i, j, 1);
      float image_blue = image->FloatValue(i, j, 2);
      float image_alpha = image->FloatValue(i, j, 3);
      ColorData color = ColorData(image_red, image_green, image_blue,
         image_alpha);
      tmp.set_pixel(i, j, color);
    }
  }
  *this = tmp;
  (void)filename;
}

bool operator==(const PixelBuffer &a, const PixelBuffer &b) {
  if ((a.width() != b.width()) || (a.height() != b.height())) {
    return false;
  } else {
    // check the actual pixels
    for (int y = 0; y < a.height(); y++) {
      for (int x = 0; x < a.width(); x++) {
        if (a.pixel(x, y) != b.pixel(x, y)) {
          return false;
        }
      }
    }
    return true;
  }
}

bool operator!=(const PixelBuffer &a, const PixelBuffer &b) {
  return !(a == b);
}

} /* namespace image_tools */
