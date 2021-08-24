#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;

//特徵檢測(影像)

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
	//	image				輸入 8 位或浮點 32 位單通道圖像。
	//	corners				檢測到的角點的輸出向量。
	//	maxCorners			要返回的最大角數。如果角的數量多於找到的角，則返回其中最強的角。
	//						maxCorners <= 0意味著沒有設置最大值限制並且返回所有檢測到的角點。
	//	qualityLevel		表徵圖像角點的最小可接受質量的參數。參數值乘以最佳角質量度量，
	//						即最小特徵值（參見cornerMinEigenVal）或Harris 函數響應（參見cornerHarris）。
	//						質量小於產品的角被拒絕。例如，如果最佳角的質量度量 = 1500，
	//						並且 qualityLevel=0.01 ，則質量度量小於 15 的所有角都將被拒絕。
	//	minDistance			返回的角之間的最小可能的歐幾里得距離。
	//	mask				可選的感興趣區域。如果圖像不為空（需要類型為 CV_8UC1 且大小與 image 相同），
	//						則指定檢測角點的區域。
	//	blockSize			用於計算每個像素鄰域上的導數協方差矩陣的平均塊的大小。
	//						請參閱 cornerEigenValsAndVecs 。
	//	useHarrisDetector	指示是使用 Harris 檢測器（請參閱cornerHarris）還是cornerMinEigenVal 的參數。
	//	k					Harris 檢測器的自由參數。

	Mat copy;
	img.copyTo(copy);

	//設定角點檢測引數
	vector<cv::Point2f> corners;
	int max_corners = 600;
	double quality_level = 0.01;
	double min_distance = 3.0;
	int block_size = 3;
	bool use_harris = false;
	double k = 0.04;

	//角點檢測
	goodFeaturesToTrack(imgBlur,
		corners,
		max_corners,
		quality_level,
		min_distance,
		Mat(),
		block_size,
		use_harris,
		k);

	//將檢測到的角點繪製到原圖上
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

