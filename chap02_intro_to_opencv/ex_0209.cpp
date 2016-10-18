/*

  getting and setting pixel values

  usage:
    ./ex_0209 lena.png

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

  int x = 16;
  int y = 32;

  // read and print the value of (b,g,r) at pixel (x,y)
  cv::Vec3b intensity = img_rgb.at< cv::Vec3b >( y, x );

  uchar blue = intensity[0];
  uchar green = intensity[1];
  uchar red = intensity[2];

  std::cout << "At (x, y) = (" << x << ", " << y << "): "
	    << "(blue, green, red) = ("
	    << (unsigned int)blue << ", "
	    << (unsigned int)green << ", "
	    << (unsigned int)red << ")" << std::endl;

  // convert to grayscale
  cv::Mat img_gry;
  cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY );

  // read and print the value of gray intensity at pixel (x, y)
  std::cout << "Gray value at the same location is "
	    << (unsigned int)img_gry.at< uchar >( y, x ) << std::endl;

  // downscale the image twice
  cv::Mat img_pyr;
  cv::Mat img_pyr2;
  cv::pyrDown( img_gry, img_pyr );
  cv::pyrDown( img_pyr, img_pyr2 );

  // print the gray value of the "same" pixel in the downscaled image
  x /= 4;
  y /= 4;

  std::cout << "Pyramid2 pixel at the same location is "
	    << (unsigned int)img_pyr2.at< uchar >( y, x ) << std::endl;

  // apply a canny filter
  cv::Mat img_cny;
  cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );

  // set the value of that pixel in the Canny image to be 128
  img_cny.at< uchar >( y, x ) = 128;

  // create windows to hold the input and output images
  cv::namedWindow( "Example BGR", cv::WINDOW_NORMAL );
  cv::namedWindow( "Example Gray", cv::WINDOW_NORMAL );
  cv::namedWindow( "Example Canny", cv::WINDOW_NORMAL );

  // show the input image and output images
  cv::imshow( "Example RGB", img_rgb );
  cv::imshow( "Example Gray", img_gry );
  cv::imshow( "Example Canny", img_cny );

  cv::waitKey(0);

  return 0;
}
