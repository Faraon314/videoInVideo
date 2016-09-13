#include "merge_frames.h"

#define ROWS 200
#define COLS 300


cv::Mat merge_frames(cv::Mat & frameSmall,cv::Mat & frameBig){
    cv::Mat frameResult;
    frameBig.copyTo(frameResult);
    cv::Size size(COLS,ROWS);
    cv::Mat smallFrame;
    resize(frameSmall,smallFrame,size);
    smallFrame.copyTo(frameResult(cv::Rect(0,0,smallFrame.cols, smallFrame.rows)));

    return frameResult;
}

