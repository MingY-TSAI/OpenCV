#include <opencv2/highgui.hpp> 
//開啟視訊鏡頭需要標頭檔
#include <opencv2/imgcodecs.hpp> 
#include<opencv2/imgproc.hpp> 
#include<iostream> 

using namespace cv;
using namespace std;



void main() {

	VideoCapture cap(0);
	//設定camera,0為預設筆電鏡頭

	Mat img;//設定img物件(矩陣)


	while (true) {

		cap.read(img);
		
		imshow("Image", img);//顯示影像

		waitKey(1);//設定
	}
}