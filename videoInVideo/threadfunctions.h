#ifndef THREADFUNCTIONS
#define THREADFUNCTIONS

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>;

#include <buffer.h>

void threadFunctionIn(buffer& ,cv::VideoCapture & );
void threadFunctionOut(buffer& ,buffer&);


#endif // THREADFUNCTIONS

