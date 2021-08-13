//圖片物件由Mat矩陣建構
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main() 
{
	Mat m1 = Mat::eye(2, 3, CV_32F); //使用cv名稱空間可省略cv::字首，下同
	Mat m2 = Mat::ones(3, 2, CV_32F);
	cout << "m1  = " << endl << m1 << endl << endl;
	cout << "m2  = " << endl << m2 << endl << endl;
	// 元素相乘
	cout << "m1.*2 = \n" << m1 * 2 << endl << endl;
	//元素個別相乘
	cout << "(m1+2).*(m1+3) = \n" << (m1 + 1).mul(m1 + 3) << endl << endl;
	// 矩陣內積 
	cout << "(m1+2).(m1+3) = = \n" << (m1 + 1)*(m1 + 3).t() << endl << endl;
	//轉置矩陣
	cout << "(m1+3) = = \n" << (m1 + 3).t() << endl << endl;


	//反矩陣
	Mat m5 = Mat::eye(5, 5, CV_32F);
	Mat m5inv = m5.inv();
	cout << "m5  = " << endl << m5 << endl << endl;
	cout << "m5inv = " << endl << m5inv << endl << endl;

	// 非零元素個數(整個row不為0才算)
	int nonZerosNum = countNonZero(m5); // m5為輸入矩陣或影象()
	cout << "m5  = " << endl << m5 << endl;
	cout << "m5中非零元素個數 = " << nonZerosNum << endl << endl;

	Mat m0 = Mat::zeros(5, 5, CV_32F);
	int nonZerosNum1 = countNonZero(m0); // m0為輸入矩陣或影象()
	cout << "m0  = " << endl << m0 << endl;
	cout << "m0中非零元素個數 = " << nonZerosNum1 << endl << endl;

	//圖片物件行列數
	Mat img = imread("resources/1.png");
	cout << "圖片有幾個row組成" << img.rows << endl;
	cout << "圖片有幾個col組成" << img.cols << endl;

	return 0;
}