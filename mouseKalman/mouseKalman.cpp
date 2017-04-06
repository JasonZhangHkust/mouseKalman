#include "Kalman.h"
Mat_<float> measurement(2, 1);
int main( )
{ 


KalmanTest KF = KalmanTest();
// Image to show mouse tracking
Mat img(600, 800, CV_8UC3);
vector<Point> mousev,kalmanv;
mousev.clear();
kalmanv.clear();
namedWindow("mouse kalman", 1);
setMouseCallback("mouse kalman", mouseCallback, NULL);
 
while(1)
{
 Mat prediction = KF.getPrediction();
 Point predictPt(prediction.at<float>(0),prediction.at<float>(1));
 //measurement = KF.getMesaurement();
 Mat estimated = KF.getCorrect(measurement);
 
 Point statePt(estimated.at<float>(0),estimated.at<float>(1));
 Point measPt(measurement(0),measurement(1));
    // plot points
    imshow("mouse kalman", img);
    img = Scalar::all(0);
 
    mousev.push_back(measPt);
    kalmanv.push_back(statePt);
    drawCross( statePt, Scalar(255,255,255), 5 );
    drawCross( measPt, Scalar(0,0,255), 5 );
 
    for (int i = 0; i < mousev.size()-1; i++) 
     line(img, mousev[i], mousev[i+1], Scalar(255,255,0), 1);
     
    for (int i = 0; i < kalmanv.size()-1; i++) 
     line(img, kalmanv[i], kalmanv[i+1], Scalar(0,155,255), 1);
     
 if(waitKey(10)==27)break;  
}
                                           
    return 0;
}

void mouseCallback(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_MOUSEMOVE) {
		measurement(0) = x;
		measurement(1) = y;
	}
}