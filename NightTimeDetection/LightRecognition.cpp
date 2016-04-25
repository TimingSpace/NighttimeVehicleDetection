#include "LightRecognition.h"
int lightRecognition(Mat img,bool detail)
{
    vector<vector<Point> >regions;
    vector<Point> region;
    //floodFill(binaryImage,region,startPoint,255,0);
    findConnectedRegin(img,regions,255,0);
    cout<<"Connected region: "<<regions.size()<<endl;
    vector<Vector2<> > light;
    light=scanLight(regions,detail);
    return light.size();
};
