#ifndef MOUSECONTROL_H
#define MOUSECONTROL_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Representation/Blackboard.h"
#include "LightRecognition.h"
using namespace std;
using namespace cv;
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
#endif
