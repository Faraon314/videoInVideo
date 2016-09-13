#include <threadfunctions.h>
#include <merge_frames.h>
#include <gcd.h>
void threadFunctionIn(buffer& buffer,cv::VideoCapture & capture)
{
    cv::Mat frame;

    capture >> frame;
    buffer.setCols(frame.cols);
    buffer.setRows(frame.rows);
    buffer.setType(frame.type());
    buffer.push(frame);

    while(buffer.isRun())
    {
        capture >> frame;
        if(frame.empty())
            break;
        buffer.push(frame);
    }
}

void threadFunctionOut(buffer& bufferSmall,buffer& bufferBig,int fpsSmal,int fpsBig)
{
    cv::Mat frameFirst;
    cv::Mat frameSecond;
    int Gcd=gcd(fpsSmal,fpsBig);
    int a=fpsSmal/Gcd;
    int b=fpsBig/Gcd;
    int Lcm=lcm(a,b);
    int FpsDelay=(1000/(Lcm*Gcd))+1;
    int i=0;

    while(bufferSmall.isRun()||bufferBig.isRun())
    {
        if(i%a==0)
        {
        frameSecond=bufferBig.get();
        }
        if(i%b==0&&bufferSmall.isRun())
        {
        frameFirst=bufferSmall.get();
        frameSecond = merge_frames(frameFirst,frameSecond);
        }

        if(i%Lcm==0)
        {
            i=0;
        }
        i++;

        imshow("test", frameSecond);
        char c = (char)cv::waitKey(FpsDelay);
        if (c == 27)
            break;
    }


}
