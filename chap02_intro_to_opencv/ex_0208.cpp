/*

  do many things:
  - change to grayscale
  - downsample twice
  - canny filter

  usage:
    ./ex_0208 lena.png

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0208 lena.png" << std::endl;
      return -1;
    }

  // read the input image
  cv::Mat img_rgb = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

  cv::Mat img_gry;
  cv::Mat img_pyr;
  cv::Mat img_pyr2;
  cv::Mat img_cny;

  cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY );
  cv::pyrDown( img_gry, img_pyr );
  cv::pyrDown( img_pyr, img_pyr2 );
  cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );

  // create windows to hold the gray and final image
  cv::namedWindow( "Example Gray", cv::WINDOW_NORMAL );
  cv::namedWindow( "Example Canny", cv::WINDOW_NORMAL );

  // show the gray and final images
  cv::imshow( "Example Gray", img_gry );
  cv::imshow( "Example Canny", img_cny );

  cv::waitKey(0);

  return 0;
}
