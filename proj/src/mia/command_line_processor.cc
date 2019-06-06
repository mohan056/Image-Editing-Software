/**
 This file is part of the CSCI-3081W Project Support Code, which was developed
 at the University of Minnesota.

 This code is to be used for student coursework.  It is not an open source
 project.
 Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 Minnesota.

 Original Author(s) of this File:
 Daniel Keefe, 2018, University of Minnesota

 Author(s) of Significant Updates/Modifications to the File:
 ...
 */


#include <string>

#include "mia/command_line_processor.h"
#include "imagetools/color_data.h"
#include "imagetools/filter_motion_blur.h"
#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

void CommandLineProcessor::ProcessCommandLine(int argument_count,
   char** arguments) {
  ImageEditor* image_editor = new ImageEditor();

  std::string in_filename(arguments[1]);

  // condition to check that correct number of aruments are given
  if (argument_count < 3) {
    if (in_filename == "-h") {
      HelpDisplay();
      return;
    } else {
      // Error message when output file is not given
      printf("Error: Output file not given. \n");
      return;
    }
  }
  // load command is executed if output file path is given
  if (isPNG(in_filename)) {
    LoadCommand *load_command = new LoadCommand(image_editor, in_filename);
    load_command->Execute();
  } else {
    printf("Error: File is not a PNG \n");
    return;
  }
  // condition to check if the filepath specified opens a file
  if (image_editor->pixel_buffer()->width() != -1) {
    // loop to iterate through filter commands given
    for (int i = 2; i < argument_count-1; i++) {
      std::string command(arguments[i]);
      // calls blur filter command only if radius given is valid
      if (command == "-blur") {
        float radius = atof(arguments[i+1]);
        if (0 <= radius && 10 >= radius && isDecimal(arguments[i+1])) {
          BlurFilterCommand *blur_command = new
          BlurFilterCommand(image_editor, radius);
          blur_command->Execute();
          delete blur_command;
          // ensuing that next command is skipped
          i = i + 1;
        } else {
          printf("Error: Radius inputted not valid. \n");
          return;
        }
      // calls edgedetect filer command
      } else if (command == "-edgedetect") {
        EdgeFilterCommand *edge_command = new EdgeFilterCommand(image_editor);
        edge_command->Execute();
        delete edge_command;
      // calls sharpen filter command only if radius given is valid
      } else if (command == "-sharpen") {
        float radius = atof(arguments[i+1]);
        if (radius >= 0 && radius <= 10 && isDecimal(arguments[i+1])) {
          SharpenFilterCommand *sharpen_command = new
          SharpenFilterCommand(image_editor, radius);
          sharpen_command->Execute();
          delete sharpen_command;
          i = i +1;
        } else {
          printf("Error: Radius inputted not valid \n");
          return;
        }
      // calls channels filter command with only red scale if scale is valid
      } else if (command == "-red") {
        float scale = atof(arguments[i+1]);
        if (scale >= 0.0f && scale <= 10.0f && isDecimal(arguments[i+1])) {
          ChannelsFilterCommand *red_command = new
          ChannelsFilterCommand(image_editor, scale, 1.0f, 1.0f);
          red_command->Execute();
          delete red_command;
          i = i +1;
        } else {
          printf("Error: Scale defined for channels not valid \n");
          return;
        }
      // calls channels filter command with only green scale if scale is valid
      } else if (command == "-green") {
        float scale = atof(arguments[i+1]);
        if (scale >= 0.0f && scale <= 10.0f && isDecimal(arguments[i+1])) {
          ChannelsFilterCommand *green_command = new
          ChannelsFilterCommand(image_editor, 1.0f, scale, 1.0f);
          green_command->Execute();
          delete green_command;
          i = i +1;
        } else {
          printf("Error: Scale defined for channels not valid \n");
          return;
        }
      // calls channels filter command with only blue scale if scale is valid
      } else if (command == "-blue") {
        float scale = atof(arguments[i+1]);
        if (scale >= 0.0f && scale <= 10.0f && isDecimal(arguments[i+1])) {
          ChannelsFilterCommand *blue_command = new
          ChannelsFilterCommand(image_editor, 1.0f, 1.0f, scale);
          blue_command->Execute();
          delete blue_command;
          i = i + 1;
        } else {
          printf("Error: Scale defined for channels not valid \n");
          return;
        }
      // calls quantize filter command when bins provided are valid
      } else if (command == "-quantize") {
        float bins = atof(arguments[i+1]);
        if (0 <= bins && 256 >= bins && isDecimal(arguments[i+1])) {
          QuantizeFilterCommand *quantize_command = new
          QuantizeFilterCommand(image_editor, bins);
          quantize_command->Execute();
          delete quantize_command;
          i = i + 1;
        } else {
          printf("Error: Number of bins inputted not valid \n");
          return;
        }
      // calls saturate filter when the saturation scale gien is valid
      } else if (command == "-saturate") {
        float scale = atof(arguments[i+1]);
        if (0.0f <= scale && scale <= 10.0f && isDecimal(arguments[i+1])) {
          SaturateFilterCommand *saturate_command = new
          SaturateFilterCommand(image_editor, scale);
          saturate_command->Execute();
          delete saturate_command;
          i = i + 1;
        } else {
          printf("Error: Saturation scale given is not valid \n");
          return;
        }
      // calls threshold filter command when the cutoff value given is valid
      } else if (command == "-threshold") {
        float cutoff = atof(arguments[i+1]);
        if (0.0f <= cutoff && 1.0f >= cutoff && isDecimal(arguments[i+1])) {
          ThresholdFilterCommand *threshold_command = new
          ThresholdFilterCommand(image_editor, cutoff);
          threshold_command->Execute();
          delete threshold_command;
          i = i + 1;
        } else {
          printf("Error: Threshold cutoff given not valid \n");
          return;
        }
      // calls the motion blur filter when radius given is valid
      } else if (command == "-motionblur-n-s") {
        float radius = atof(arguments[i+1]);
        if (0 <= radius && 10 >= radius && isDecimal(arguments[i+1])) {
          MotionBlurFilterCommand *motion_blur_command = new
          MotionBlurFilterCommand(image_editor, radius, "North/South");
          motion_blur_command->Execute();
          delete motion_blur_command;
          i = i +1;
        } else {
          printf("Error: Scale given for blurring is not valid. \n");
          return;
        }
      // calls the motion blur filter when radius given is valid
      } else if (command == "-motionblur-e-w") {
        float radius = atof(arguments[i+1]);
        if (0 <= radius && 10 >= radius && isDecimal(arguments[i+1])) {
          MotionBlurFilterCommand *motion_blur_command = new
          MotionBlurFilterCommand(image_editor, radius, "East/West");
          motion_blur_command->Execute();
          delete motion_blur_command;
          i = i +1;
        } else {
          printf("Error: Scale given for blurring is not valid. \n");
          return;
        }
      // calls the motion blur filter when the radius given is valid
      } else if (command == "-motionblur-ne-sw") {
        float radius = atof(arguments[i+1]);
        if (0 <= radius && 10 >= radius && isDecimal(arguments[i+1])) {
          MotionBlurFilterCommand *motion_blur_command = new
          MotionBlurFilterCommand(image_editor, radius, "Northeast/Southwest");
          motion_blur_command->Execute();
          delete motion_blur_command;
          i = i +1;
        } else {
          printf("Error: Scale given for blurring is not valid. \n");
          return;
        }
      // calls the motion blur filter when the radius given is valid
      } else if (command == "-motionblur-nw-se") {
        float radius = atof(arguments[i+1]);
        if (0 <= radius && 10 >= radius && isDecimal(arguments[i+1])) {
          MotionBlurFilterCommand *motion_blur_command = new
          MotionBlurFilterCommand(image_editor, radius, "Northwest/Southeast");
          motion_blur_command->Execute();
          delete motion_blur_command;
          i = i +1;
        } else {
          printf("Error: Scale given for blurring is not valid. \n");
          return;
        }
      } else {
          printf("Error: Command given unrecognizable \n");
          return;
      }
    }
    // saves file into the given file path
    std::string out_filename(arguments[argument_count-1]);
    SaveCommand *save_command = new SaveCommand(image_editor, out_filename);
    save_command->Execute();
    delete save_command;
  } else {
    printf("Error:Cannot find input file \n");
    return;
  }
}

