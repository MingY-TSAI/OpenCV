#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main()
{

	//1. Mat::Mat() 無參數建構
	Mat a = Mat();
	cout << "無參數建構Mat\n" << a << endl << endl;

	//2.Mat::Mat(int rows, int cols, int type)
	//建立行數為 rows，列數為 col，型別為 type 的影象；
	Mat b(3, 4, CV_16U);
	cout << "row,col,type 建構Mat\n" << b << endl << endl;

	//3.Mat::Mat(Size size, int type)
	//建立大小為 size，型別為 type 的影象；
	Mat c(Size(2, 2), CV_16U);
	cout << "Size,type 建構Mat\n" << c << endl << endl;

	//4.Mat::Mat(int rows, int cols, int type, const Scalar & s)
	//建立行數為 rows，列數為 col，型別為 type 的影象，並將所有元素初始化為值 s
	Mat d(3, 3, CV_16U, Scalar(10));
	cout << "row,col,type並將所有元素初始化Scalar(10) 建構Mat\n" << d << endl << endl;

	//5.Mat::Mat(Size size, int type, const Scalar & s)
	//建立大小為 size，型別為 type 的影象，並將所有元素初始化為值 s
	Mat e(Size(3, 3), CV_16UC4, Scalar(5));//4個channel
	cout << "Size,type並將所有元素初始化Scalar(5) 建構Mat\n" << e << endl << endl;

	//6.Mat::Mat(const Mat & m)
	//將m賦值給新建立的物件，此處不會對影象資料進行復制，m和新物件共用影象資料； 
	Mat f(b);
	cout << "參考Mat b 建構Mat\n" << f << endl << endl;

	//7.Mat::Mat(int rows, int cols, int type, void* data, size_t step = AUTO_STEP)
	// 建立行數為rows，列數為col，型別為type的影象，
	//此建構函式不建立影象資料所需記憶體，而是直接使用data所指記憶體，影象的行步長由 step指定。(矩陣占用字節數) 
	//這些外部的數據不會被自動釋放。
	const int nrows = 10;
	const int ncols = 10;
	double data[nrows][ncols];
	int vals = 0;
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			data[i][j] = vals++;
		}
	}

	Mat g(nrows, ncols, CV_64FC1, data, 160);
	cout << "nrows,ncols,type, 陣列資料  建構Mat\n" << g << endl << endl;

	cout << "step參數講解 " << endl << endl;
	cout << "type參數大小:" << sizeof(CV_64FC1) * 2 << endl << endl;
	cout << "資料維度: " << g.dims << endl << endl;
	cout << "元素大小 = type參數大小*channel數 =  " << g.elemSize() << endl << endl;  //4 (uchar)* 2個channel
	cout << "base_step = elemSize()*ncols  = " << g.elemSize() * ncols << endl << endl;
	cout << "Mat g 現階段step = " << g.step << endl << endl;   // g.elemSize()*ncols為base
	cout << "step1 = step/elemSize() =  " << g.step1() << endl << endl;   // step/elemSize()


	//8、 Mat::Mat(Size size, int type, void* data, size_t step = AUTO_STEP)
	Mat h(Size(nrows, ncols), CV_64FC1, data, 80);
	cout << "Size ,type, 陣列資料  建構Mat\n" << h << endl << endl;



	//	9、Mat::Mat(const Mat& m, const Range& rowRange, const Range& colRange)
	//	建立的新影象為m的一部分，具體的範圍由rowrange和colrange指定，此建構函式也不進行影象資料的複製操作，新影象與m共用影象資料；
	Mat i(h, Range(3, 9), Range(3, 9));
	cout << "將原Mat h框範圍  建構新的Mat\n" << i << endl << endl;

	//	10、 Mat::Mat(const Mat& m, const Rect& roi)
	//	建立的新影象為m的一部分，具體的範圍roi指定，此建構函式也不進行影象資料的複製操作，新影象與m共用影象資料。
	Mat j(h, Rect(3, 3, 6, 6));
	cout << "利用ROI將原Mat h框範圍   建構新的Mat\n" << j << endl << endl;

	//	11 、 Mat (const Matx< _Tp, m, n > &mtx, bool copyData=true)
	Mat k = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "k = " << endl << " " << k << endl << endl;


	//	12 、 Mat(const std::vector< int > &sizes, int type)
	//		  Mat(const std::vector< int > &sizes, int type, const Scalar & s)
	vector<float> l;
	l.push_back((float)CV_PI);
	l.push_back(2);
	l.push_back(3.01f);
	cout << "用Vector  建構新的Mat = \n" << Mat(l, CV_64FC1) << endl << endl;

	//	13、Mat(const std::vector< int > &sizes, int type, void* data, const size_t * steps = 0)
	Mat o(vector <int> {2, 3}, CV_64FC1, data);
	cout << "用vector作為size框data 建構Mat \n" << o << endl << endl;

	//	14 、 Mat(int ndims, const int* sizes, int type)
	//	Mat(int ndims, const int* sizes, int type, const Scalar & s)
	int sz[2] = { 4, 3 };
	Mat m(2, sz, CV_64FC1, Scalar(1));
	cout << "用維度及1維陣列(定義元素數量)並初始化 建構Mat \n" << m << endl << endl;

	//	15 、 Mat(int ndims, const int* sizes, int type, void* data, const size_t * steps = 0)
	int sz1[2] = { 5, 5 };
	Mat n(2, sz1, CV_64FC1, data);
	cout << "用維度及1維陣列作為size框data 建構Mat \n" << n << endl << endl;







	return 0;
}
