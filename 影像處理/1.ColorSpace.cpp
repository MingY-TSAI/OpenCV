#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 



using namespace cv;

using namespace std;



void main() {

	string path = "Resources/0.png";

	Mat img = imread(path);

	Mat imgGray,  imgBayer, imgdemosaicing;

	
	//轉換色彩空間，並以灰階輸出

	//void cv::cvtColor(InputArray 	src, OutputArray 	dst, int 	code, int 	dstCn = 0)
	//Parameters
	//	src		輸入圖像：8 位無符號、16 位無符號 ( CV_16UC... ) 或單精度浮點。
	//	dst		輸出與 src 大小和深度相同的圖像。
	//	dstCn	目標圖像中的通道數；如果參數為 0，則通道數自動從 src 和 code 導出
	//	code	顏色空間轉換代碼  COLOR_BGR2BGRA  COLOR_BGR2GRAY  COLOR_BGR2HSV  COLOR_BayerBG2BGR_VNG 
		
		//1、RGB和BGR（opencv默認的彩色圖像的顏色空間是BGR）顏色空間的轉換
		//cv::COLOR_BGR2RGB
		//cv::COLOR_RGB2BGR
		//cv::COLOR_RGBA2BGRA
		//cv::COLOR_BGRA2RGBA

		//2、向RGB和BGR圖像中增添alpha通道
		//cv::COLOR_RGB2RGBA
		//cv::COLOR_BGR2BGRA

		//3、從RGB和BGR圖像中去除alpha通道

		//cv::COLOR_RGBA2RGB
		//cv::COLOR_BGRA2BGR

		//4、從RBG和BGR顏色空間轉換到灰階空間
		//	cv::COLOR_RGB2GRAY
		//	cv::COLOR_BGR2GRAY
		//	cv::COLOR_RGBA2GRAY
		//	cv::COLOR_BGRA2GRAY

		//5、從灰度空間轉換到RGB和BGR顏色空間
		//	cv::COLOR_GRAY2RGB
		//	cv::COLOR_GRAY2BGR
		//	cv::COLOR_GRAY2RGBA
		//	cv::COLOR_GRAY2BGRA

		//6、RGB和BGR顏色空間與BGR565顏色空間之間的轉換
		//	cv::COLOR_RGB2BGR565
		//	cv::COLOR_BGR2BGR565
		//	cv::COLOR_BGR5652RGB
		//	cv::COLOR_BGR5652BGR
		//	cv::COLOR_RGBA2BGR565
		//	cv::COLOR_BGRA2BGR565
		//	cv::COLOR_BGR5652RGBA
		//	cv::COLOR_BGR5652BGRA

		//7、灰度空間域BGR565之間的轉換
		//cv::COLOR_GRAY2BGR555
		//cv::COLOR_BGR5552GRAY

		//8、RGB和BGR顏色空間與CIE XYZ之間的轉換
		//	cv::COLOR_RGB2XYZ
		//	cv::COLOR_BGR2XYZ
		//	cv::COLOR_XYZ2RGB
		//	cv::COLOR_XYZ2BGR

		//9、RGB和BGR顏色空間與uma色度（YCrCb空間）之間的轉換
		//	cv::COLOR_RGB2YCrCb
		//	cv::COLOR_BGR2YCrCb
		//	cv::COLOR_YCrCb2RGB
		//	cv::COLOR_YCrCb2BGR



		//10、RGB和BGR顏色空間與HSV顏色空間之間的相互轉換
		//	cv::COLOR_RGB2HSV
		//	cv::COLOR_BGR2HSV
		//	cv::COLOR_HSV2RGB
		//	cv::COLOR_HSV2BGR

		//11、RGB和BGR顏色空間與HLS顏色空間之間的相互轉換
		//	cv::COLOR_RGB2HLS
		//	cv::COLOR_BGR2HLS
		//	cv::COLOR_HLS2RGB
		//	cv::COLOR_HLS2BGR

		//12、RGB和BGR顏色空間與CIE Lab顏色空間之間的相互轉換
		// 對於 8 位和 16 位圖像，R、G 和 B 被轉換為浮點格式並縮放以適應 0 到 1 的範圍。
		//	cv::COLOR_RGB2Lab
		//	cv::COLOR_BGR2Lab
		//	cv::COLOR_Lab2RGB
		//	cv::COLOR_Lab2BGR

		//13、RGB和BGR顏色空間與CIE Luv顏色空間之間的相互轉換
		// 對於 8 位和 16 位圖像，R、G 和 B 被轉換為浮點格式並縮放以適應 0 到 1 的範圍。
		//	cv::COLOR_RGB2Luv
		//	cv::COLOR_BGR2Luv
		//	cv::COLOR_Luv2RGB
		//	cv::COLOR_Luv2BGR
		
		//14、Bayer格式（raw data）向RGB或BGR顏色空間的轉換
		// 廣泛用於 CCD 和 CMOS 相機。它使您能夠從單個平面獲取彩色圖片，
		// 其中 R、G 和 B 像素（特定組件的傳感器）按如下方式交錯
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
