#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>


using namespace cv;
using namespace std;

int main(int, char**)
{
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;

  Size size = Size((int) cap.get(CV_CAP_PROP_FRAME_WIDTH),  
		(int) cap.get(CV_CAP_PROP_FRAME_HEIGHT));
  cout << "Caputure Size: " << size << endl;

  int framesPerSecond = static_cast<int>(cap.get(CV_CAP_PROP_FPS));
  cout << "CV_CAP_PROP_FPS: " << framesPerSecond << endl;

  int codexName = static_cast<int>(cap.get(CV_CAP_PROP_FOURCC)); 
  char EXT[] = {(char)(codexName & 0XFF) , (char)((codexName & 0XFF00) >> 8),(char)((codexName & 0XFF0000) >> 16),(char)((codexName & 0XFF000000) >> 24), 0};
  cout << "CV_CAP_PROP_FOURCC: " << EXT << endl;
  
  VideoWriter outputVideo;
  outputVideo.open("/tmp/out.avi", codexName, framesPerSecond, size, true); 

  Mat edges;
  namedWindow("edges",1);
  for(;;)
    {
      Mat frame;
      cap >> frame; // get a new frame from camera
      /*
      cvtColor(frame, edges, CV_BGR2GRAY);
      GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
      Canny(edges, edges, 0, 30, 3);
      imshow("edges", edges);
      */
      imshow("raw", frame);
      outputVideo.write(frame);
      if(waitKey(30) >= 0) break;
    }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}

