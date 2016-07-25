#include <iostream>
#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui_c.h>
#include <highgui.h>
#include "VectorCanvas.h"
#include "math.h"
using namespace cv;
Mat genRandomVector()
{
    Mat mat(10,10,CV_64FC2);
    for (int y = 0; y < mat.rows; ++y)
    {
        double *matData = mat.ptr<double>(y);
        for (int x = 0; x < mat.cols; ++x)
        {
            double alpha = rand() / (float)RAND_MAX * 3.1415;
            matData[2 * x] = cos(alpha);
            matData[2 * x + 1] = sin(alpha);

        }

    }
    return mat;
}
void getGradientImage(Mat inputImage, Mat &XImage, Mat &YImage)
{
    Sobel(inputImage,XImage,CV_16S,1,0);
    Sobel(inputImage,YImage,CV_16S,0,1);
    convertScaleAbs(XImage,XImage,0.5,128);
    blur(XImage,XImage,Size(10,10));
    convertScaleAbs(YImage,YImage,0.5,128);

}
void TestRandomVector()
{
    VectorCanvas canvas(30);
    Mat testV = genRandomVector();
    Mat gradData[2];
    split(testV, gradData);
    Mat mat = canvas.DrawVector(gradData[0],gradData[1]);
    namedWindow("draw",CV_WINDOW_AUTOSIZE);
    imshow("draw",mat);
    waitKey();
}
Mat DrawPoly()
{
    Mat img;
    img.create(128,128,CV_8UC3);
    Point pts[] = {Point(30,20),Point(60,20), Point(60,50),Point(30,50)};
    int num[] = {4};
    polylines(img,&pts,num,1,true,Scalar(255,255,255));
    return img;
}
int main() {
    VectorCanvas canvas(10);

    Mat img(128,128,CV_RGB);

    cvtColor(img,img,CV_RGB2GRAY);

    Mat XImage, YImage;
    getGradientImage(img,XImage,YImage);

    namedWindow("draw",CV_WINDOW_AUTOSIZE);
    imshow("draw",img);
    imshow("XGradient",XImage);
    imshow("YGradient",YImage);
    Mat bigVis = canvas.DrawVector(XImage,YImage);
    imshow("gradient",bigVis);
    waitKey();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}