#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 


using namespace cv;
using namespace std;


Mat imgHSV, mask;

//�إ�HSV_bar��l��
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

	cvtColor(img, imgHSV, COLOR_BGR2HSV);//�N�Ϥ��ରHSV�y�Шt��

	bar_window_set(); //�ۦ�w�qbar����HSV����


	while (true)

	{
		Scalar lower(hmin, smin, vmin);//bar_window�w�q�V�q
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask); //�վ�mask�Ϥ�HSV�d��


		imshow("Image", img);

		//imshow("Image HSV", imgHSV);

		imshow("Image Mask", mask);//���ܫ᪺HSVmask�v��

		waitKey(1);

	}



}