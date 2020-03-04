#include "opencv2/opencv.hpp"
#include <ctime>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    VideoCapture cap;

    Mat frameOriginal;        // input frame
    Mat frameGrayscale;       // grayscale of input frame
    Mat frameBlurred;         // intermediate blured frame
    Mat frameCanny;           // Edge-detection
    Mat merged;
    Mat addweight;

    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return 0;

	const int num_frames = 1000;    // Number of frames to capture Has to be > ignoreFrames
    const int ignoreFrames = 10;
    double secs = 0;
    double fps = 0;
    double avg_secs = 0;
    double avg_fps = 0;
    double min_fps = 9999;
    double max_fps = 0;
    double min_secs = 9999;
    double max_secs = 0;


    //double fps = cap.get(CV_CAP_PROP_FPS);
    //cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;

    for(int i=0; i<num_frames; i++)
    {

        int64 t0 = cv::getTickCount();
        // Get frames from Camera
        cap >> frameOriginal;

        cvtColor(frameOriginal, frameGrayscale, CV_BGR2GRAY);
        GaussianBlur(frameGrayscale, frameBlurred, Size(5, 5), 1.5);  
        Canny(frameBlurred, frameCanny,50,150);                    
 
        //Merge Images
        frameOriginal.copyTo( merged, frameCanny); // copy part of src image according the canny output, canny is used as mask
        cvtColor(frameCanny, frameCanny, CV_GRAY2BGR); // convert canny image to bgr
        addWeighted( frameOriginal, 0.5, frameCanny, 0.5, 0.0, addweight); // blend src image with canny image
        frameOriginal += frameCanny; // add src image with canny image


        //Output
        if( frameCanny.empty() ) break; // end of video stream
        //imshow("Original", frameOriginal);
        //imshow("Canny", frameCanny);
        //imshow("Merged", merged);

        //if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC 

        int64 t1 = cv::getTickCount();
        secs = (t1-t0)/cv::getTickFrequency();
        fps = cv::getTickFrequency()/(cv::getTickCount() - t0); // fps in Hz (1/s)

        if(i >= ignoreFrames)
        {
            if(fps > max_fps) max_fps = fps;
            if(fps < min_fps) min_fps = fps;
            if(secs > max_secs) max_secs = secs;
            if(secs < min_secs) min_secs = secs;

            avg_fps += fps;
            avg_secs += secs;
            std::cout << "Ms: " << secs*1000 << " FPS: " << fps << endl;
        }
    }
    std::cout << "AVERAGE Ms: " << (avg_secs*1000)/(num_frames-ignoreFrames) << " FPS: " << avg_fps/(num_frames-ignoreFrames) << endl;
    std::cout << "Max FPS: " << max_fps  << "   Min FPS: " << min_fps << endl;
    std::cout << "Max Time (ms): " << max_secs*1000 << "   Min Time (ms): " << min_secs*1000 << endl;


    return 0;
}