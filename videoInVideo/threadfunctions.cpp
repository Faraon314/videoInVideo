#include <threadfunctions.h>
#include <merge_frames.h>
void threadFunctionIn(buffer& buffer,cv::VideoCapture & capture)
{
    cv::Mat frame;

    capture >> frame;
    buffer.setCols(frame.cols);
    buffer.setRows(frame.rows);
    buffer.setType(frame.type());
    buffer.push(frame);

    while(true)
    {
        capture >> frame;
        if(frame.empty())
            break;
        buffer.push(frame);
    }
}

void threadFunctionOut(buffer& bufferSmall,buffer& bufferBig)
{
    while(true)
    {
        cv::Mat frameFirst=bufferSmall.get();
        cv::Mat frameSecond=bufferBig.get();

        cv::Mat frame = merge_frames(frameFirst,frameSecond);
        imshow("test", frame);
        char c = (char)cv::waitKey(1);
        if (c == 27)
            break;
    }


}
