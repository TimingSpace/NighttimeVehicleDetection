#include "mouseControl.h"
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     static Point leftTop;
     static Point rightBottom;
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          leftTop=Point(x,y);
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          rightBottom=Point(x,y);

           imshow("ImageForModify",myImage.binImage);
           namedWindow("Light",0);
           Mat localImg=(myImage.binImage)(Rect(leftTop.x,leftTop.y,rightBottom.x-leftTop.x,rightBottom.y-leftTop.y));
           imshow("Light",localImg);
           lightRecognition(localImg,true);

     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }

}
