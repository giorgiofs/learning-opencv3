/*

  loading and smoothing an image

  usage:
    ./ex_0205 lena.png

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void example2_5( const cv::Mat& image )
{

  // create some windows to show the input and output images
  cv::namedWindow( "Example2_5-in", cv::WINDOW_NORMAL );
  cv::namedWindow( "Example2_5-out", cv::WINDOW_NORMAL );

  // show the input image
  cv::imshow( "Example2_5-in", image );

  // create an image to hold the smoothed output
  cv::Mat out;

  // do the smoothing (yes, we're doing it twice)
  // coule use GaussianBlur(), blur(), medianBlur(), bilateralFilter()
  cv::GaussianBlur( image, out, cv::Size( 5, 5 ), 3, 3 );
  cv::GaussianBlur(   out, out, cv::Size( 5, 5 ), 3, 3 );

  // show the smoothed image
  cv::imshow( "Example2_5-out", out );

  cv::waitKey(0);

}

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0201 lena.png" << std::endl;
      return -1;
    }

  // read the input image
  cv::Mat img = cv::imread( argv[1], cv::IMREAD_UNCHANGED);

  // blur the image and display it
  example2_5( img );

  return 0;
}
