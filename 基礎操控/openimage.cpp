 #include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 



using namespace cv;
using namespace std;



void main() {

	string path = "Resources/1.png";
	//�}�ҹϤ���m
	Mat img = imread(path);
	//�ഫ��Mat����
	imshow("Image", img);

	waitKey(0);

}