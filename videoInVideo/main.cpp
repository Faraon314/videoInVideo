#include "buffer.h"
#include "merge_frames.h"
#include "threadfunctions.h"

const std::string fileFilm1="/home/sergey/Downloads/Nachalo.2010. BDRip.avi";
const std::string fileFilm2="/home/sergey/Downloads/Forrest.Gamp.1994.BDRip.CTC.Premier.HTB+.avi";
const std::string fileSt1="/home/sergey/Downloads/st1.mp4";
const std::string fileSt2="/home/sergey/Downloads/st2.mp4";
const std::string fileTr1="/home/sergey/Downloads/tr1.mp4";
const std::string fileTr2="/home/sergey/Downloads/tr2.mp4";
const std::string file1="/home/sergey/Downloads/Warcraft60fps.mkv";
const std::string file2="/home/sergey/Downloads/video(2).mp4";
const std::string file3="/home/sergey/Downloads/video(1).mp4";


int main(int argc, char *argv[])
{
    cv::VideoCapture capture1;
    capture1.open(file3);
    cv::VideoCapture capture2;
    capture2.open(file2);
    int fps1=round(capture1.get(cv::CAP_PROP_FPS));
    int fps2=round(capture1.get(cv::CAP_PROP_FPS));
    std::cout<<capture1.get(cv::CAP_PROP_FRAME_COUNT)<<std::endl;

    buffer buffer1(150,capture1.get(cv::CAP_PROP_FRAME_COUNT));
    buffer buffer2(150,capture2.get(cv::CAP_PROP_FRAME_COUNT));
    std::thread threadIn1(threadFunctionIn, std::ref(buffer1),std::ref(capture1));
    std::thread threadIn2(threadFunctionIn,std::ref(buffer2),std::ref(capture2));
    threadFunctionOut(buffer1,buffer2,fps1,fps2);
    threadIn1.join();
    threadIn2.join();


}
