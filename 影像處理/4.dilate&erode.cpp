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
	//	src			��J�Ϲ��F�q�D�ƥi�H���N�A���`������CV_8U�BCV_16U�BCV_16S�BCV_32F��CV_64F���@�C
	//	dst			��X�P src �j�p�M�����ۦP���Ϲ��C
	//	kernel		�Ω󿱵Ȫ����c�����F�p�G elemenat=Mat()�A�h�ϥ� 3 x 3 �x�ε��c�����C�i�H�ϥ�getStructuringElement�Ыؤ���
	//	anchor		���������I����m�F�q�{�� (-1, -1) ������I��󤸯����ߡC
	//	iterations	�����X�i�����ơC
	//	borderType	�����~����k�A�Ѩ�BorderTypes�CBORDER_WRAP���䴩�C
	//	borderValue	��ɤ��ܪ����p�U����ɭ�


	dilate(imgCanny, imgDil, kernel);



	//void cv::erode(InputArray 	src, OutputArray 	dst, InputArray 	kernel,
	//	Point 	anchor = Point(-1, -1), int 	iterations = 1, int  borderType = BORDER_CONSTANT, 
	//	const Scalar & borderValue = morphologyDefaultBorderValue())

	//Parameters
	//	src			��J�Ϲ��F�q�D�ƥi�H���N�A���`������CV_8U�BCV_16U�BCV_16S�BCV_32F��CV_64F���@�C
	//	dst			��X�P src �j�p�M�����ۦP���Ϲ��C
	//	kernel		�Ω�I�k�����c�����F�p�Gelement=Mat()�A3 x 3�h�ϥίx�ε��c�����C�i�H�ϥ�getStructuringElement�Ыؤ��֡C
	//	anchor		���������I����m�F�q�{�� (-1, -1) ������I��󤸯����ߡC
	//	iterations	���ΫI�k�����ơC
	//	borderType	�����~����k�A�Ѩ�BorderTypes�C�����BORDER_WRAP�C
	//	borderValue	��ɤ��ܪ����p�U����ɭ�

	erode(imgDil, imgErode, kernel);





	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("ImageCanny", imgCanny);

	imshow("ImageDilation", imgDil);

	imshow("ImageErode", imgErode);



	waitKey(0);

}