#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;

//�S�x�˴�(�v��)

void main() {

	string path = "Resources/2.png";

	Mat img = imread(path);

	Mat imgGray, imgBlur, img_goodfeature;



	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	
	//
	//void cv::goodFeaturesToTrack(InputArray image, OutputArray corners, int maxCorners, double qualityLevel,
	//	double 	minDistance, InputArray mask = noArray(), int blockSize = 3, bool useHarrisDetector = false,
	//	double 	k = 0.04)
	//Parameters
	//	image				��J 8 ��ίB�I 32 ���q�D�Ϲ��C
	//	corners				�˴��쪺���I����X�V�q�C
	//	maxCorners			�n��^���̤j���ơC�p�G�����ƶq�h���쪺���A�h��^�䤤�̱j�����C
	//						maxCorners <= 0�N���ۨS���]�m�̤j�ȭ���åB��^�Ҧ��˴��쪺���I�C
	//	qualityLevel		��x�Ϲ����I���̤p�i������q���ѼơC�Ѽƭȭ��H�̨Ψ���q�׶q�A
	//						�Y�̤p�S�x�ȡ]�Ѩ�cornerMinEigenVal�^��Harris ����T���]�Ѩ�cornerHarris�^�C
	//						��q�p�󲣫~�����Q�ڵ��C�Ҧp�A�p�G�̨Ψ�����q�׶q = 1500�A
	//						�åB qualityLevel=0.01 �A�h��q�׶q�p�� 15 ���Ҧ������N�Q�ڵ��C
	//	minDistance			��^�����������̤p�i�઺�ڴX���o�Z���C
	//	mask				�i�諸�P����ϰ�C�p�G�Ϲ������š]�ݭn������ CV_8UC1 �B�j�p�P image �ۦP�^�A
	//						�h���w�˴����I���ϰ�C
	//	blockSize			�Ω�p��C�ӹ����F��W���ɼƨ��t�x�}�����������j�p�C
	//						�аѾ\ cornerEigenValsAndVecs �C
	//	useHarrisDetector	���ܬO�ϥ� Harris �˴����]�аѾ\cornerHarris�^�٬OcornerMinEigenVal ���ѼơC
	//	k					Harris �˴������ۥѰѼơC

	Mat copy;
	img.copyTo(copy);

	//�]�w���I�˴��޼�
	vector<cv::Point2f> corners;
	int max_corners = 600;
	double quality_level = 0.01;
	double min_distance = 3.0;
	int block_size = 3;
	bool use_harris = false;
	double k = 0.04;

	//���I�˴�
	goodFeaturesToTrack(imgBlur,
		corners,
		max_corners,
		quality_level,
		min_distance,
		Mat(),
		block_size,
		use_harris,
		k);

	//�N�˴��쪺���Iø�s���ϤW
	for (int i = 0; i < corners.size(); i++)
	{
		cv::circle(copy, corners[i], 1, cv::Scalar(0, 0, 255), 2, 8, 0);
	}




	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", imgBlur);

	imshow("Imagegoodfeature", copy);





	waitKey(0);

}

