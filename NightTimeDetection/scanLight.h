#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <math.h>
#include "Tools/Vector2.h"
#include "ourarea.h"
using namespace cv;
using namespace std;
OurArea getArea(vector<Point> area);
double possiblityTobeLightPair(OurArea area1, OurArea area2);
double getOrientation(vector<Point> area);
vector<Vector2<> > scanLight(vector<vector<Point> > contours,bool detail);

