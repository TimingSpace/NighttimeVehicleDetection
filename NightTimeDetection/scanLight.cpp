#include "scanLight.h"
OurArea getArea(vector<Point> area)
{
    Point startPoint=area.front();
    double left=startPoint.x;
    double right=startPoint.x;
    double top=startPoint.y;
    double bottom=startPoint.y;
    double width=0;
    double height=0;
    Point leftTopPoint=startPoint;
    Point leftDownPoint=startPoint;
    Point rightTopPoint=startPoint;
    Point rightDownPoint=startPoint;
    for(vector<Point>::iterator point=area.begin();point!=area.end();point++)
    {
        if(point->x<left)
        {
            left=point->x;
        }
        if(point->x>right)
        {
            right=point->x;
        }
        if(point->y<top)
        {
            top=point->y;
        }
        if(point->y>bottom)
        {
            bottom=point->y;
        }
        if(point->x<=leftTopPoint.x&&point->y<=leftTopPoint.y)
        {
            leftTopPoint=*point;
        }
        if(point->x<=leftDownPoint.x&&point->y>=leftDownPoint.y)
        {
            leftDownPoint=*point;
        }
        if(point->x>=rightTopPoint.x&&point->y<=rightTopPoint.y)
        {
            rightTopPoint=*point;
        }
        if(point->x>=rightDownPoint.x&&point->y>=rightDownPoint.y)
        {
            rightDownPoint=*point;
        }
    }
    Vector2<> leftTop(leftTopPoint.x,leftTopPoint.y);
    Vector2<> leftDown(leftDownPoint.x,leftDownPoint.y);
    Vector2<> rightTop(rightTopPoint.x,rightTopPoint.y);
    Vector2<> rightDown(rightDownPoint.x,rightDownPoint.y);
    double orient=getOrientation(area);
    width=right-left+1;
    height=bottom-top+1;
    double s=area.size();
    double scale=sqrt(s/(width*height));
    width=width*scale;
    height=height*scale;
    OurArea ourarea(left,right,top,bottom,width,height,orient);
    return ourarea;


}
double getOrientation(vector<Point> area)
{
    if(area.empty())
        return 0;
    float sumOfX  = 0;
    float sumOfX2 = 0;
    float sumOfXY = 0;
    float sumOfY  = 0;
    int N=area.size();
    for(vector<Point>::iterator point=area.begin();point!=area.end();point++)
    {
        sumOfX  += point->x;
        sumOfX2 += point->x*point->x;
        sumOfXY += point->x*point->y;
        sumOfY  += point->y;
    }
    double orientation=(N*sumOfXY-sumOfX*sumOfY)/(N*sumOfX2-sumOfX*sumOfX);
    return orientation;
}
double possiblityTobeLightPair(OurArea area1, OurArea area2,bool detail)
{
    double possiblity=0;
    double distanceHorizontal=max(area1.left,area2.left)-min(area1.right,area2.right)-1;
    double distanceVertical=max(area1.top,area2.top)-min(area1.bottom,area2.bottom)-1;
    double overlap=distanceVertical/min(area1.height,area2.height);
    double similarheight=min(area1.height,area2.height)/max(area1.height,area2.height);
    double similarwidth=min(area1.width,area2.width)/max(area1.width,area2.width);
    double near=(distanceHorizontal+area1.width+area2.width)/max(area1.width,area2.width);
    double scale=(distanceHorizontal+area1.width+area2.width)/max(area1.height,area2.height);
//    double orientation1=max(area1.lengthOfLeftTop2RightDown,area1.lengthOfRightTop2LeftDown)/min(area1.lengthOfLeftTop2RightDown,area1.lengthOfRightTop2LeftDown);
//    double orientation2=max(area2.lengthOfLeftTop2RightDown,area2.lengthOfRightTop2LeftDown)/min(area2.lengthOfLeftTop2RightDown,area2.lengthOfRightTop2LeftDown);
    double orientation1=area1.orientation;
    double orientation2=area2.orientation;
//    if(orientation1>0.1)
//    {
//        possiblity-=1;
//    }
//    if(orientation2>0.1)
//    {
//        possiblity-=1;
//    }
    if(area1.area<10)
    {
        possiblity-=1;
    }
     if(area2.area<10)
    {
        possiblity-=1;
    }
    if(overlap<-0.7)
    {
        possiblity+=0.5;
    }
    else if(overlap<-0.2)
    {
        possiblity+=0.2+overlap;
    }
    else
    {
        possiblity-=1;
    }
    if(similarheight>0.8)
    {
        possiblity+=0.25;
    }
    else if(similarheight>=0.5)
    {
        possiblity+=0.25+0.5*(similarheight-0.8);
    }
    else
    {
        possiblity-=1;
    }
    if(similarwidth>0.8)
    {
        possiblity+=0.25;
    }
    else if(similarwidth>=0.5)
    {
        possiblity+=0.25+0.5*(similarwidth-0.8);
    }
    else
    {
        possiblity-=1;
    }
    if(near<6&&near>2)
    {
        possiblity+=0.25;
    }
    else if(near>2&&near<11)
    {
        possiblity+=0.25-(near-6)*0.05;
    }
    else
    {
        possiblity-=1;
    }
    if(scale>2.5&&scale<10)
    {
        possiblity+=0.25;
    }
    else if(scale>2.5&&scale<15)
    {
        possiblity+=0.25-0.01*(scale-10);
    }
    else if(scale>2.5&&scale<20)
    {
        possiblity+=0.2-0.04*(scale-15);
    }
    else
    {
        possiblity-=1;
    }
    if(detail)
    {
        cout<<"************************"<<endl;
        cout<<"Light Fir:("<<area1.centor.x<<","<<area1.centor.y<<")"<<" height :"<<area1.height<<" width : "<<area1.width<<"  orientation: "<<orientation1<<endl;
        cout<<"Light Sec:("<<area2.centor.x<<","<<area2.centor.y<<")"<<" height :"<<area2.height<<" width : "<<area2.width<<"  orientation: "<<orientation2<<endl;
        cout<<"overlap  : "<<overlap<<endl;
        cout<<"simheight: "<<similarheight<<endl;
        cout<<"simwidth : "<<similarwidth<<endl;
        cout<<"near     : "<<near<<endl;
        cout<<"scale    : "<<scale<<endl;
        cout<<"Posi     : "<<possiblity<<endl;
        cout<<"************************"<<endl;
        cout<<endl;

    }
    ;

    return possiblity;
}
double possiblityTobeLightPair(OurArea area1, OurArea area2)
{
    double possiblity=0;
    double distanceHorizontal=max(area1.left,area2.left)-min(area1.right,area2.right);
    double distanceVertical=max(area1.top,area2.top)-min(area1.bottom,area2.bottom);
    double overlap=distanceVertical/min(area1.height,area2.height);
    double similarheight=min(area1.height,area2.height)/max(area1.height,area2.height);
    double near=(distanceHorizontal+area1.width+area2.width)/max(area1.width,area2.width);
    double scale=(distanceHorizontal+area1.width+area2.width)/max(area1.height,area2.height);
    if(overlap<-0.7)
    {
        possiblity+=0.5;
    }
    if(similarheight>0.7)
    {
        possiblity+=0.25;
    }
    if(near<7&&near>2)
    {
        possiblity+=0.25;
    }
    if(scale>2.5&&scale<15)
    {
        possiblity+=0.25;
    }
    return possiblity;
}
vector<Vector2<> > scanLight(vector<vector<Point> > contours,bool detail)
{
    vector<Vector2<> > posiLight;
    vector<OurArea> areas;
    for(vector<vector<Point> >::iterator contour=contours.begin();contour!=contours.end();contour++)
    {
        OurArea area=getArea(*contour);
        areas.push_back(area);
    }
    if(!areas.empty())
    {
        for(vector<OurArea>::iterator area1=areas.begin();area1!=areas.end();area1++)
        {
            for(vector<OurArea>::iterator area2=area1+1;area2!=areas.end();area2++)
            {
                double posi=possiblityTobeLightPair(*area1,*area2,detail);
                if(posi>=1)
                {
                    possiblityTobeLightPair(*area1,*area2,!detail);
                    posiLight.push_back(area1->centor);
                    posiLight.push_back(area2->centor);
//                    Scalar color = Scalar(rand()%255,rand()%255,rand()%255);

//                    circle(*colorSrc,Point(area1->centor.x,area1->centor.y),10,color,5);
//                    circle(*colorSrc,Point(area2->centor.x,area2->centor.y),10,color,5);
//                    cout<<"light1"<<area1->centor.x<<" "<<area1->centor.y;
//                    cout<<"light2"<<area2->centor.x<<" "<<area2->centor.y;


                }
            }

        }
    }
    cout<<"number of light pair"<<posiLight.size()<<endl;
    return posiLight;
}
