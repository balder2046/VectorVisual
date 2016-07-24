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
int main() {
    VectorCanvas canvas(30);
    Mat testV = genRandomVector();
    Mat gradData[2];
    split(testV, gradData);
    Mat mat = canvas.DrawVector(gradData[0],gradData[1]);
    namedWindow("draw",CV_WINDOW_AUTOSIZE);
    imshow("draw",mat);
    waitKey();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}