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

	
	//�p��Ω��I�˴����S�x�ϡC
	//void cv::preCornerDetect(InputArray 	src, OutputArray 	dst,
	//							int 	ksize, int 	borderType = BORDER_DEFAULT)
	//Parameters
	//	src			��q�D 8 ��B�I�Ϲ��C
	//	dst			������ CV_32F �B�j�p�P src �ۦP����X�Ϲ��C
	//	ksize		Sobel ���ծ|�j�p�C
	//	borderType	�����~���k�C�����BORDER_WRAP�C




	Mat corner;
	preCornerDetect(imgCanny, corner, 5);
	//// �� 3x3 �x�ε��c�����i�濱��


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