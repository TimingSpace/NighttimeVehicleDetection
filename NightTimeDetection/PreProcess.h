#ifndef Pre_Process_H
#define Pre_Process_H

#include <opencv2/opencv.hpp>
using namespace cv;
    Mat proprecess(Mat src);

    /*********************************
     * @input    Gray Image
     * @output   Binary Image
     * @fun      threshold with a fixed threshold value
     * ******************************/
    Mat myThreshold(Mat src);
    /*********************************
     * @input    RGB image
     * @output   Binary Image
     * @fun      first get R channel of the RGB Image
     * then threshold with a fixed threshold value
     * ******************************/
    Mat myRedThreshold(Mat src);
    /*********************************
     * @input    Binary Image
     * @output   Binary Image
     * @fun      Close process
     * ******************************/
    Mat myMorPhological(Mat src);
    /*********************************
     * @input    Binary Image
     * @output   Binary Image
     * @fun      Mean filted
     * ******************************/
    Mat myFiter(Mat src);
    /*********************************
     * @input    Binary Image
     * @output   Binary Image
     * @fun      have not succeed
     * ******************************/

#endif // Pre_Process_H
