// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <iostream>
#include "gtest/gtest.h"
#include "flashphoto/flashphoto_app.h"

using image_tools::FlashPhotoApp;

class FlashPhotoAppTest : public ::testing::Test {
  void SetUp() override {
    app_ = new FlashPhotoApp(1024, 780, image_tools::ColorData(1, 1, 1));
  }

  void TearDown() override {
    delete app_;
  }

  // We need to write this method
  // void ComparePixelBuffers(PixelBuffer& bufA, PixelBuffer& bufB) {}

 protected:
  FlashPhotoApp *app_;
};

TEST_F(FlashPhotoAppTest, GetToolTest) {
  image_tools::Tool* pen = app_->GetToolByName("Pen");
  EXPECT_TRUE(pen);
  image_tools::Tool* unknownTool = app_->GetToolByName("Unknown");
  EXPECT_FALSE(unknownTool);
}

TEST_F(FlashPhotoAppTest, CanApplyFilters) {
  // For each filter {
  //   Copy pixel buffer from app_
  //   Apply filter
  //   Get new pixel buffer
  //   ComparePixelBuffers() to see if there was a change
  // }

  // image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  // app_->StartStroke("Pen", red_color, 3.0f, 50, 50);
  // for (int i = 50; i < 500; i++) {
  //   app_->AddToStroke(i, i);
  // }
  // app_->EndStroke(500, 500);
  // app_->StartStroke("Blur", red_color, 5.0f, 50, 50);
  // for (int i = 50; i < 500; i++) {
  //   app_->AddToStroke(i, i);
  // }
  // app_->EndStroke(500, 500);
  // app_->SaveToFile("resources/blur-tool-5-expected.png");
}

TEST_F(FlashPhotoAppTest, BlurFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  app_->ApplyBlurFilter(5.0f);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  // FlashPhotoApp *app_2 = new FlashPhotoApp(1024, 780, image_tools::ColorData(1, 1, 1));
  std::string expected_filename = "resources/blur-5-expected.png";
  // app_2->LoadFromFile(expected_filename);
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, QuantizeFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  app_->ApplyQuantizeFilter(5.0f);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/quantize-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, ChannelsFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  image_tools::ImageEditor *im = new image_tools::ImageEditor();
  im->LoadFromFile(input_filename);
  im->ApplyChannelsFilter(1.44f, 1.0f, 1.0f);
  image_tools::PixelBuffer *true_buffer = im->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/channels-1.44-1.0-1.0-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, EdgedetectFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  app_->ApplyEdgeDetectFilter();
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/edgedetect-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, SaturateFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  image_tools::ImageEditor *im = new image_tools::ImageEditor();
  im->LoadFromFile(input_filename);
  im->ApplySaturateFilter(1.44f);
  image_tools::PixelBuffer *true_buffer = im->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/saturate-1.44-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, SharpenFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  app_->ApplySharpenFilter(5.0f);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/sharpen-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, ThresholdFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  app_->ApplyThresholdFilter(0.5f);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/threshold-0.5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, MotionBlurNSFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  FlashPhotoApp::MBlurDir dir = FlashPhotoApp::MBLUR_DIR_N_S;
  app_->ApplyMotionBlurFilter(5.0f, dir);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/motionblur-ns-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, MotionBlurEWFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  FlashPhotoApp::MBlurDir dir = FlashPhotoApp::MBLUR_DIR_E_W;
  app_->ApplyMotionBlurFilter(5.0f, dir);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/motionblur-ew-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, MotionBlurNESWFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  FlashPhotoApp::MBlurDir dir = FlashPhotoApp::MBLUR_DIR_NE_SW;
  app_->ApplyMotionBlurFilter(5.0f, dir);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/motionblur-nesw-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, MotionBlurNWSEFilterRegressionTest) {
  std::string input_filename = "resources/in-example.png";
  app_->LoadFromFile(input_filename);
  FlashPhotoApp::MBlurDir dir = FlashPhotoApp::MBLUR_DIR_NW_SE;
  app_->ApplyMotionBlurFilter(5.0f, dir);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/motionblur-nwse-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, PenToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Pen", red_color, 100.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/pen-100-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, HighlighterToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Highlighter", red_color, 100.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/highlighter-100-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, SprayCanToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Spray Can", red_color, 100.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/spray-can-100-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, CaligraphyPenToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Caligraphy Pen", red_color, 100.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/caligraphy-pen-100-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, ChalkToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  image_tools::ToolChalk::setSeed();
  app_->StartStroke("Chalk", red_color, 100.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/chalk-100-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, BlurToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Pen", red_color, 3.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  app_->StartStroke("Blur", red_color, 5.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/blur-tool-5-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, EraserToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  app_->StartStroke("Pen", red_color, 20.0f, 50, 50);
  for (int i = 50; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  app_->StartStroke("Eraser", red_color, 20.0f, 250, 250);
  for (int i = 250; i < 500; i++) {
    app_->AddToStroke(i, i);
  }
  app_->EndStroke(500, 500);
  image_tools::PixelBuffer *true_buffer = app_->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/eraser-20-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}

TEST_F(FlashPhotoAppTest, StampToolRegressionTest) {
  image_tools::ColorData red_color = image_tools::ColorData(1, 0, 0);
  image_tools::ImageEditor *im = new image_tools::ImageEditor(app_->pixel_buffer());
  im->StartStroke("Stamp", red_color, 20.0f, 50, 50);

  im->EndStroke(50, 50);
  image_tools::PixelBuffer *true_buffer = im->pixel_buffer();
  image_tools::PixelBuffer true_value = *true_buffer;
  std::string expected_filename = "resources/stamp-tool-expected.png";
  image_tools::PixelBuffer *expected_buffer = new image_tools::PixelBuffer(expected_filename);
  image_tools::PixelBuffer expected_value = *expected_buffer;
  EXPECT_TRUE(true_value == expected_value);
}
