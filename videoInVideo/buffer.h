#ifndef BUFFER_H
#define BUFFER_H

#include <atomic>
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

class buffer
{
private:
    //размер буфера (контролируется семафором)
    int size;
    //количество кадров в загружаемом потоке
    int frame_count;
    //счетчик отправленных из буфера кадров
    int count;

    std::queue<cv::Mat> queue;
    std::mutex* mutex;
    //семафоры
    boost::interprocess::interprocess_semaphore* free_space;
    boost::interprocess::interprocess_semaphore* used_space;

    //нужно чтобы получить черное окно правильного размера когда в буфере больше ничего не появится
    int Rows;
    int Cols;
    int type;
    //нужно чтобы узнать что в буфере больше ничего не появится
    bool status;
public:
    bool isRun();
    void setRows(int);
    void setCols(int);
    void setType(int);
    buffer(int size,int frame_count);
    void push(cv::Mat);
    //get first
    cv::Mat get();
    ~buffer();

};

#endif // BUFFER_H
