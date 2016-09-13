#include "buffer.h"


buffer::buffer(int size,int frame_count)
{

    this->size = size;
    mutex = new std::mutex();
    free_space= new boost::interprocess::interprocess_semaphore(size);
    used_space= new boost::interprocess::interprocess_semaphore(0);
    this->frame_count=frame_count;
    count=0;
    status=true;
}

void  buffer::push(cv::Mat frame)
{
    free_space->wait();
    mutex->lock();
    cv::Mat frame1;
    frame.copyTo(frame1);
    queue.push(frame1);
    mutex->unlock();
    used_space->post();

}

cv::Mat buffer::get()
{
    cv::Mat frame;
    if(count!=frame_count)
    {
    used_space->wait();
    mutex->lock();
    frame = queue.front().clone();
    queue.pop();
    count++;
    mutex->unlock();
    free_space->post();
    }else
    {
       frame=cv::Mat::zeros(Rows, Cols, type);
       status=false;
    }

    return frame;
}

bool buffer::isEnd()
{
    return status;
}

void buffer::setRows(int Rows )
{
    this->Rows=Rows;
}

void buffer::setCols(int Cols)
{
     this->Cols=Cols;
}
void buffer::setType(int type)
{
    this->type=type;
}


buffer::~buffer()
{
    delete mutex;
    delete free_space;
    delete used_space;
}



