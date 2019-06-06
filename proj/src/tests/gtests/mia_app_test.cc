// Copyright (c) 2018 Abhiraj Mohan

#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "mia/command_line_processor.h"

using image_tools::CommandLineProcessor;

class MiaCommandLineAppTest : public ::testing::Test {
  void SetUp() override {
  }

  void TearDown() override {
    (void)cmd_;
  }

  // We need to write this method
  // void ComparePixelBuffers(PixelBuffer& bufA, PixelBuffer& bufB) {}

 protected:
  CommandLineProcessor cmd_;
};

TEST_F(MiaCommandLineAppTest, BlurCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-blur");
  command.push_back("5");
  command.push_back("resources/mia-blur-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/blur-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-blur-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, EdgeDetectCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-edgedetect");
  command.push_back("resources/mia-edgedetect-output.png");
  char* commands[4];
  for (int i = 0; i < 4; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(4, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/edgedetect-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-edgedetect-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, SharpenCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-sharpen");
  command.push_back("5");
  command.push_back("resources/mia-sharpen-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/sharpen-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-sharpen-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, QuantizeCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-quantize");
  command.push_back("5");
  command.push_back("resources/mia-quantize-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/quantize-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-quantize-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, RedCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-red");
  command.push_back("1.44");
  command.push_back("resources/mia-red-1.44-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/channels-1.44-1.0-1.0-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-red-1.44-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, GreenCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-green");
  command.push_back("1.44");
  command.push_back("resources/mia-green-1.44-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/channels-1.0-1.44-1.0-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-green-1.44-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, BlueCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-blue");
  command.push_back("1.44");
  command.push_back("resources/mia-blue-1.44-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/channels-1.0-1.0-1.44-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-blue-1.44-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, SaturateCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-saturate");
  command.push_back("1.44");
  command.push_back("resources/mia-saturate-1.44-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/saturate-1.44-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-saturate-1.44-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, ThresholdCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-threshold");
  command.push_back("0.5");
  command.push_back("resources/mia-threshold-0.5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/threshold-0.5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-threshold-0.5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, MotionBlurNSCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-motionblur-n-s");
  command.push_back("5");
  command.push_back("resources/mia-motionblur-ns-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/motionblur-ns-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-motionblur-ns-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, MotionBlurEWCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-motionblur-e-w");
  command.push_back("5");
  command.push_back("resources/mia-motionblur-ew-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/motionblur-ew-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-motionblur-ew-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, MotionBlurNESWCommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-motionblur-ne-sw");
  command.push_back("5");
  command.push_back("resources/mia-motionblur-nesw-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/motionblur-nesw-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-motionblur-nesw-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, MotionBlurNWSECommandRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-motionblur-nw-se");
  command.push_back("5");
  command.push_back("resources/mia-motionblur-nwse-5-output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(5, commands);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer("resources/motionblur-nwse-5-expected.png");
  image_tools::PixelBuffer expected_value = *expected_buffer;
  image_tools::PixelBuffer *actual_buffer = new image_tools::PixelBuffer("resources/mia-motionblur-nwse-5-output.png");
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, HelpTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("-h");
  char* commands[2];
  for (int i = 0; i < 2; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  std::string expected_output = "usage: mia infile.png [image processing"
  " commands ...] outfile.png \n\ninfile.png:"
  "          input image file in png format \n"
  "outfile.png:         filename to use for saving the result \n\n"
  "image processing comamnds: \n\n"
  "-blur r:             apply a gaussian blur of radius r \n"
  "-edgedetect:         apply an edge detection filter \n"
  "-sharpen r:          apply a sharpening filter of radius r \n"
  "-red s:              scale the red channel by factor s\n"
  "-green s:            scale the green channel by factor s\n"
  "-blue s:             scale the blue channel by factor s\n"
  "-quantize n:         quantize each color channel into n bins\n"
  "-saturate s:         saturate colors by scale factor s\n"
  "-threshold c:        threshold using cutoff value c\n"
  "-motionblur-n-s r:   north-south motion blur with"
  " kernel radius r\n"
  "-motionblur-e-w r:   east-west motion blur with kernel"
  " radius r \n"
  "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n"
  "-motionblur-nw-se r: nw-se motion blur with kernel radius r\n";
  testing::internal::CaptureStdout();
  cmd_.ProcessCommandLine(2, commands);
  std::string actual_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_output, expected_output);
}

TEST_F(MiaCommandLineAppTest, OutputFileNotGivenTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  char* commands[2];
  for (int i = 0; i < 2; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  std::string expected_output = "Error: Output file not given. \n";
  testing::internal::CaptureStdout();
  cmd_.ProcessCommandLine(2, commands);
  std::string actual_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_output, expected_output);
}

TEST_F(MiaCommandLineAppTest, RadiusNotValidTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("-blur");
  command.push_back("ivalid");
  command.push_back("resources/output.png");
  char* commands[5];
  for (int i = 0; i < 5; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  std::string expected_output = "Error: Radius inputted not valid. \n";
  testing::internal::CaptureStdout();
  cmd_.ProcessCommandLine(5, commands);
  std::string actual_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_output, expected_output);
}

TEST_F(MiaCommandLineAppTest, FileNotFoundTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example-invalid.png");
  command.push_back("resources/output.png");
  char* commands[3];
  for (int i = 0; i < 3; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  std::string expected_output = "Error:Cannot find input file \n";
  testing::internal::CaptureStdout();
  cmd_.ProcessCommandLine(3, commands);
  std::string actual_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_output, expected_output);
}

TEST_F(MiaCommandLineAppTest, MiaFileCopiedRunsTest) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/in-example.png");
  command.push_back("resources/mia-output.png");
  char* commands[3];
  for (int i = 0; i < 3; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(3, commands);
  image_tools::ImageEditor *im_ = new image_tools::ImageEditor();
  im_->LoadFromFile("resources/in-example.png");
  image_tools::PixelBuffer *expected_buffer = im_->pixel_buffer();
  image_tools::PixelBuffer expected_value = *expected_buffer;
  im_->LoadFromFile("resources/mia-output.png");
  image_tools::PixelBuffer *actual_buffer = im_->pixel_buffer();
  image_tools::PixelBuffer actual_value = *actual_buffer;
  EXPECT_EQ(actual_value, expected_value);
}

TEST_F(MiaCommandLineAppTest, NonPNGFileDoesNotWork) {
  std::vector<std::string> command;
  command.push_back("./build/bin/mia");
  command.push_back("resources/not_a_png.txt");
  command.push_back("resources/mia-output.png");
  char* commands[3];
  for (int i = 0; i < 3; i++) {
    int word_length = command.at(i).length();
    commands[i] = (char *)malloc((word_length + 1) * sizeof(char));
    strcpy(commands[i], command.at(i).c_str());
  }
  cmd_.ProcessCommandLine(3, commands);
  std::string expected_output = "Error: File is not a PNG \n";
  testing::internal::CaptureStdout();
  cmd_.ProcessCommandLine(3, commands);
  std::string actual_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(actual_output, expected_output);
}
