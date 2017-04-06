#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/tracking.hpp"
#include <Windows.h>
#define drawCross( center, color, d )                                 \
line( img, Point( center.x - d, center.y - d ), Point( center.x + d, center.y + d ), color, 2, CV_AA, 0); \
line( img, Point( center.x + d, center.y - d ), Point( center.x - d, center.y + d ), color, 2, CV_AA, 0 )
using namespace cv;
using namespace std;


class KalmanTest {
public:
	Mat_<float> measurement = Mat_<float>(2,1);
	cv::KalmanFilter KF = KalmanFilter(4, 2, 0);
	POINT mousePos;
	KalmanTest();
	cv::Mat getPrediction();
	cv::Mat getCorrect(Mat tmp);
	cv::Mat getMesaurement();
	//void mouseCallback(int event, int x, int y, int flags, void* userdata);
};
void mouseCallback(int event, int x, int y, int flags, void* userdata);