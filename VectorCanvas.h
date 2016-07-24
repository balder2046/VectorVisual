//
// Created by 赵磊 on 16/7/24.
//

#ifndef VECTORVISUAL_VECTORCANVAS_H
#define VECTORVISUAL_VECTORCANVAS_H

#include <cv.h>
class VectorCanvas {
public:
    VectorCanvas(int nGridSize);

protected:
public:
    cv::Mat DrawBoard(int nRows, int nCols);
    cv::Mat DrawVector(const cv::Mat XData, const cv::Mat YData);
private:
    int m_nRows;
    int m_nCols;
    int m_nGridSize;

};


#endif //VECTORVISUAL_VECTORCANVAS_H
