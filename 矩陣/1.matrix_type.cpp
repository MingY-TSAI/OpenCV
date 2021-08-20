
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>

using namespace std;
using namespace cv;


int main()
{
	//圖片基礎為像素pixel構成(2D矩陣)，Mat為矩陣物件
	//Mat, IplImage, CvMat,後兩者都為opencv2舊物件
	Mat img = imread("Resources/1.png");

	cout << "圖片type" << img.type() << endl << endl;
	cout << "圖片cols * rows (寬,長)" << img.size() << endl << endl;


	//1.Mat 物件型態 CV_N
	//U是無符號整數（unsigned integer）
	//S是有符號整數（signed integer），
	//F是浮點數（float）。

	cout << "----------------------------(有無符號)整數，浮點數----------------------------" << endl << endl;

	Mat a;
	int size1[2] = { 2, 2 };
	a.create(2, size1, CV_8UC1);
	cout << "U無符號整數 = \n" << a << endl << endl;

	a.create(2, size1, CV_8SC1);
	cout << "S有符號整數 = \n" << a << endl << endl;

	a.create(2, size1, CV_32FC1);
	cout << "F  浮點數  = \n" << a << endl << endl;


	
	//2.通道數  C "n"
	//Mat與python,numpy表示方式有些微不同
	//python與numpy把channel數也當為一個維度
	// Mat 通道 為BGR!!!

	//Mat g(300,400, CV_8UC3, Scalar(0,255,0));
	//imshow("green-pic", g);
	//waitKey(3000);

	cout << "----------------------------------通道數----------------------------------" << endl << endl;


	cout << "----------------------------------單通道----------------------------------" << endl << endl;
	//1.基礎單通道2D陣列

	int size2[2] = { 3, 4 };
	Mat b(2, size2, CV_8UC1);
	
	cout << "b (C)  = \n" << b << endl << endl;
	cout << "b (python)  = \n" << format(b, Formatter::FMT_PYTHON) << endl << endl;
	cout << "b (numpy)  = \n"  << format(b, Formatter::FMT_NUMPY) << endl << endl;

	cout << "----------------------------------雙通道----------------------------------" << endl << endl;
	//2.雙通道2D陣列
	b.create(2, size2, CV_8UC2);
	cout << "b (C)  = \n" << b << endl << endl;
	cout << "b (python)  = \n" << format(b, Formatter::FMT_PYTHON) << endl << endl;
	cout << "b (numpy)  = \n" << format(b, Formatter::FMT_NUMPY) << endl << endl;

	cout << "----------------------------------三通道----------------------------------" << endl << endl;
	//3.三通道(BGR)2D陣列
	b.create(2, size2, CV_8UC3);
	cout << "b (C)  = \n" << b << endl << endl;
	cout << "b (python)  = \n" << format(b, Formatter::FMT_PYTHON) << endl << endl;
	cout << "b (numpy)  = \n" << format(b, Formatter::FMT_NUMPY) << endl << endl;

	//type 值對應：
	//CV_8UC1  0   CV_8UC2  8   CV_8UC3  16   CV_8UC4  24

	//CV_8SC1  1   CV_8SC2  9   CV_8SC3  17   CV_8SC4  25

	//CV_16UC1 2   CV_16UC2 10  CV_16UC3 18   CV_16UC4 26

	//CV_16SC1 3   CV_16SC2 11  CV_16SC3 19   CV_16SC4 27

	//CV_32SC1 4   CV_32SC2 12  CV_32SC3 20   CV_32SC4 28

	//CV_32FC1 5   CV_32FC2 13  CV_32FC3 21   CV_32FC4 29

	//CV_64FC1 6   CV_64FC2 14  CV_64FC3 22   CV_64FC4 30




	return 0;
}