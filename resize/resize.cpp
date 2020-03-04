#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv )
{ 
    Mat image;
    Mat dst;//dst image



    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Size size(512,512);//the dst image size,e.g.100x100
    
    resize(image,dst,size);//resize image
    imwrite("Lena_M_resized.jpg",dst);

    return 0;
}
