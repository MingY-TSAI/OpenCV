#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;

//�S�x�˴�

void main() {

	string path = "Resources/1.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, imgCanny;


	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

	//void cv::Canny(InputArray image, OutputArray edges, double threshold1, double threshold2, 
	//	int apertureSize = 3, bool L2gradient = false)
	//Parameters
	//	image	8 ���J�Ϲ��C
	//	edges	��X��t��(edge map)�F��q�D 8 ��Ϲ��A�P image �j�p�ۦP�C
	//	threshold1	����L�{���Ĥ@���H�ȡC
	//	threshold2		����L�{���ĤG���H��
	//	apertureSize	Sobel ��l���ծ|�j�p�C
	//	L2gradient		�@�Ӽлx�A��ܬO�_�Χ�ǽT�W�d L2 norm = ((dI / dx)**2 + (dI / dy)**2)**0.5 should 
	//	�p���פj�p(L2gradient = true), ��
	//	�ιw�] L1 norm = | dI / dx | +| dI / dy | �N����(L2gradient = false).


	Canny(imgBlur, imgCanny, 25, 75);



	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("ImageCanny", imgCanny);


	



	waitKey(0);

}