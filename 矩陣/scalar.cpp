#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main()
{
	//scalar���w�]4���V�q(RGBA)
	Scalar a = Scalar(1, 3);
	cout << "m0  = " << endl << a << endl;
	//7*7�x�}����1,3�q�D
	Mat M(7, 7, CV_32FC2, Scalar(1, 3));
	cout << "m0  = \n" << M << endl;

	//�`�ήר�1-color
	Mat red_m(256, 256, CV_8UC3, Scalar(0, 0, 255, 22));
	imshow("Red", red_m);

	//�`�ήר�2-image-mask
	int hmin = 90, smin = 110, vmin = 153;
	int hmax = 179, smax = 240, vmax = 255;
	Mat mask;
	Scalar lower(hmin, smin, vmin);//bar_window�w�q�V�q 
	Scalar upper(hmax, smax, vmax);

	inRange(red_m, lower, upper, mask); //�վ�mask�Ϥ�HSV�d�� 
	imshow("Red-mask", mask);

	waitKey(0);
	return 0;
}