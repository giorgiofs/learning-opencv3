/*

  display an image

  usage:
    ./ex_0201 lena.png

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0201 lena.png" << std::endl;
      return -1;
    }
  cv::Mat img = cv::imread( argv[1], -1 );
  if( img.empty() )
    return -1;
  cv::namedWindow( "Example1", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Example1", img );
  cv::waitKey( 0 );
  return 0;
}
