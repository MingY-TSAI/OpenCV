#include <opencv2/highgui.hpp> 
//�}�ҵ��T���Y�ݭn���Y��
#include <opencv2/imgcodecs.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 

using namespace cv;
using namespace std;



void main() {

	VideoCapture cap(0);
	//�]�wcamera,0���w�]���q���Y

	Mat img;//�]�wimg����(�x�})


	while (true) {

		cap.read(img);
		
		imshow("Image", img);//��ܼv��

		waitKey(1);//�]�w
	}
}