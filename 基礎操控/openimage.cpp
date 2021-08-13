 #include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 



using namespace cv;
using namespace std;



void main() {

	string path = "Resources/1.png";
	//開啟圖片位置
	Mat img = imread(path);
	//轉換為Mat物件
	imshow("Image", img);

	waitKey(0);

}