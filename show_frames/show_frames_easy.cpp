#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    VideoCapture cap;

    Mat frameOriginal;        // input frame
    Mat frameGrayscale;       // grayscale of input frame
    Mat frameBlurred;         // intermediate blured frame
    Mat frameCanny;           // Edge-detection

    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return 0;
    for(;;)
    {
        int64 t0 = cv::getTickCount();
        // Get frames from Camera
        cap >> frameOriginal;

        double fps = cap.get(CV_CAP_PROP_FPS);
        cout << "Frames per second: " << fps << endl;

        // Convert to Grayscale
        cvtColor(frameOriginal, frameGrayscale, CV_BGR2GRAY);
          
        //Blur the frames
        GaussianBlur(frameGrayscale, frameBlurred, Size(5, 5), 1.5);  

        //Apply Canny-filter
        Canny(frameBlurred, frameCanny,50,150);                    
 
        //Output
        if( frameCanny.empty() ) break; // end of video stream
        imshow("Canny)", frameCanny);

        //Calculate Time diff
        int64 t1 = cv::getTickCount();
        double secs = (t1-t0)/cv::getTickFrequency();
        cout << "Time Interval: " << secs << endl;



        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
    }

    // the camera will be closed automatically upon exit-> close() not necessary
    // cap.close();
    return 0;
}
