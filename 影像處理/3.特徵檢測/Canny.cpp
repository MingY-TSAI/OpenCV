#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;

//特徵檢測

void main() {

	string path = "Resources/1.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, imgCanny;


	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

	//void cv::Canny(InputArray image, OutputArray edges, double threshold1, double threshold2, 
	//	int apertureSize = 3, bool L2gradient = false)
	//Parameters
	//	image	8 位輸入圖像。
	//	edges	輸出邊緣圖(edge map)；單通道 8 位圖像，與 image 大小相同。
	//	threshold1	滯後過程的第一個閾值。
	//	threshold2		滯後過程的第二個閾值
	//	apertureSize	Sobel 算子的孔徑大小。
	//	L2gradient		一個標誌，表示是否用更準確規範 L2 norm = ((dI / dx)**2 + (dI / dy)**2)**0.5 should 
	//	計算梯度大小(L2gradient = true), 或
	//	用預設 L1 norm = | dI / dx | +| dI / dy | 就足夠(L2gradient = false).


	Canny(imgBlur, imgCanny, 25, 75);



	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("ImageCanny", imgCanny);


	



	waitKey(0);

}