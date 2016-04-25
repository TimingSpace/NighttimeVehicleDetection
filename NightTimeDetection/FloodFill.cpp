#include "FloodFill.h"

void changeColor(Mat &img,Point point, Scalar replacementColor)
{
    img.at<uchar>(point.y,3*point.x)=replacementColor(0);
    img.at<uchar>(point.y,3*point.x+1)=replacementColor(1);
    img.at<uchar>(point.y,3*point.x+2)=replacementColor(2);

}
void floodFill(Mat &img,vector<Point> &region,Point startPoint,Scalar targetColor,Scalar replacementColor)
{
    Scalar nodeColor=Scalar(static_cast<int>(img.at<uchar>(startPoint.y,3*startPoint.x)),static_cast<int>(img.at<uchar>(startPoint.y,3*startPoint.x+1)),static_cast<int>(img.at<uchar>(startPoint.y,3*startPoint.x+2)));
    if(nodeColor==replacementColor)
        return;
    if(nodeColor!=targetColor)
        return;
    changeColor(img,startPoint,replacementColor);
    if(startPoint.x+1<img.cols)
        floodFill(img,region,Point(startPoint.x+1,startPoint.y),targetColor,replacementColor);
    if(startPoint.x-1>=0)
        floodFill(img,region,Point(startPoint.x-1,startPoint.y),targetColor,replacementColor);
    if(startPoint.y+1<img.rows)
        floodFill(img,region,Point(startPoint.x,startPoint.y+1),targetColor,replacementColor);
    if(startPoint.y-1>=0)
        floodFill(img,region,Point(startPoint.x,startPoint.y-1),targetColor,replacementColor);

}

void findConnectedRegin(Mat &img,vector< vector<Point> > &regions,unsigned int targetColor,unsigned int replacementColor)
{
    for(unsigned int i_row=0;i_row<img.rows;i_row++)
    {
        for(unsigned int i_col=0;i_col<img.cols;i_col++)
        {
            unsigned nodeColor=static_cast<int>(img.at<uchar>(i_row,i_col));
            if(nodeColor==targetColor)
            {
                vector<Point> region;
                floodFill(img,region,Point(i_col,i_row),targetColor,replacementColor);
                regions.push_back(region);
            }
        }
    }
}
void floodFill(Mat &img,vector<Point> &region,Point startPoint,unsigned int targetColor,unsigned int replacementColor)
{
    unsigned nodeColor=static_cast<int>(img.at<uchar>(startPoint.y,startPoint.x));
    if(nodeColor==replacementColor)
        return;
    if(nodeColor!=targetColor)
        return;
    img.at<uchar>(startPoint.y,startPoint.x)=replacementColor;
    region.push_back(startPoint);
    if(startPoint.x+1<img.cols)
        floodFill(img,region,Point(startPoint.x+1,startPoint.y),targetColor,replacementColor);
    if(startPoint.x-1>=0)
        floodFill(img,region,Point(startPoint.x-1,startPoint.y),targetColor,replacementColor);
    if(startPoint.y+1<img.rows)
        floodFill(img,region,Point(startPoint.x,startPoint.y+1),targetColor,replacementColor);
    if(startPoint.y-1>=0)
        floodFill(img,region,Point(startPoint.x,startPoint.y-1),targetColor,replacementColor);

}

