#include <opencv2/imgcodecs.hpp> 

#include <opencv2/highgui.hpp> 

#include<opencv2/imgproc.hpp> 

#include<iostream> 





using namespace cv;

using namespace std;

//「平滑處理」（smoothing）也稱「模糊處理」（bluring）
//對於圖像濾波一般有兩點要求：
//（1）不能損壞圖像的重要特徵信息（如輪廓和邊緣等）；
//（2）圖像經濾波處理後清晰度更高；
//還有兩點目的：
//（1）抽出圖像的特徵作爲圖像識別的特徵模式；
//（2）適應圖像處理時項目的要求，儘可能的降低噪聲；

void main() {

	string path = "Resources/0.png";

	Mat img = imread(path);

	Mat imgGray, img_GaussBlur, img_Boxfilter, img_medianBlur, img_bilateralFilter;



	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//1.均值濾波
	// 一個歸一化卷積框完成的。它取卷積核區域下所有像素的平均值並替換中心元素
	//void cv::boxFilter(InputArray src, OutputArray dst, int ddepth, Size ksize, Point anchor = Point(-1, -1), 
	//	bool normalize = true, int 	borderType = BORDER_DEFAULT)
	//Parameters
	//	src			輸入圖像
	//	dst			輸出與 src 大小和類型相同的圖像。
	//	ddepth		輸出圖像深度（-1 使用src.depth()）
	//	ksize		模糊內核大小。
	//	anchor		錨點；預設值 Point(-1,-1) 表示錨點位於內核中心。
	//	normalize	標誌，指定內核是否按其區域規範化。
	//	borderType	邊框模式用於推斷圖像外的像素，請參閱BorderTypes。不支持BORDER_WRAP。


	boxFilter(imgGray, img_Boxfilter, -1, Size(3,3));



	//2.高斯模糊
	// 把捲積核換成高斯核。它是通過函數
	// 我們應該指定卷積核的寬度和高度，它應該是正數並且是奇數。我們還應該分別指定X和Y方向的標準偏差sigmaX和sigmaY
	//void cv::GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY = 0, 
	//	int borderType = BORDER_DEFAULT)

	//Parameters
	//	src	     輸入圖像；圖像可以有任意數量的通道，獨立處理，但深度應為 CV_8U、CV_16U、CV_16S、CV_32F 或 CV_64F。
	//	dst	     輸出與 src 大小和類型相同的圖像。
	//	ksize	 高斯核大小。ksize.width 和 ksize.height 可以不同，但​​它們都必須是正數和奇數。
	//			 或它們可以是零，然後根據 sigma 計算它們。
	//	sigmaX	 X 方向的高斯核標準偏差。
	//	sigmaY	 Y方向的高斯核標準偏差；
	//			 如果 sigmaY 為零，則設置為等於 sigmaX，如果兩個 sigma 都為零，則分別從 ksize.width 和 ksize.height 計算
	//			 (詳見getGaussianKernel）；為了完全控制結果，而不管所有這些語義將來可能進行的修改，
	//			 建議指定所有 ksize、sigmaX 和 sigmaY。
	//	borderType		像素外推方法，參見BorderTypes。不支持BORDER_WRAP。


	//Mat kernel = getGaussianKernel(4, 2,  CV_64F);
	GaussianBlur(imgGray, img_GaussBlur, Size(3, 3), 2, 0);

	//3.中值濾波
	// 利用median filter將胡椒鹽雜訊去除，仍然能保持邊緣的銳度。
	//void cv::medianBlur(InputArray 	src, OutputArray 	dst, int 	ksize)
	//Parameters
	//	src			輸入 1、3 或 4 通道圖像；當 ksize 為 3 或 5 時，圖像深度應為 CV_8U、CV_16U 或 CV_32F，
	//				對於較大的光圈尺寸，只能為 CV_8U。
	//	dst			與 src 具有相同大小和類型的目標數組。
	//	ksize		孔徑線性尺寸；它必須是奇數並且大於 1，例如：3, 5, 7 ...
	medianBlur(imgGray, img_medianBlur	,3);

	//4. 雙邊濾波
	//在降噪方面非常有效，同時保持邊緣清晰。但與其他過濾器相比，操作速度較慢。

	//void cv::bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace, 
	//	int borderType = BORDER_DEFAULT)
	//Parameters
	//	src			8 位或浮點、1 通道或 3 通道圖像來源。
	//	dst			與 src 具有相同大小和類型的目標圖像。
	//	d			過濾期間使用的每個像素鄰域的直徑。如果它是非正數，則從 sigmaSpace 計算。
	//	sigmaColor	在顏色空間中過濾 sigma。較大的參數值意味著像素鄰域內更遠的顏色（請參閱 sigmaSpace）
	//				將混合在一起，從而產生更大的半等色區域。
	//	sigmaSpace	在坐標空間中過濾 sigma。較大的參數值意味著更遠的像素會相互影響，只要它們的顏色足夠接近
	//				（請參閱 sigmaColor ）。當 d>0 時，它指定鄰域大小而不管 sigmaSpace。否則，d 與 sigmaSpace 成正比。
	//	borderType	邊框模式用於外推圖像外的像素，請參閱BorderTypes

	bilateralFilter(imgGray, img_bilateralFilter, 3,75,75);


	imshow("Image", img);

	imshow("ImageGray", imgGray);

	imshow("ImageBlur", img_GaussBlur);
	imshow("ImageBoxfilter", img_Boxfilter);
	imshow("ImagemedianBlur", img_medianBlur);
	imshow("ImagebilateralFilter", img_bilateralFilter);


	waitKey(0);

}