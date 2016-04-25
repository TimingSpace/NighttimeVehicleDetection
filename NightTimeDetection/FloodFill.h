#ifndef FLOODFILL_H
#define FLOODFILL_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
void floodFill(Mat &img,vector<Point> &region,Point startPoint,Scalar targetColor,Scalar replacementColor);
void floodFill(Mat &img,vector<Point> &region,Point startPoint,unsigned int targetColor,unsigned int replacementColor);
void findConnectedRegin(Mat &img,vector< vector<Point> > &regions,unsigned int targetColor,unsigned int replacementColor);

#endif
