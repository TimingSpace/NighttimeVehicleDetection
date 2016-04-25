#include "scanLight.h"
//#include "mouseControl.h"
#include "FloodFill.h"
#include "Representation/Blackboard.h"
#include "PreProcess.h"
int main()
{
    Mat img;//srcImage
    VideoCapture video=VideoCapture("tailLight.MOV");
    Mat grayImage;
    Mat binaryImage;
    Mat showImage;
    while(1)
    {
    if(1)
    {
        video>>img;
        imshow("source",img);
        myImage.srcImage=img;//Pass to Global Parameter
        showImage=img.clone();
        //image proprecess

        cvtColor(img,grayImage,CV_BGR2GRAY);

        //threshold(grayImage,binaryImage,200,255,CV_THRESH_BINARY);
        binaryImage=proprecess(img);
        myImage.binImage=binaryImage.clone();
    }
    else
    {
        img=imread("carLight7.png");
        myImage.srcImage=img;//
        showImage=img.clone();
        cvtColor(img,grayImage,CV_BGR2GRAY);
        threshold(grayImage,binaryImage,200,255,CV_THRESH_BINARY);
        imshow("bi",binaryImage);
        myImage.binImage=binaryImage.clone();
    }

    //Find vehicle light
    //Point startPoint(100,0);
    vector<vector<Point> >regions;
    vector<Point> region;
    //floodFill(binaryImage,region,startPoint,255,0);
    findConnectedRegin(binaryImage,regions,255,0);
    imshow("biaf",binaryImage);
    vector<Vector2<> > light;
    light=scanLight(regions,false);
    //Show the light pair we recognited
    cout<<"Connected region: "<<regions.size()<<endl;
    cout<<"Light  NUM      : "<<light.size()<<endl;

    if(!light.empty())
    {
        for(vector<Vector2<> >::iterator lv=light.begin();lv!=light.end();lv=lv+2 )
        {
            Scalar color = Scalar(rand()%255,rand()%255,rand()%255);
            circle(showImage,Point(lv->x,lv->y),10,color,5);
            circle(showImage,Point((lv+1)->x,(lv+1)->y),10,color,5);
        }
    }
    namedWindow("showImage",1);
    //setMouseCallback("showImage", CallBackFunc, &img);
    imshow("showImage",showImage);
    waitKey(1);
    }
    return 0;
}
