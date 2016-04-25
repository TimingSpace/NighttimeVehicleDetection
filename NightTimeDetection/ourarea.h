#ifndef OURAREA_H
#define OURAREA_H
#include <iostream>
#include "Tools/Vector2.h"
class OurArea
{
private:

public:
    double left;
    double right;
    double top;
    double bottom;
    double width;
    double height;
    double area;
    double lengthOfLeftTop2RightDown;
    double lengthOfRightTop2LeftDown;
    double orientation;
    Vector2<> centor;
    Vector2<> leftTopPoint;
    Vector2<> leftDownPoint;
    Vector2<> rightTopPoint;
    Vector2<> rightDownPoint;
    OurArea();
    OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl,Vector2<> leftTopl,Vector2<> leftDownl,Vector2<> rightTopl,Vector2<> rightDownl);
    OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl,double orientl);
    OurArea(double leftl,double rightl,double topl,double bottoml,double widthl,double heightl);
    OurArea operator - (OurArea area1);
};

#endif // OURAREA_H
