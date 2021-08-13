#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 


using namespace cv;
using namespace std;


Mat imgHSV, mask;

//建立HSV_bar初始值
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void bar_window_set()
{
	namedWindow("Trackbars", (640, 200));

	createTrackbar("Hue Min", "Trackbars", &hmin, 179);

	createTrackbar("Hue Max", "Trackbars", &hmax, 179);

	createTrackbar("Sat Min", "Trackbars", &smin, 255);

	createTrackbar("Sat Max", "Trackbars", &smax, 255);

	createTrackbar("Val Min", "Trackbars", &vmin, 255);

	createTrackbar("Val Max", "Trackbars", &vmax, 255);
}

void main()

{

	string path = "Resources/1.png";

	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);//將圖片轉為HSV座標系統

	bar_window_set(); //自行定義bar控制HSV視窗


	while (true)

	{
		Scalar lower(hmin, smin, vmin);//bar_window定義向量
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask); //調整mask圖片HSV範圍


		imshow("Image", img);

		//imshow("Image HSV", imgHSV);

		imshow("Image Mask", mask);//調變後的HSVmask影像

		waitKey(1);

	}



}