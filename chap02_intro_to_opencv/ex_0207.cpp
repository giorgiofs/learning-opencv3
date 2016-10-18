/*

  applying Canny edge detector; requires changing colorspace

  usage:
    ./ex_0207 lena.png

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0207 lena.png" << std::endl;
      return -1;
    }

  // read the input image
  cv::Mat img_rgb = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

  // input image converted in grayscale
  cv::Mat img_gry;

  // output image, canny filtered
  cv::Mat img_cny;

  // converting to grayscale
  cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY );

  // Canny filtering
  cv::Canny( img_gry, img_cny, 10, 100, 3, true );

  // create windows to hold the input and output images
  cv::namedWindow( "Example Gray", cv::WINDOW_NORMAL );
  cv::namedWindow( "Example Canny", cv::WINDOW_NORMAL );

  // show the input image and output images
  cv::imshow( "Example Gray", img_gry );
  cv::imshow( "Example Canny", img_cny );

  cv::waitKey(0);

  return 0;
}
