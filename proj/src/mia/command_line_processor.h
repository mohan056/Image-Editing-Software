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


#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <string>

#include "imagetools/color_data.h"
#include "imagetools/filter_motion_blur.h"
#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

/** Class to procees all commands for the mia command line. Defines a single
function to process all commands. Each command is passed in as an array of
char pointers. This class will parse through those commands and based on the
command, will call specific instances of the image_editor_commands class.**/
class CommandLineProcessor {
 public:
  /**Function to call respective commands from image_editor_commands file based
  on which command is passed on the interface. **/
  void ProcessCommandLine(int argument_count, char** arguments);

  /** Function to format display for the help command. This function is called
  by ProcessCommandLine when -h is passed. **/
  void HelpDisplay();

 private:
  bool isDecimal(char* str);

  bool isPNG(std::string str);
};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
