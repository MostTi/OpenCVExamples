#include "opencv2/opencv.hpp"
#include "crdtscp.h"

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    Mat frameOriginal;        // input frame
    Mat frameGrayscale;       // grayscale of input frame
    Mat frameBlurred;         // intermediate blured frame
    Mat frameCanny;           // Edge-detection
    Mat merged;
    Mat addweight;

    struct rdtscp_data rdata; 
    rdtscp_init(&rdata, 200); //init for 100 measurement samples
    rdtscp_init_corr(&rdata); //init also correction value

    for (int i = 0; i < rdata.nummeas; ++i) 
    {      
        rdata.tstart[i] = rdtscp(); //take start timestamp


        frameOriginal = imread( samples::findFile("Lena.jpg") );
        if( frameOriginal.empty() ) { cout << "Error loading Image" << endl; return EXIT_FAILURE; }
    
        cvtColor(frameOriginal, frameGrayscale, CV_BGR2GRAY);
        GaussianBlur(frameGrayscale, frameBlurred, Size(5, 5), 1.5);  
        Canny(frameBlurred, frameCanny,50,150);                    

        //Merge Images
        frameOriginal.copyTo( merged, frameCanny); // copy part of src image according the canny output, canny is used as mask
        cvtColor(frameCanny, frameCanny, CV_GRAY2BGR); // convert canny image to bgr
        addWeighted( frameOriginal, 0.5, frameCanny, 0.5, 0.0, addweight); // blend src image with canny image
        frameOriginal += frameCanny; // add src image with canny image

        rdata.tend[i] = rdtscp(); //take end timestamp
    }
    
    rdtscp_eval_wcorr(&rdata); //eval with corr value
    rdtscp_print(&rdata, "RDTSCP");    
    rdtscp_free(&rdata);  

    imshow("Original", frameOriginal);
    imshow("Canny", frameCanny);
    imshow("Merged", merged);

    waitKey(0);
    return 0;
}