#include "Kalman.h"
KalmanTest::KalmanTest() {
	
	KF.transitionMatrix = (Mat_<float>(4, 4) << 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1);
	measurement.setTo(Scalar(0));
	GetCursorPos(&mousePos);
	KF.statePre.at<float>(0) = mousePos.x;
	KF.statePre.at<float>(1) = mousePos.y;
	KF.statePre.at<float>(2) = 0;
	KF.statePre.at<float>(3) = 0;
	setIdentity(KF.measurementMatrix);
	setIdentity(KF.processNoiseCov, Scalar::all(1e-4));
	setIdentity(KF.measurementNoiseCov, Scalar::all(10));
	setIdentity(KF.errorCovPost, Scalar::all(.1));
}
Mat KalmanTest::getPrediction() {
	return KF.predict();
}

Mat KalmanTest::getCorrect(Mat tmp) {
return KF.correct(tmp);
}

Mat KalmanTest::getMesaurement() {
	GetCursorPos(&mousePos);
	measurement(0) = mousePos.x;
	measurement(1) = mousePos.y;
	return measurement;
}
