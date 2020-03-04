#include <iostream>
#include <opencv2/core/core.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>

using namespace std;
using namespace cv;

double getMSE(const Mat& I1, const Mat& I2);

int main()
{
    Mat current;
    VideoCapture cam1;
    VideoWriter *writer = new VideoWriter();
    Mat frameGrayscale;       // grayscale of input frame
    Mat frameBlurred;         // intermediate blured frame
    Mat frameCanny;           // Edge-detection


    cam1.open(0);

    namedWindow("Normal");

    if(!cam1.isOpened())
    {
        cout << "Cam not found" << endl;
        return -1;
    }

    cam1>>current;
    Size *s = new Size((int)current.cols,current.rows);
    writer->open("MyVideo.avi",CV_FOURCC('D','I','V','X'),10,*s,false);


    while(true)
    {
        //Take the input
        cam1 >> current;

        // Convert to Grayscale
        cvtColor(current, frameGrayscale, CV_BGR2GRAY);
          
        //Blur the frames
        GaussianBlur(frameGrayscale, frameBlurred, Size(5, 5), 1.5);  

        //Apply Canny-filter
        Canny(frameBlurred, frameCanny,50,150);         

        *writer << frameCanny;
        imshow("Normal",frameCanny);

        if(waitKey(30)>=0)
         {
               break;
         }


    }
}