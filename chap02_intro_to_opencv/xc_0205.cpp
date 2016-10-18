/*

  play a video, there's even a slider now

  usage:
    ./ex_0204 video_file

*/

#include <fstream>
#include <iostream>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;             // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void* )
/*
  Callback function for trackbar

  int pos - current position of the specified trackbar
  void*   - optional parameter
*/
{
  g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );

  if( !g_dontset )
    g_run = 1;
  g_dontset = 0;

}

int main( int argc, char** argv )
{
  if( argc != 2 )
    {

      std::cout << "usage: ex_0202 video_file" << std::endl;
      return -1;

    }

  cv::namedWindow( "Example2_4", cv::WINDOW_NORMAL );
  g_cap.open( std::string( argv[1] ) );
  int frames	= (int) g_cap.get( cv::CAP_PROP_FRAME_COUNT );
  int tmpw	= (int) g_cap.get( cv::CAP_PROP_FRAME_WIDTH );
  int tmph	= (int) g_cap.get( cv::CAP_PROP_FRAME_HEIGHT );
  std::cout << "Video has " << frames << " frames of dimensions("
	    << tmpw << ", " << tmph << ")." << std::endl;

  cv::createTrackbar( "Position", "Example2_4", &g_slider_position, frames,
		      onTrackbarSlide );

  int downsampling_factor = 0;
  int max_downsampling_factor = 8;

  cv::createTrackbar( "Downsampling", "Example2_4",
		      &downsampling_factor, max_downsampling_factor );

  cv::Mat frame;

  while( true )
    {

      // std::cout << "slider position: " << g_slider_position << std::endl;

      if( g_run != 0 )
	{

	  g_cap >> frame;
	  if( frame.empty() )
	    break;
	  int current_pos = (int) g_cap.get( cv::CAP_PROP_POS_FRAMES );
	  g_dontset = 1;

	  cv::setTrackbarPos( "Position", "Example2_4", current_pos );

	  for (int i = 0; i != downsampling_factor; i++)
	    cv::pyrDown( frame, frame );

	  cv::imshow( "Example2_4", frame );

	  g_run -= 1;

	}

      char c = (char) cv::waitKey( 10 );
      if( c == 's' ) // single step
	{
	  g_run = 1; std::cout << "Single step, run = " << g_run << std::endl;
	}
      if( c == 'r' ) // run mode
	{
	  g_run = -1; std::cout << "Run mode, run = " << g_run << std::endl;
	}
      if( c == 27 ) // break if user presses the Escape key
	break;
    }

  return 0;
}
