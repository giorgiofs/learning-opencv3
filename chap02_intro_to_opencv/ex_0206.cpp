/*

  downsampling an image. low-pass filtering before to avoid aliasing

  usage:
    ./ex_0206 lena.png

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0201 lena.png" << std::endl;
      return -1;
    }

  // read the input image
  cv::Mat in = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

  // output image
  cv::Mat out;

  // create a new image that's half the width and height of the input image
  cv::pyrDown( in, out );

  // create windows to show the input and output images
  cv::namedWindow( "Example2_6-in", cv::WINDOW_AUTOSIZE );
  cv::namedWindow( "Example2_6-out", cv::WINDOW_AUTOSIZE );

  // show the input image and the outpue images
  cv::imshow( "Example2_6-in", in );
  cv::imshow( "Example2_6-out", out );

  cv::waitKey(0);

  return 0;
}
