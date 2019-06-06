My Main Page {#mainpage}
=============

\section guide_for_user Guide For Users
- \subpage Guide_for_Users_Flashphoto
- \subpage Guide_for_Users_MIA
\section guide_for_developer Guide For Developers
- \subpage Guide_For_Developer

This manual documents the usages of flashphoto app and mia app. There are guides provided for users and for developers who wish to expand or alter the code. <br>

To make all the files in the project codebase, run te following command when in
the PROJ folder:
\verbatim
make
\endverbatim

Click on the user guide if you are wishing to only use the software as it is. <br>
Click on the developer guide if you wish to add more to the codebase. <br>

For any more queries, please contact me at mohan056@umn.edu.

\page Guide_for_Users_Flashphoto User Guide for Flashphoto
This page is to guide users through flashphoto:<br>
\section flashphoto_get_started Getting started with flashphoto
This section will detail how to get started with flashphoto. To build and run
flashphoto, run make and then run
\verbatim
./build/bin/flashphoto
\endverbatim
This will get you
started with the GUI for flashphoto.<br>
After you are started with the GUI, there are the following features you will
have the option to use.
\image html flashphoto_toolbox.png "Flashphoto Toolbox"
\subsection Open_and_save_in_flashphoto How to Open and Save
- Open: To open a file, click on the Open button. On the window that pops up,
navigate to the path where the file is located. Only PNG files are supported.
- Save: Once you want to save your image, you can click here to save it in a
PNG format. Navigate to the location in the pop-up window where you wish to
save it and proceed.
\subsection Tools_in_flashphoto How To use Tools
Flashphoto provides users with a range of tools that they can use to draw over
the canvas. To select a tool, click on the respective tool button.
To specify tool size, use the slider in the toolbox. To specify the tool color,
use the circular gradient defined in the toolbox.
- Pen: This Tool functions as a single opaque line of chosen color and radius.
It mimics the movement of a pen on the canvas. Below, we provide an example of
what the canvas would look like after applying a pen stroke
\image html pen_doxy.png "Pen Example"
- Calligraphy Pen: This Tool functions as a calligraphy pen. It has a thinner
width when going up or down than when going side to side. Below, we provide
an example of what applying calligraphy pen with color red looks like
\image html caligraphy_doxy.png "Calligraphy Pen Example"
- Chalk: This Tool functions as a chalk. It has a rarified stroke that is not
opaque. Below, as you can see, chalk tool does not have an opaque stroke.
\image html chalk_doxy.png "Chalk Example"
- Highlighter: This Tool functions like a highlighter. It is translucent
which you can observe below. It has a color red as its color.
\image html highlighter_doxy.png "Highlighter Example"
- Spray Can: This Tool functions as a spray can and is also not opaque.
Below, you can observe its example.
\image html spray_can_doxy.png "Spray Can Example"
- Blur: This Tool when dragged over a specific area of the canvas, blurs edges
and other areas of the canvas. The blur tool does not have a color selection.
In the example, the stroke on the left side is blur and on the right side is
not. The longer you hold onto the blur tool, the longer it will blur.
\image html blur_tool_doxy.png "Blur Tool Example"
- Eraser: This Tool can be used to erase specific areas of canvas. It cannot be
selected to be any other color. In the example given below, the eraser tool has
been used to erase the middle of the canvas.
\image html eraser_doxy.png "Eraser Example"
<br>
To work with these tools:
- Click on the tool you want
- Drag over the canvas with mouse clicked
- Release mouse where you want to end the stroke

\subsection guide_for_filters How To Use Filters
To implement filters in flashphoto, choose any of the options that the tool box
 provides. Each filter has specific bounds that cannot be exceeded. For some
 filters such as the motionblur, you have to provide two parameters such as
 direction and the radius of the kernel. the larger the radius, the large would
  be the effect. To demonstrate the effect of each filter, we use this image:

  \image html in-example.png "Original input image"

- Blur Filter: This filter applies a uniform blur effect all over the canvas or
the picture you have loaded. The slider describes the scale to which the image
will be blurred.

\image html blur-5-expected.png "Image after blur filter Scale: 5"
\image html blur-9-expected.png "Image after blur filter Scale :9"

- MotionBlur Filter: this filter will blur in the direction you specify. There
 are four directions available: North/South, East/West, Northeast/Southwest,
 Northwest/Southeast. You can increase the scale of blur effect by using the
 slider.

 \image html motionblur-ns-5-expected.png "Image after blur in North/South direction"
 \image html motionblur-ew-5-expected.png "Image after blur in East/West direction"
 \image html motionblur-nesw-5-expected.png "Image after blur in Northeast/Southwest direction"
 \image html motionblur-nwse-5-expected.png "Image after blur in Northwest/Southeast direction"

 - Sharpen Filter: This filter is to sharpen the edges of the image. Like
 previous filters, you can specify the magnitude or scale with the slider.

 \image html sharpen-5-expected.png "Image after Sharpen Filter Scale: 5"
 \image html sharpen-9-expected.png "Image after Sharpen Filter Scale: 9"

- Edge Detect Filter: This filter detects al the hard edges in the image or
canvas. It does not have a scale or any parameter.

\image html edgedetect-expected.png "Image after EdgeDetect Filter"

- Threshold Filter: This filter converts the whole image into black or white.
If part of the image has higher intensity, it is rounded up to white and if
it has lower intensity, it is rounded down to 0.

\image html threshold-0.5-expected.png "Image after Threshold Filter Threshold: 0.5"
\image html threshold-0.78-expected.png "Image after Threshold Filter Threshold: 0.78"

- Saturate Filter: This filter scales up the colors of the image based on the
value you specify.

\image html saturate-1.44-expected.png "Image after Saturate Filter Scale: 1.44"
\image html saturate-1.89-expected.png "Image after Saturate Filter Scale: 1.89"

- Adjust R,G,B Filter: this filter will scale each value of the colors out
of Red, Green and Blue individually. You can use on of the three sliders
given based on what you require.

\image html channels-1.44-1.0-1.0-expected.png "Image after scaling up the red"
\image html channels-1.0-1.44-1.0-expected.png "Image after scaling up the green"
\image html channels-1.0-1.0-1.44-expected.png "Image after scaling up the blue"

- Quantize Filter: This filter can be sued to quantize images.
 This filter will distribute the whole spectrum of colors in the image into
 certain bins. You can specify the number of bins using the slider.

 \image html quantize-5-expected.png "Image after Quantize Filter Bins: 5"
 \image html quantize-10-expected.png "Image after Quantize Filter Bins: 10"

To apply a filter:
- Select the filter
- Select the scale and other parameters in the box that opens

\subsection how_to_undo_and_redo How To use Undo or Redo
Apart from being able to use all these tools and filters, flashphoto also
provides us with the ability to undo or redo changes. Any change that has been
made to the canvas can be undone by clicking the undo button. Similarity, we
can redo any change by clicking on the redo button. Clicking on redo will redo
any change that you previously might have undone.



\page Guide_for_Users_MIA User Guide For MIA
This section gives a guide on how to Medical Imaging Application or MIA.

\section user_guide_for_MIA Getting Started with MIA
MIA has two modes- the graphical user interface and the command line mode.

\subsection graphical_interface Graphical Interface
The graphical window performs extremely similarly to how flashphoto performs.
To run the graphical version of MIA< run the following command once you are in PROJ folder:

\verbatim
./build/bin/mia
\endverbatim

\image html mia_toolbox.png "MIA toolbox"

\subsection open_and_save How To Open and Save
- Open: To open a file, click on the Open button. On the window that pops up, navigate to the path where the file is located. Only PNG files are supported.
- Save: Once you want to save your image, you can click here to save it in a PNG format. Navigate to the location in the pop-up window where you wish to save it and proceed.

Next, we explore different filters and tools for annotation and marking.
To demonstrate the effect of each change, we use this image:

\image html mia-in.png "Original input image"

\subsection how_mia_tools How To Use Tools
MIA provides users with a range of tools that they can use to draw over the
canvas. To select a tool, click on the respective tool button. To specify the tool
color, use the circular gradient defined in the toolbox.

- Pen: This Tool functions as a single opaque line of chosen color and radius.
It mimics the movement of a pen on the canvas. Below, we provide an example of
what the canvas would look like after applying a pen stroke with color red.
This tool is to be used to point areas of the medical image.

\image html mia-pen.png "Pen Example"

- Mark: This Tool can be used to annotate specific areas of the image. It gives
a specific mark on the medical image. Different colors can be chosen.

\image html mia-mark.png "Mark Example"

\subsection filter_mia How To Use Filters
To implement filters in MIA, choose any of the options that the tool box
provides. MIA provides a subset of the filters available in flashphoto.

- Blur Filter: This filter applies a uniform blur effect all over the canvas or
the picture you have loaded. The slider describes the scale to which the image
will be blurred.

\image html mia-blur.png "Image after Blur Filter"

- Sharpen Filter: This filter is to sharpen the edges of the image. Like
previous filters, you can specify the magnitude or scale with the slider.

\image html mia-sharpen.png "Image after Sharpen filter"

- Edge Detect Filter: This filter detects all the hard edges in the image or
canvas. It does not have a scale or any parameter.

\image html mia-edgedetect.png "Image after Edge Detect"

- Threshold Filter: This filter converts the whole image into black or white.
If part of the image has higher intensity, it is rounded up to white and if it
has lower intensity, it is rounded down to 0.

\image html mia-threshold.png "Image after threshold Filter"

- Quantize Filter: This filter can be sued to quantize images. This filter will
 distribute the whole spectrum of colors in the image into certain bins. You
 can specify the number of bins using the slider.

 \image html mia-quantize.png "Image after Quantize Filter"

 \subsection how_to_undo How to Undo and Redo
 Apart from being able to use all these tools and filters, MIA also
 provides us with the ability to undo or redo changes. Any change that has been
 made to the canvas can be undone by clicking the undo button. Similarity, we
 can redo any change by clicking on the redo button. Clicking on redo will redo
 any change that you previously might have undone.

 \subsection command_line Command Line
 Apart from the graphical interface, we can also use the command line mode for
 MIA. The command line mode for MIA supports various filters that can be
 applied. All of these filters have effects just like other modes of MIA and
 flashphoto. The usage of the MIA Command line is like this:

 \verbatim
 mia in.png –sharpen 5 –edgedetect out.png

usage: mia infile.png [image processing commands ...] outfile.png

infile.png:          input image file in png format
outfile.png:         filename to use for saving the result

image processing comamnds:
-blur r:             apply a gaussian blur of radius r. This filter blurs all the edges of the image.
-edgedetect:         apply an edge detection filter. This applies a filter to detect edges in the image.
-sharpen r:          apply a sharpening filter of radius r. This sharpens edges of the image.
-red s:              scale the red channel by factor s. This increases the redness of the image.
-green s:            scale the green channel by factor s. This increases the greeness of the image.
-blue s:             scale the blue channel by factor s. This increases the blueness of the image.
-quantize n:         quantize each color channel into n bins. This divides the whole color spectrum into distinct bins.
-saturate s:         saturate colors by scale factor s. This saturates the colors of the color spectrum.
-threshold c:        threshold using cutoff value c. This divides the image into black and white regions.
-motionblur-n-s r:   north-south motion blur with kernel radius r. This applies a blur in the north south direction.
-motionblur-e-w r:   east-west motion blur with kernel radius r. This applies a blur in the east west direction.
-motionblur-ne-sw r: ne-sw motion blur with kernel radius r. This applies a blur in the northwest and southeast direction.
-motionblur-nw-se r: nw-se motion blur with kernel radius r. This applies a blur in the northeast and southwest direction.

\endverbatim

Several of these filters use filters that have been defined in the user guide
for flashphoto. Navigate back from this page and onto the flashphoto guide for
sample usages.

\page Guide_For_Developer Developer Guide
This guide is specifically for users who wish to add more to the code provided
for our imaging software. We give a wide overview of our code structure along
with various elements such as important classes. For developers who are going
to be altering the structure of our code, we will be giving a guide through our
general coding style. This style needs to be followed when adding code to our
existing code base. All of the classes that have been defined in our project
are defined in the image_tools namespace.

\section programming_Reference Programming Reference
Our project follows a lose Model-View-Controller structure. It consists of
three main folders - flashphoto, mia and imagetools. Flashphoto and Mia serve
as the View and Controller for the flashphoto and mia apps respectively. Mia
app also has a command line mode which it handles. In the next list, we will
provide links to different classes inside of the different folders. <br>
<b>imagetools</b> <br>
This section of our code holds all the models and data structures used to
define the back-end of our app. All the filters and tools have their general
structure templates defined in this section. Along with those, we have also
defined structures for the canvas as a image_tools::PixelBuffer and the
structure of a pixel has been defined by image_tools::ColorData. This the list
of classes that have been defined inside.
- image_tools::ColorData
- image_tools::FloatMatrix
- image_tools::ImageEditor
- image_tools::ImageToolsMath
- image_tools::MaskFactory
- image_tools::PixelBuffer <br>
These are the general data structure of our project along with various utility based classes that have been defined. Along with these, here are the tools that have been defined:
- image_tools::ToolBlur
- image_tools::ToolCalligraphyPen
- image_tools::ToolChalk
- image_tools::ToolEraser
- image_tools::ToolHighlighter
- image_tools::ToolPen
- image_tools::ToolSprayCan
- image_tools::ToolStamp <br>
These are specific tools that follow the general template defined by the image_tools::Tool class. <br>
Next, we have our filters. All of these follow the template defined by the image_tools::filter class. There are simple filters and there are also convolutional filters. The simple filters alter the pixel in place and do not require any adjoining pixels. Convolutional filters however alter the pixel based on the other adjoining pixels' values. All the convolutional filters follow the image_tools::ConvolutionalFilter class and the image_tools::ConvolutionalFilter class follows the image_tools::Filter class.. Here is a list of the filter classes that we have:
- image_tools::ChannelsFilter
- image_tools::EdgeDetectFilter
- image_tools::QuantizeFilter
- image_tools::SaturationFilter
- image_tools::ThresholdFilter <br>
All of the above filters are simple filters. The next list of filters are convolutional filters.
- image_tools::BlurFilter
- image_tools::MotionBlurFilter
- image_tools::SharpenFilter
- image_tools::EdgeDetectFilter <br>
These structures and models are used to define various elements of the view and the controller and both of these are defined by the flashphoto folder and the mia folder. <br>

<b>mia</b> <br>
This section of the code handles the view and controller section for MIA. It will
generate the graphical interface and the command line for MIA.
- image_tools::ImageEditorCommand
This has the following command classes as well: image_tools::AddToStrokeCommand,
image_tools::BlurFilterCommand, image_tools::ChannelsFilterCommand,
image_tools::EdgeFilterCommand, image_tools::EndStrokeCommand,
image_tools::LoadCommand, image_tools::MotionBlurFilterCommand,
image_tools::QuantizeFilterCommand, image_tools::RedoCommand,
image_tools::SaturateFilterCommand, image_tools::SaveCommand,
image_tools::SharpenFilterCommand, image_tools::StartStrokeCommand,
image_tools::ThresholdFilterCommand, image_tools::UndoCommand
- image_tools::CommandLineProcessor
- image_tools::MiaApp <br>
Some of these classes deal with the command line mode and the image_tools::MiaApp
generates the graphical interface for MIA. <br>

<b>flashphoto</b> <br>
This section provides the controller and view for Flashphoto.
- image_tools::FlashPhotoApp <br>
This class is responsible for creating the graphical mode for Flashphoto.

\section high_level_design High Level Design
In this section, we will talk about the general design structure of our project.

\image html imagetools_class_structure.jpg "Class UML structure for Imagetools"

From the general UML structure of our project, we can observe some important
things. Class image_tools::ImageEditor utilizes several of the filter classes
and tools classes. Image Editor has commands to apply filters to the pixel buffer
which are called upon when changing the canvas. All the different tools are extended
from the Tool template file. The convolution filters share a common CreateKernel function.
This function is responsible for creating the kernels for all the convolution
filters. The image_tools::ConvolutionalFilter class extends the image_tools::filter class. This means that ConvolutionalFilter
class defines the CalculateFilteredPixel function. Its definition is different than that of Simple filters because
to be able to change the pixel content of the buffer, convolution filters need
other adjacent pixel values. Simple filters, on the other hand, do not need information
regarding  adjacent pixels. Thus, every simple filter defines its own
CalculateFilteredPixel function.

\image html Mia_Flashphoto_structure.jpg "Class UML structure for MIA and Flashphoto"

From the MIA app, we can say that it is extremely similar to FlashPhotoApp
in structure. This is because like FlashphotoApp, Mia app also utilizes
instances of different tools and filters to change the view of the canvas that we see.
However, since medical imaging does not require channels or saturation as filters
or motionblur, MiaApp does not utilize any of those instances. FlashphotoApp, on the other hand,
requires all the filters and tools except for the Stamp Too which is only required by MiaApp.
Both of the FlashphotoApp and MiaApp clases use the functions already defined in IamgeEditor to
Apply different filters, to start stroke for a tool, add to the stroke and to edn the stroke.
The App classes also utili9ze the undo and redo commands and functions defined.
Both of these view classes also use Mingfx to define the front-end of their respective sections.


\section coding_style Coding Style
Throughout this project, there are several style guidelines that have been followed.
For if you wish to add to thir project, it is imperative to check the styling of
the document. to check the style run the following command when in PROJ folder:
\verbatim
make check-style
or
make check-style-cse
\endverbatim
This runs cpplint on the entire project to ensure that all style guides have been followed.
The project uses the Google styling guide: https://google.github.io/styleguide/cppguide.html.
This is the link to get all the constraints or styling guides that need to be followed.
Some of the most common and basic guides are:
- Ensure that number of characters in a line are not more than 80
- Ensure that there are 2 space characters as indent usually
- Ensure that private and public in header files are indented with 1 space
- etc.

For a more expanded guide, navigate to the link provided above.
For naming convention, we follow the following convention when adding a new tool.
Name your tool header file as  <br> tool_<name of the tool> <br> and your class should be named
as <br> Tool<name of your tool>. <br> For naming filters and adding new ones, add a class
file like <br>  filter_<name of your filter> <br> and for naming your class, it should be in this format:
<br> <name of your filter>Filter. <br> Following this naming convention helps us keep the code
consistent.

\section common_tasks Common Tasks
For developers who are looking to add to the existing codebase, there are
certain tasks that need to be done:
\subsection adding_filter Adding a Filter
To add a filter to the existing filter set, do the following:
- Make a Filter class that follows the file naming convention in the imagetools
folder. If it is a convolution filter, it should inherit from the image_tools::ConvolutionalFilter
class or else inherit from the image_tools::Filter class. As a reference, look
at the image_tools::BlurFilter class.
- In image_tools::ImageEditor file, implement a function that when called upon,
can implement the new function on the pixel buffer.
- In the tests/gtest folder, implement a new test function that tests out the
filter. Based on where the filter is, implement it in the flashphotoapptest or
the miaapptest file.
- Run all regression tests to ensure that remainder of prior code works fine.
\subsection adding_tool Adding a Tool
To add a tool to the existing tool set, do the following:
- Make a tool class that inherits from image_tools::Tool class. To follow our
guide, follow image_tools::ToolPen or any other class.
- Implement a test function in tests/gtest suite that checks if the tool works.

For all of these steps, ensure that you are following the styling guide so
described.

\subsection how_run_tests Running A Test
To run all the tests, ensure that the make file has been run.
\verbatim
make tests
./build/test/gtests
\endverbatim

These are methods to do some common tasks for developers looking to add to our
existing codebase.
