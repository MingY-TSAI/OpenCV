//�Ϥ������Mat�x�}�غc
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


int main() 
{
	Mat m1 = Mat::eye(2, 3, CV_32F); //�ϥ�cv�W�٪Ŷ��i�ٲ�cv::�r���A�U�P
	Mat m2 = Mat::ones(3, 2, CV_32F);
	cout << "m1  = " << endl << m1 << endl << endl;
	cout << "m2  = " << endl << m2 << endl << endl;
	// �����ۭ�
	cout << "m1.*2 = \n" << m1 * 2 << endl << endl;
	//�����ӧO�ۭ�
	cout << "(m1+2).*(m1+3) = \n" << (m1 + 1).mul(m1 + 3) << endl << endl;
	// �x�}���n 
	cout << "(m1+2).(m1+3) = = \n" << (m1 + 1)*(m1 + 3).t() << endl << endl;
	//��m�x�}
	cout << "(m1+3) = = \n" << (m1 + 3).t() << endl << endl;


	//�ϯx�}
	Mat m5 = Mat::eye(5, 5, CV_32F);
	Mat m5inv = m5.inv();
	cout << "m5  = " << endl << m5 << endl << endl;
	cout << "m5inv = " << endl << m5inv << endl << endl;

	// �D�s�����Ӽ�(���row����0�~��)
	int nonZerosNum = countNonZero(m5); // m5����J�x�}�μv�H()
	cout << "m5  = " << endl << m5 << endl;
	cout << "m5���D�s�����Ӽ� = " << nonZerosNum << endl << endl;

	Mat m0 = Mat::zeros(5, 5, CV_32F);
	int nonZerosNum1 = countNonZero(m0); // m0����J�x�}�μv�H()
	cout << "m0  = " << endl << m0 << endl;
	cout << "m0���D�s�����Ӽ� = " << nonZerosNum1 << endl << endl;

	//�Ϥ������C��
	Mat img = imread("resources/1.png");
	cout << "�Ϥ����X��row�զ�" << img.rows << endl;
	cout << "�Ϥ����X��col�զ�" << img.cols << endl;

	return 0;
}