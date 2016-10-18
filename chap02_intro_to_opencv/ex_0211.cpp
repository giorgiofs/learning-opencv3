/*

  read in a color video and write a log-polar transformed video

  usage:
    ./ex_0211 video_file

*/

#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main( int argc, char* argv[] )
{
  if( argc != 3 )
    {
      std::cout << "usage: ex_0211 video_file_in video_file_out" << std::endl;
      return -1;
    }

  cv::namedWindow( "Example2_11", cv::WINDOW_NORMAL );
  cv::namedWindow( "Log_Polar", cv::WINDOW_NORMAL );

  cv::VideoCapture capture( argv[1] );

  double fps = capture.get( cv::CAP_PROP_FPS );
  cv::Size size(
		(int)capture.get( cv::CAP_PROP_FRAME_WIDTH ),
		(int)capture.get( cv::CAP_PROP_FRAME_HEIGHT )
		);

  cv::VideoWriter writer;
  writer.open( argv[2], CV_FOURCC( 'M','J','P','G' ), fps, size );

  cv::Mat logpolar_frame;
  cv::Mat bgr_frame;

  while( true )
    {
      capture >> bgr_frame;
      // if done, break
      if( bgr_frame.empty() )
	break;

      cv::imshow( "Example2_11", bgr_frame );

      cv::logPolar(
		   bgr_frame,				// input frame
		   logpolar_frame,			// output frame, logpolar
		   cv::Point2f(				// centerpoint for log-polar transformation
			       bgr_frame.cols/2,	// x
			       bgr_frame.rows/2		// y
						),
		   40,					// magnitude (scale parameter)
		   cv::WARP_FILL_OUTLIERS		// fill outliers with zero
		   );

      cv::imshow( "Log_Polar", logpolar_frame);
      writer << logpolar_frame;

      char c = cv::waitKey(10);
      // if the user presses the escape key, terminate instantly
      if( c == 27 )
	break;
    }

  capture.release();

  return 0;
}