void CommandLineProcessor::HelpDisplay() {
  printf("usage: mia infile.png [image processing commands ...]"
  " outfile.png \n\n");
  printf("infile.png:          input image file in png format \n");
  printf("outfile.png:         filename to use for saving the result \n\n");
  printf("image processing comamnds: \n\n");
  printf("-blur r:             apply a gaussian blur of radius r \n");
  printf("-edgedetect:         apply an edge detection filter \n");
  printf("-sharpen r:          apply a sharpening filter of radius r \n");
  printf("-red s:              scale the red channel by factor s\n");
  printf("-green s:            scale the green channel by factor s\n");
  printf("-blue s:             scale the blue channel by factor s\n");
  printf("-quantize n:         quantize each color channel into n bins\n");
  printf("-saturate s:         saturate colors by scale factor s\n");
  printf("-threshold c:        threshold using cutoff value c\n");
  printf("-motionblur-n-s r:   north-south motion blur with"
  " kernel radius r\n");
  printf("-motionblur-e-w r:   east-west motion blur with kernel"
  " radius r \n");
  printf("-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n");
  printf("-motionblur-nw-se r: nw-se motion blur with kernel radius r\n");
}

bool CommandLineProcessor::isDecimal(char* str) {
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (!(isdigit(str[i]) || str[i] == '.')) {
      return false;
    }
  }
  return true;
}

bool CommandLineProcessor::isPNG(std::string str) {
  int length = str.length();
  return (str.substr(length-4, length) == ".png");
}

};  // namespace image_tools
