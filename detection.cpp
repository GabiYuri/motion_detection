#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){

    VideoCapture cap(0);

    // If the webcam doesn`t open
    if(!cap.isOpened()) return -1; 

    Mat frame, n_frame, frame_gray, n_frame_gray;
    Mat compare;

    while(1){

        cap.read(frame);
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        cap.read(n_frame);
        cvtColor(n_frame, n_frame_gray, COLOR_BGR2GRAY);

        compare = n_frame_gray - frame_gray;

        imshow("Actual Frame", frame_gray);
        imshow("Next Frame", n_frame_gray);

        if(waitKey(30) == 's');

        
    }

    return 0;

}