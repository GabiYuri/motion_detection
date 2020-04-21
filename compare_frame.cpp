#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){

    VideoCapture cap(0);

    if(!cap.isOpened()) return -1;

    Mat frame, next_frame;
    Mat frame_g, next_frame_g;
    Mat compare;
    bool movimento = false;

    while(1){
        
        int i = 0;
        //movimento = false;

        cap.read(frame);
        cvtColor(frame, frame_g, COLOR_BGR2GRAY);

        cap.read(next_frame);
        cvtColor(next_frame, next_frame_g, COLOR_BGR2GRAY);

        compare = frame_g - next_frame_g;
        imshow("frame", frame_g);
        imshow("next_frame", next_frame_g);
        imshow("compare", compare);
        
        if(waitKey(30) == 's') break;

        if(frame_g.data and next_frame_g.data){
            for(int i = 0; i < compare.rows; i++){
                for(int j = 0; j < compare.cols; j++){
                    if (compare.at<uchar>(i,j) > 40){
                        movimento = true;
                    }
                }
            }  
        }
    }

    if(movimento == true){
        cout << "Movimento!" << endl;
    }
    else{
        cout << "Sem movimento!" << endl;
    }

    return 0;

}