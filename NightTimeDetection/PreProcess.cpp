#include "PreProcess.h"
Mat proprecess(Mat src)
{
    Mat rThreshold=myRedThreshold(src);
    cvtColor(src,src,COLOR_BGR2GRAY);
    Mat thre=myThreshold(src);
    Mat andImage;
    bitwise_and(rThreshold,thre,andImage);
    Mat closeImg=myMorPhological(andImage);
    Mat filterImage=myFiter(closeImg);
    if(1)
    {
        imshow("red",rThreshold);
        imshow("thre",thre);
        imshow("and",andImage);
        imshow("close",closeImg);
        imshow("filter",filterImage);
    }
    return filterImage;
}

Mat myThreshold(Mat src)
{

    Mat imgBW;
    threshold(src,imgBW,200,255,CV_THRESH_BINARY);//@todo how to modify it auto
    return imgBW;


}
Mat myRedThreshold(Mat src)//to do Riamge not suitable maybe I used a wrong method to get a R chanel of the Image
{
    vector<Mat> imageVector;
    Mat ycc;
    cvtColor(src,ycc,CV_BGR2YCrCb);
    split(src,imageVector);
    Mat rImage=imageVector[2];
    Mat rThresholdImage;
    threshold(rImage,rThresholdImage,200,255,CV_THRESH_BINARY);
    return rThresholdImage;
}
Mat myMorPhological(Mat src)
{
    Mat erodeImg;
    Mat dilImage;
    int erosionType=MORPH_RECT;
    int erosionSize=2;
    Mat element=getStructuringElement(erosionType,Size(2*erosionSize+1,2*erosionSize+1),Point(erosionSize,erosionSize));
    dilate(src,dilImage,element);
    erode(dilImage,erodeImg,element);
    return erodeImg;
}
Mat myFiter(Mat src)
{

    Mat filterImage;
    medianBlur(src,filterImage,5);
    return src;
}


Mat myCanny(Mat src)
{
    Mat edgeImage;
    uint thresh=100;
    Canny(src,edgeImage,thresh,2*thresh);
    return edgeImage;
}



