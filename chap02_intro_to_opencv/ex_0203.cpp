/*

  play a video

  usage:
    ./ex_0203 video_file

*/

#include <iostream>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main( int argc, char** argv )
{
  if( argc != 2 )
    {
      std::cout << "usage: ex_0203 video_file" << std::endl;
      return -1;
    }

  cv::namedWindow( "Example3", cv::WINDOW_NORMAL );
  cv::VideoCapture cap;
  cap.open( std::string( argv[1] ) );

  cv::Mat frame;
  while( true )
    {
      cap >> frame;
      if( frame.empty() ) // Ran out of film
	break;
      cv::imshow( "Example3", frame );
      if( cv::waitKey( 33 ) >= 0 ) // assuming a 30fps video: 1/30fps = 0.033s
	break;
    }

  return 0;
}
