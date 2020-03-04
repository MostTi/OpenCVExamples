#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <ctime>

using namespace cv;
using namespace std;

static void help(char ** argv)
{
    cout << endl
        <<  "This program demonstrated the use of the discrete Fourier transform (DFT). " << endl
        <<  "The dft of an image is taken and it's power spectrum is displayed."  << endl << endl
        <<  "Usage:"                                                                      << endl
        << argv[0] << " [image_name -- default lena.jpg]" << endl << endl;
}

int main(int argc, char ** argv)
{

    VideoCapture cap;
    Mat I;
    Mat frameOriginal;

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
        cap >> frameOriginal;
        cvtColor(frameOriginal, I, CV_BGR2GRAY);

        Mat padded;                            //expand input image to optimal size
        int m = getOptimalDFTSize( I.rows );
        int n = getOptimalDFTSize( I.cols ); // on the border add zero values
        copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
        Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
        Mat complexI;
        merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
        dft(complexI, complexI);            // this way the result may fit in the source matrix
        // compute the magnitude and switch to logarithmic scale
        // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
        split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
        magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
        Mat magI = planes[0];
        magI += Scalar::all(1);                    // switch to logarithmic scale
        log(magI, magI);
        // crop the spectrum, if it has an odd number of rows or columns
        magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
        // rearrange the quadrants of Fourier image  so that the origin is at the image center
        int cx = magI.cols/2;
        int cy = magI.rows/2;
        Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
        Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
        Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
        Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
        Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
        q0.copyTo(tmp);
        q3.copyTo(q0);
        tmp.copyTo(q3);
        q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
        q2.copyTo(q1);
        tmp.copyTo(q2);
        normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
                                                // viewable image form (float between values 0 and 1).

        //imshow("Input Image"       , I   );    // Show the result
        imshow("spectrum magnitude", magI);

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

    return EXIT_SUCCESS;
}