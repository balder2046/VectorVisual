//
// Created by 赵磊 on 16/7/24.
//

#include "VectorCanvas.h"
using namespace cv;
VectorCanvas::VectorCanvas(int nGridSize) {
    m_nGridSize = nGridSize;
}

cv::Mat VectorCanvas::DrawBoard(int nRows, int nCols) {
    cv::Mat matBoard;
    int nTotalWidth = nCols * m_nGridSize;
    int nTotalHeight = nRows * m_nGridSize;
    matBoard.create(nTotalHeight + 1, nTotalWidth + 1,CV_8UC3);
    Scalar colorLine = Scalar(255,255,255);
    for (int i = 0; i < nRows + 1; ++i)
    {
        line(matBoard, Point(0,i * m_nGridSize),Point(nTotalWidth,i * m_nGridSize),colorLine);
    }
    for (int i = 0; i < nCols + 1; ++i)
    {
        line(matBoard, Point(i * m_nGridSize,0), Point(i * m_nGridSize, nTotalHeight), colorLine);
    }
    return matBoard;


}

cv::Mat VectorCanvas::DrawVector(const cv::Mat XData, const cv::Mat YData) {
    int nRows = XData.rows;
    int nCols = XData.cols;
    Mat matBoard = DrawBoard(nRows, nCols);
    for (int y = 0; y < nRows; ++y)
    {
        const double *xdata = XData.ptr<double>(y);
        const double *ydata = YData.ptr<double>(y);
        for (int x = 0; x < nCols; ++x)
        {
            double xval = xdata[x];
            double yval = ydata[x];
            double length = sqrt(xval * xval + yval * yval);
            if (length > 0.01)
            {
                xval /= length;
                yval /= length;
            }
            int halfsize = m_nGridSize / 2;
            Point center = Point(x * m_nGridSize + m_nGridSize / 2, y * m_nGridSize + m_nGridSize / 2);
            Point start = Point(center.x - xval * halfsize, center.y - yval * halfsize);
            Point end = Point(center.x + xval * halfsize, center.y + yval * halfsize);
            Scalar color = Scalar(length * 255, length * 255, length * 255);
            line(matBoard,start, end,color);

        }
    }
    return matBoard;

}
