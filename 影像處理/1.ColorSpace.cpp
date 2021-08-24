#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 



using namespace cv;

using namespace std;


// �Ϲ��G�Ȥ�(�Ƕ�)�X> �����ҽk(�o��)�X>Canny��t�˴��X>Dilate/Erode�]����/�I�k)
void main() {

	string path = "Resources/0.png";

	Mat img = imread(path);

	Mat imgGray,  imgBayer, imgdemosaicing;

	
	//�ഫ��m�Ŷ��A�åH�Ƕ���X

	//void cv::cvtColor(InputArray 	src, OutputArray 	dst, int 	code, int 	dstCn = 0)
	//Parameters
	//	src		��J�Ϲ��G8 ��L�Ÿ��B16 ��L�Ÿ� ( CV_16UC... ) �γ��ׯB�I�C
	//	dst		��X�P src �j�p�M�`�׬ۦP���Ϲ��C
	//	dstCn	�ؼйϹ������q�D�ơF�p�G�ѼƬ� 0�A�h�q�D�Ʀ۰ʱq src �M code �ɥX
	//	code	�C��Ŷ��ഫ�N�X  COLOR_BGR2BGRA  COLOR_BGR2GRAY  COLOR_BGR2HSV  COLOR_BayerBG2BGR_VNG 
		
		//1�BRGB�MBGR�]opencv�q�{���m��Ϲ����C��Ŷ��OBGR�^�C��Ŷ����ഫ
		//cv::COLOR_BGR2RGB
		//cv::COLOR_RGB2BGR
		//cv::COLOR_RGBA2BGRA
		//cv::COLOR_BGRA2RGBA

		//2�B�VRGB�MBGR�Ϲ����W�Kalpha�q�D
		//cv::COLOR_RGB2RGBA
		//cv::COLOR_BGR2BGRA

		//3�B�qRGB�MBGR�Ϲ����h��alpha�q�D

		//cv::COLOR_RGBA2RGB
		//cv::COLOR_BGRA2BGR

		//4�B�qRBG�MBGR�C��Ŷ��ഫ��Ƕ��Ŷ�
		//	cv::COLOR_RGB2GRAY
		//	cv::COLOR_BGR2GRAY
		//	cv::COLOR_RGBA2GRAY
		//	cv::COLOR_BGRA2GRAY

		//5�B�q�ǫתŶ��ഫ��RGB�MBGR�C��Ŷ�
		//	cv::COLOR_GRAY2RGB
		//	cv::COLOR_GRAY2BGR
		//	cv::COLOR_GRAY2RGBA
		//	cv::COLOR_GRAY2BGRA

		//6�BRGB�MBGR�C��Ŷ��PBGR565�C��Ŷ��������ഫ
		//	cv::COLOR_RGB2BGR565
		//	cv::COLOR_BGR2BGR565
		//	cv::COLOR_BGR5652RGB
		//	cv::COLOR_BGR5652BGR
		//	cv::COLOR_RGBA2BGR565
		//	cv::COLOR_BGRA2BGR565
		//	cv::COLOR_BGR5652RGBA
		//	cv::COLOR_BGR5652BGRA

		//7�B�ǫתŶ���BGR565�������ഫ
		//cv::COLOR_GRAY2BGR555
		//cv::COLOR_BGR5552GRAY

		//8�BRGB�MBGR�C��Ŷ��PCIE XYZ�������ഫ
		//	cv::COLOR_RGB2XYZ
		//	cv::COLOR_BGR2XYZ
		//	cv::COLOR_XYZ2RGB
		//	cv::COLOR_XYZ2BGR

		//9�BRGB�MBGR�C��Ŷ��Puma��ס]YCrCb�Ŷ��^�������ഫ
		//	cv::COLOR_RGB2YCrCb
		//	cv::COLOR_BGR2YCrCb
		//	cv::COLOR_YCrCb2RGB
		//	cv::COLOR_YCrCb2BGR



		//10�BRGB�MBGR�C��Ŷ��PHSV�C��Ŷ��������ۤ��ഫ
		//	cv::COLOR_RGB2HSV
		//	cv::COLOR_BGR2HSV
		//	cv::COLOR_HSV2RGB
		//	cv::COLOR_HSV2BGR

		//11�BRGB�MBGR�C��Ŷ��PHLS�C��Ŷ��������ۤ��ഫ
		//	cv::COLOR_RGB2HLS
		//	cv::COLOR_BGR2HLS
		//	cv::COLOR_HLS2RGB
		//	cv::COLOR_HLS2BGR

		//12�BRGB�MBGR�C��Ŷ��PCIE Lab�C��Ŷ��������ۤ��ഫ
		// ��� 8 ��M 16 ��Ϲ��AR�BG �M B �Q�ഫ���B�I�榡���Y��H�A�� 0 �� 1 ���d��C
		//	cv::COLOR_RGB2Lab
		//	cv::COLOR_BGR2Lab
		//	cv::COLOR_Lab2RGB
		//	cv::COLOR_Lab2BGR

		//13�BRGB�MBGR�C��Ŷ��PCIE Luv�C��Ŷ��������ۤ��ഫ
		// ��� 8 ��M 16 ��Ϲ��AR�BG �M B �Q�ഫ���B�I�榡���Y��H�A�� 0 �� 1 ���d��C
		//	cv::COLOR_RGB2Luv
		//	cv::COLOR_BGR2Luv
		//	cv::COLOR_Luv2RGB
		//	cv::COLOR_Luv2BGR
		
		//14�BBayer�榡�]raw data�^�VRGB��BGR�C��Ŷ����ഫ
		// �s�x�Ω� CCD �M CMOS �۾��C���ϱz����q��ӥ�������m��Ϥ��A
		// �䤤 R�BG �M B �����]�S�w�ե󪺶ǷP���^���p�U�覡���
		//	cv::COLOR_BayerBG2RGB
		//	cv::COLOR_BayerGB2RGB
		//	cv::COLOR_BayerRG2RGB
		//	cv::COLOR_BayerGR2RGB
		//	cv::COLOR_BayerBG2BGR
		//	cv::COLOR_BayerGB2BGR
		//	cv::COLOR_BayerRG2BGR
		//	cv::COLOR_BayerGR2BGR


	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	cvtColor(imgGray, imgBayer, COLOR_GRAY2RGB);

	cvtColor(imgGray, imgdemosaicing, COLOR_BayerBG2BGR_VNG);




	imshow("Image", img);
	imshow("ImageGray", imgGray);
	imshow("ImageBayer", imgBayer);
	imshow("Imagedemosaicing", imgdemosaicing);




	waitKey(0);

}