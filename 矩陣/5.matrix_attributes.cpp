#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main() 
{
	Mat o;
	int size2[2] = { 3, 4 };
	o.create(2, size2, CV_8UC3);
	cout << "矩陣 o = " << endl << " " << o << endl << endl;

	//矩陣維度
	cout << "矩陣維度\n" << o.dims << endl << endl;

	//整個矩陣刑事CV_8UC3 ...代號
	cout << "矩陣 type代號\n" << o.type() << endl << endl;

	//代表每個pixel的通到個數
	cout << "C'通道數'\n" << o.channels() << endl << endl;

	//每個pixel的位元(bit)數，在opencv中的Mat.depth()中得到的是一個0~6的數字，分別代表不同的位數，
	//enum{ CV_8U=0, CV_8S=1, CV_16U=2, CV_16S=3, CV_32S=4, CV_32F=5, CV_64F=6}; 
	//0和1都代表8位， 2和3都代表16位， 4和5代表32位，6代表64位
	cout << "每個pixel的位元(bit)數代號\n" << o.depth() << endl << endl;

	//cols * rows (Size() 格式)
	cout << "回傳矩陣 cols * rows \n" << o.size() << endl << endl;

	//C++: bool Mat::empty() const 如果矩陣中有没有 elemens，则返回 true。
	cout << "矩陣 o 是否為空的 \n" << o.empty() << endl << endl;

	//C++: size_t Mat::total() const
	cout << "元素總數: \n" << o.total() << endl << endl;
	//Mat::isContinuous   返回矩陣是否連續。
	cout << "元素是否連續: \n" << o.isContinuous() << endl << endl;

	//圖片物件行列數
	Mat img = imread("resources/1.png");
	cout << "圖片有幾個row組成" << img.rows << endl;
	cout << "圖片有幾個col組成" << img.cols << endl << endl;

	cout << "-----------------------------step相關-----------------------------" << endl << endl;

	//(每一個元素包含n個uchar值)
	cout << "elemSize == \n" << o.elemSize() << endl << endl;

	//(elemSize/channels); 矩陣中每一個元素的數據大小
	cout << "elemSize1 == (elemSize/channels) == \n" << o.elemSize1() << endl << endl;

	//step步長,字節基本單位
	//step這個部分有兩個值可以取，第一個是o.step[0]，另一個是o.step[1]。 
	//o.step[0]代表一列所有的數據大小，而o.step[1]代表一個pixel的數據大小，
	//所以o.step[0] = o.cols * o.elemSize() = ˙4 * 3 = 12
	//o.step[1] = 3，另外如果看到(int)o.step這樣的寫法，也就是取o.step[0]的意思。
	cout << "step == o.cols * o.elemSize() == \n" << o.step << endl << endl;

	//以字節的基本單位，Mat矩阵中每一个像素的大小，累計了所有通道、所有通道的elemSize1之後的值
	//step1 == step / elemSize1；
	cout << "step1 == step / elemSize1 == \n" << o.step1() << endl << endl;



	return 0;
}