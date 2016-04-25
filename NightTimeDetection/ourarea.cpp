#include "ourarea.h"

OurArea::OurArea()
{
}
OurArea::OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl,Vector2<> leftTopl,Vector2<> leftDownl,Vector2<> rightTopl,Vector2<> rightDownl)
{
    left=leftl;
    right=rightl;
    top=topl;
    bottom=bottoml;
    width=widthl;
    height=heightl;
    centor.x=(left+right)/2;
    centor.y=(top+bottom)/2;
    leftTopPoint=leftTopl;
    leftDownPoint=leftDownl;
    rightTopPoint=rightTopl;
    rightDownPoint=rightDownl;
    lengthOfLeftTop2RightDown=sqrt(pow((leftTopPoint-rightDownPoint).x+1,2)+pow((leftTopPoint-rightDownPoint).y+1,2));
    lengthOfRightTop2LeftDown=sqrt(pow((rightTopPoint-leftDownPoint).x+1,2)+pow((rightTopPoint-leftDownPoint).y+1,2));
    area=width*height;
    orientation=std::max(lengthOfLeftTop2RightDown,lengthOfRightTop2LeftDown)/std::min(lengthOfLeftTop2RightDown,lengthOfRightTop2LeftDown);
}
OurArea::OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl,double orientl)
{
    left=leftl;
    right=rightl;
    top=topl;
    bottom=bottoml;
    width=widthl;
    height=heightl;
    centor.x=(left+right)/2;
    centor.y=(top+bottom)/2;
    Vector2<> point(0,0);
    leftTopPoint=point;
    leftDownPoint=point;
    rightTopPoint=point;
    rightDownPoint=point;
    area=width*height;
    orientation=orientl;
    lengthOfLeftTop2RightDown=0;
    lengthOfRightTop2LeftDown=0;
}
OurArea::OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl)
{
    left=leftl;
    right=rightl;
    top=topl;
    bottom=bottoml;
    width=widthl;
    height=heightl;
    centor.x=(left+right)/2;
    centor.y=(top+bottom)/2;
    Vector2<> point(0,0);
    leftTopPoint=point;
    leftDownPoint=point;
    rightTopPoint=point;
    rightDownPoint=point;
    area=width*height;
    lengthOfLeftTop2RightDown=0;
    lengthOfRightTop2LeftDown=0;
    orientation=0;
}
