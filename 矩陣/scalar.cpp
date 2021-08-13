#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main()
{
	//scalar為預設4階向量(RGBA)
	Scalar a = Scalar(1, 3);
	cout << "m0  = " << endl << a << endl;
	//7*7矩陣內塞1,3通道
	Mat M(7, 7, CV_32FC2, Scalar(1, 3));
	cout << "m0  = \n" << M << endl;

	//常用案例1-color
	Mat red_m(256, 256, CV_8UC3, Scalar(0, 0, 255, 22));
	imshow("Red", red_m);

	//常用案例2-image-mask
	int hmin = 90, smin = 110, vmin = 153;
	int hmax = 179, smax = 240, vmax = 255;
	Mat mask;
	Scalar lower(hmin, smin, vmin);//bar_window定義向量 
	Scalar upper(hmax, smax, vmax);

	inRange(red_m, lower, upper, mask); //調整mask圖片HSV範圍 
	imshow("Red-mask", mask);

	waitKey(0);
	return 0;
}