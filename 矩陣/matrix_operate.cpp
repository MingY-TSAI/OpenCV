//圖片物件由Mat矩陣建構
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	//1.創造矩陣
	cout << "--------------------------------------1.創造矩陣--------------------------------------" << endl << endl;
	//C++: void Mat::create(int rows, int cols, int type)
	//C++: void Mat::create(Size size, int type)
	//C++ : void Mat::create(int ndims, const int* sizes, inttype)
	Mat a;
	a.create(3, 3, CV_8UC3);
	cout << "3rows*3cols (3channel)的a矩陣 = " << endl << " " << a << endl << endl;
	Mat b;
	b.create(Size(3, 2), CV_8UC3);
	cout << "2rows*2cols (3channel)的b矩陣 = " << endl << " " << b << endl << endl;
	Mat c;
	int size[2] = { 3, 2 };
	c.create(2, size, CV_8UC3);
	cout << "3rows*2cols (3channel)的c矩陣 = " << endl << " " << c << endl << endl;

	//零矩陣,identity矩陣,一矩陣
	Mat m0 = Mat::zeros(5, 5, CV_32F);
	Mat m1 = Mat::eye(2, 3, CV_32F); 
	Mat m2 = Mat::ones(3, 2, CV_32F);
	cout << "5*5 零矩陣       m0  = " << endl << m0 << endl << endl;
	cout << "2*3 Identity矩陣 m1  = " << endl << m1 << endl << endl;
	cout << "3*2 單位1矩陣    m2  = " << endl << m2 << endl << endl;


	//2.矩陣運算
	cout << "--------------------------------------2.矩陣運算--------------------------------------" << endl << endl;
	// 元素相乘
	cout << "m1.*2 = \n" << m1 * 2 << endl << endl;
	//元素個別相乘
	cout << "(m1+2).*(m1+3) = \n" << (m1 + 1).mul(m1 + 3) << endl << endl;
	// 矩陣內積 
	cout << "(m1+2).(m1+3) = = \n" << (m1 + 1) * (m1 + 3).t() << endl << endl;
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

	int nonZerosNum1 = countNonZero(m0); // m0為輸入矩陣或影象()
	cout << "m0  = " << endl << m0 << endl;
	cout << "m0中非零元素個數 = " << nonZerosNum1 << endl << endl;

	//3.矩陣操作
	cout << "--------------------------------------3.矩陣操作--------------------------------------" << endl << endl;
	//矩陣堆疊rows
	//C++: templatevoidMat::push_back(const T & elem)
	//C++ : void Mat::push_back(const Mat & elem)

	Mat mat = (Mat_<uchar>(2, 4) << 5, 6, 0, 4, 0, 1, 9, 9);
	cout << "原始mat矩陣: \n" << mat << endl << endl;

	vector<uchar> v1 = { 5, 77, 0, 4 };
	mat.push_back(Mat(v1).t());
	cout << "堆疊向量v1後的 mat矩陣: \n" << mat << endl << endl;

	mat.push_back(mat);
	cout << "mat 堆疊自己的 mat矩陣: \n" << mat << endl << endl;

	//刪除rows
	//C++: templatevoidMat::pop_back(size_t nelems = 1)
	mat.pop_back(2);
	cout << "刪除底下兩列後的 mat矩陣: \n" <<mat << endl << endl;


	//Mat::resize    改變矩陣的行數，會引起矩陣的重新分配
	//	C++: void Mat::resize(size_t sz)
	int size1[2] = { 3, 2 };
	Mat d;
	d.create(2, size1, CV_8UC3);
	cout << "原始矩陣       d = " << endl << " " << d << endl << endl;
	d.resize((3,2));
	cout << "重新分配後矩陣 d = " << endl << " " << d << endl << endl;
	//	C++ : void Mat::resize(size_t sz, const Scalar & s)
	d.resize((3, 4), Scalar(10,11,12));
	cout << "重新分配且配置向量後矩陣 d = " << endl << " " << d << endl << endl;


	//C++: Mat Mat::reshape(int cn, int rows = 0 const)
	//	cn：目標通道數，如果是0則保持和原通道數一致；
	//	rows：目標行數，同上是0則保持不變；

	Mat re_d = d.reshape(3, 2);
	cout << "重新碩型後矩陣 d = " << endl << " " << re_d << endl << endl;



	//隨機生0-255 rand表示random，u表示uniform
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));//隨機
	cout << "隨機分布矩陣         R = " << endl << " " << R << endl << endl;

	//randn(image, Scalar(128), Scalar(10));
	//高斯分佈的隨機數矩陣；第二個引數是均值，第三個引數是標差。
	Mat R1 = Mat(3, 2, CV_8UC1);
	randn(R1, Scalar(128), Scalar(10));//隨機
	cout << "高斯分佈的隨機數矩陣 R1 = " << endl << " " << R1 << endl << endl;


	//4.矩陣拷貝
	cout << "--------------------------------------4.矩陣拷貝--------------------------------------" << endl << endl;

	//淺拷貝
	//1.void copyTo (OutputArray m) const
	Mat copy_R ;
	R.copyTo(copy_R);
	//2.Mat::clone() 
	Mat clone_R = R.clone();

	//深拷貝
	
	//3.用 =
	Mat equal_R = R;

	//4.Mat()
	Mat Mat_R (R);
	cout << "原始矩陣R = " << endl << " " << R << endl << endl;
	R += 10;
	
	
	cout << "變更後原始矩陣R = " << endl << " " << R << endl << endl;
	cout << "copyTo   =" << endl << " " << copy_R << endl << endl;
	cout << "clone  = " << endl << " " << clone_R << endl << endl;
	cout << "equal_R  = " << endl << " " << equal_R << endl << endl;
	cout << "Mat_R (R) = " << endl << " " << Mat_R << endl << endl;



	//5.影像處理
	cout << "--------------------------------------5.影像處理--------------------------------------" << endl << endl;

	//創造影像
	Mat image1(240, 320, CV_8UC3);
	//imshow("123", image1);
	//waitKey(3000);


	//void Mat::locateROI(Size & wholeSize, Point & ofs) const
	// locateROI 返回與根圖像相關的偏移量，而與 ROI 父級無關
	cv::Mat img1(100, 100, CV_8UC1);               // the root image
	cv::Mat imgROI(img1, cv::Rect(10, 10, 60, 60));  // a ROI in the root image
	cv::Mat roiROI(imgROI, cv::Rect(5, 5, 30, 30)); // a ROI into a ROI

	Point offset;
	Size wholesize;
	imgROI.locateROI(wholesize, offset);
	cout << "imgRoi Offset: " << offset.x << "," << offset.y << endl;

	roiROI.locateROI(wholesize, offset);
	cout << "roiRoi Offset: " << offset.x << "," << offset.y << endl;

	//Mat& Mat::adjustROI(int dtop, int dbottom, int dleft, int dright)(t,b,l,r)(調整為移量)
	imgROI = imgROI.adjustROI(1, 1, 1 , 1);
	imgROI.locateROI(wholesize, offset);
	cout << "imgRoi Offset: " << offset.x << "," << offset.y << endl << endl;




	//6.指針相關
	cout << "--------------------------------------6.指針相關--------------------------------------" << endl << endl;
	//Mat::at     返回對指定元素的引用。
	//C++: templateT & Mat::at(int i)const
	//C++: templateT& Mat::at(int i,int j)...
	Mat o;
	int size2[2] = { 3, 2 };
	o.create(2, size2, CV_8UC1);
	cout << "原始數矩陣 o = \n"  << " " << o << endl << endl;

	o.at<uchar>(1, 1) = 255;
	cout << "利用at 改變(1,1)元素後  矩陣 o = \n" << o << endl << endl;

	//Mat::ptr    返回指定矩陣row的指针(指向哪個row開始)。
	//	C++: uchar * Mat::ptr(int i = 0)
	cout << "原始 o矩陣 \n" << o << endl << endl;
	cout << "指向row3 開始的o矩陣指針記憶體位址\n " << o.ptr<Vec3b>(2) << endl << endl;
	cout << "指向row3 開始的o矩陣指針元素\n " << o.ptr<Vec3b>(2)[0] << endl << endl;
	
	for (size_t i = 0; i < o.rows; i++)
	{
		for (size_t j = 0; j < o.cols; j++)
		{
			o.ptr<Vec3b>(i)[j][0] *= 0.5;
			o.ptr<Vec3b>(i)[j][1] *= 0.5;
			o.ptr<Vec3b>(i)[j][2] = 255;
			
		}
	}
	cout << "改變後 o矩陣\n " << o << endl << endl;
	
	//Mat::addref
	//計數器參考。
	//	C++: void Mat::addref()
	Mat M;
	M = (Mat_<int>(3,3) << 1,2,3,4,5,6,7,8,9);
	cout << "原始 M矩陣 \n" << M << endl << endl;

	//Mat::release
	//在必要的情況下，遞減引用計數並釋放該矩陣。
	//C++: void Mat::release()
	M.release();
	cout << "釋放後 M矩陣 \n" << M << endl << endl;




	//Mat::begin    返回矩陣疊代器，並將其設置為第一矩陣元。
	//Mat::end   返回矩陣疊代器，並將其設置為最後元素（after-last）的矩陣元。
	MatConstIterator_<uchar> it = o.begin<uchar>(), it_end = o.end<uchar>();
	int sum = 0;
	for (; it != it_end; ++it) 
		sum += *it;	
	cout << "利用疊代器begin,end 加總元素內容\n" << sum << endl << endl;


	
	return 0;
}
