#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	//x,y�b�y��(�����y��)
	Point a = Point(2, 2);
	cout << "�I�y��a : " << a << endl;
	Point b = Point(2, 1);
	cout << "�I�y��b-a : " << b-a << endl << endl;

	//Size�i�d�ߡA�Χ@���Ѽƻs�@�x�}(�e,��)
	cout << "a���e�� : " <<  Size(a) << endl;
	Size c = Size(30, 2);
	cout << "c����(�e,��) : " << c << endl;
	cout << "c����e : " << c.width << endl;
	cout << "c���� : " << c.height << endl << endl;

	//x,y�e��
	Rect d = Rect(1, 2, 30, 30);
	cout << "�x�Ϊ���" << d << endl;
	cout << "�x�Ϊ���x�y��" << d.x << endl;
	cout << "�x�Ϊ���y�y��" << d.y << endl;
	cout << "�x�Ϊ���e��" << d.width << endl;
	cout << "�x�Ϊ��󰪫�" << d.height << endl;


	return 0;
}