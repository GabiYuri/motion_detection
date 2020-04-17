#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){

    VideoCapture cap(0);

    // Check if the video opened
    if(!cap.isOpened()) return -1;

    Mat frame;

    while(1){
        
        // Show each frame
        cap.read(frame);
        imshow("Camera", frame);

        // Close the video when press 's'
        if(waitKey(30) == 's') break;
    }

    return 0;

}
