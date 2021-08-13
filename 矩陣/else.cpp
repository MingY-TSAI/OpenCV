//框範圍
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	//x,y軸座標(像素座標)
	Point a = Point(2, 2);
	cout << "點座標a : " << a << endl;
	Point b = Point(2, 1);
	cout << "點座標b-a : " << b-a << endl << endl;

	//Size可查詢，或作為參數製作矩陣(寬,高)
	cout << "a的寬高 : " <<  Size(a) << endl;
	Size c = Size(30, 2);
	cout << "c物件(寬,高) : " << c << endl;
	cout << "c物件寬 : " << c.width << endl;
	cout << "c物件高 : " << c.height << endl << endl;

	//x,y寬長
	Rect d = Rect(1, 2, 30, 30);
	cout << "矩形物件" << d << endl;
	cout << "矩形物件x座標" << d.x << endl;
	cout << "矩形物件y座標" << d.y << endl;
	cout << "矩形物件寬度" << d.width << endl;
	cout << "矩形物件高度" << d.height << endl;


	return 0;
}
