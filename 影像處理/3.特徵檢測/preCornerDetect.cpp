#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;



void main() {

	string path = "Resources/2.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;



	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

	Canny(imgBlur, imgCanny, 25, 75);

	
	//計算用於角點檢測的特徵圖。
	//void cv::preCornerDetect(InputArray 	src, OutputArray 	dst,
	//							int 	ksize, int 	borderType = BORDER_DEFAULT)
	//Parameters
	//	src			單通道 8 位浮點圖像。
	//	dst			類型為 CV_32F 且大小與 src 相同的輸出圖像。
	//	ksize		Sobel 的孔徑大小。
	//	borderType	像素外推法。不支持BORDER_WRAP。




	Mat corner;
	preCornerDetect(imgCanny, corner, 5);
	//// 用 3x3 矩形結構元素進行膨脹


	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(corner, imgDil, kernel);

	erode(imgDil, imgErode, kernel);





	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("ImageCanny", imgCanny);

	imshow("corner", corner);

	imshow("ImageDilation", imgDil);

	imshow("ImageErode", imgErode);
	


	waitKey(0);

}