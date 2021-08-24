#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;



void main() {

	string path = "Resources/4.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;



	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));


	//void cv::dilate(InputArray 	src, OutputArray 	dst, InputArray 	kernel, Point 	anchor = Point(-1, -1),
	//	int 	iterations = 1, int 	borderType = BORDER_CONSTANT, 
	//	const Scalar & borderValue = morphologyDefaultBorderValue())

	//Parameters
	//	src			輸入圖像；通道數可以任意，但深度應為CV_8U、CV_16U、CV_16S、CV_32F或CV_64F之一。
	//	dst			輸出與 src 大小和類型相同的圖像。
	//	kernel		用於膨脹的結構元素；如果 elemenat=Mat()，則使用 3 x 3 矩形結構元素。可以使用getStructuringElement創建內核
	//	anchor		元素內錨點的位置；默認值 (-1, -1) 表示錨點位於元素中心。
	//	iterations	應用擴張的次數。
	//	borderType	像素外推方法，參見BorderTypes。BORDER_WRAP不支援。
	//	borderValue	邊界不變的情況下的邊界值


	dilate(imgCanny, imgDil, kernel);



	//void cv::erode(InputArray 	src, OutputArray 	dst, InputArray 	kernel,
	//	Point 	anchor = Point(-1, -1), int 	iterations = 1, int  borderType = BORDER_CONSTANT, 
	//	const Scalar & borderValue = morphologyDefaultBorderValue())

	//Parameters
	//	src			輸入圖像；通道數可以任意，但深度應為CV_8U、CV_16U、CV_16S、CV_32F或CV_64F之一。
	//	dst			輸出與 src 大小和類型相同的圖像。
	//	kernel		用於侵蝕的結構元素；如果element=Mat()，3 x 3則使用矩形結構元素。可以使用getStructuringElement創建內核。
	//	anchor		元素內錨點的位置；默認值 (-1, -1) 表示錨點位於元素中心。
	//	iterations	應用侵蝕的次數。
	//	borderType	像素外推方法，參見BorderTypes。不支持BORDER_WRAP。
	//	borderValue	邊界不變的情況下的邊界值

	erode(imgDil, imgErode, kernel);





	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("ImageCanny", imgCanny);

	imshow("ImageDilation", imgDil);

	imshow("ImageErode", imgErode);



	waitKey(0);

}