//使用 OpenCV 函數cv::cornerEigenValsAndVecs查找特徵值和特徵向量以確定像素是否為角。
//使用 OpenCV 函數cv::cornerMinEigenVal找到角點檢測的最小特徵值。
//通過使用上述兩個函數，實現我們自己版本的 Harris 檢測器以及 Shi - Tomasi 檢測器。
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src, src_gray;
Mat myHarris_dst, myHarris_copy, Mc;
Mat myShiTomasi_dst, myShiTomasi_copy;
int myShiTomasi_qualityLevel = 50;
int myHarris_qualityLevel = 50;
int max_qualityLevel = 100;
double myHarris_minVal, myHarris_maxVal;
double myShiTomasi_minVal, myShiTomasi_maxVal;
RNG rng(12345);
const char* myHarris_window = "My Harris corner detector";
const char* myShiTomasi_window = "My Shi Tomasi corner detector";
void myShiTomasi_function(int, void*);
void myHarris_function(int, void*);

int main(int argc, char** argv)
{
    
    src = imread("Resources/4.png");

    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    int blockSize = 3, apertureSize = 3;
    cornerEigenValsAndVecs(src_gray, myHarris_dst, blockSize, apertureSize);
    //抓取角點
    //定義MC調整角點
    Mc = Mat(src_gray.size(), CV_32FC1);
    for (int i = 0; i < src_gray.rows; i++)
    {
        for (int j = 0; j < src_gray.cols; j++)
        {
            float lambda_1 = myHarris_dst.at<Vec6f>(i, j)[0];
            float lambda_2 = myHarris_dst.at<Vec6f>(i, j)[1];
            Mc.at<float>(i, j) = lambda_1 * lambda_2 - 0.04f * pow((lambda_1 + lambda_2), 2);
        }
    }
    //找最小值
    minMaxLoc(Mc, &myHarris_minVal, &myHarris_maxVal);
    
    /* Create Window and Trackbar */
    namedWindow(myHarris_window);
    createTrackbar("Quality Level:", myHarris_window, &myHarris_qualityLevel, max_qualityLevel, myHarris_function);
    myHarris_function(0, 0);

    //計算角點檢測的梯度矩陣的最小特徵值。
    cornerMinEigenVal(src_gray, myShiTomasi_dst, blockSize, apertureSize);
    minMaxLoc(myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal);

    /* Create Window and Trackbar */
    namedWindow(myShiTomasi_window);
    createTrackbar("Quality Level:", myShiTomasi_window, &myShiTomasi_qualityLevel, max_qualityLevel, myShiTomasi_function);
    myShiTomasi_function(0, 0);
    waitKey();
    return 0;
}


//定義mark角點並顯示
void myShiTomasi_function(int, void*)
{
    myShiTomasi_copy = src.clone();
    myShiTomasi_qualityLevel = MAX(myShiTomasi_qualityLevel, 1);
    for (int i = 0; i < src_gray.rows; i++)
    {
        for (int j = 0; j < src_gray.cols; j++)
        {
            if (myShiTomasi_dst.at<float>(i, j) > myShiTomasi_minVal + (myShiTomasi_maxVal - myShiTomasi_minVal) * myShiTomasi_qualityLevel / max_qualityLevel)
            {
                circle(myShiTomasi_copy, Point(j, i), 4, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)), FILLED);
            }
        }
    }
    imshow(myShiTomasi_window, myShiTomasi_copy);
}
//定義mark角點並顯示
void myHarris_function(int, void*)
{
    myHarris_copy = src.clone();
    myHarris_qualityLevel = MAX(myHarris_qualityLevel, 1);
    for (int i = 0; i < src_gray.rows; i++)
    {
        for (int j = 0; j < src_gray.cols; j++)
        {
            if (Mc.at<float>(i, j) > myHarris_minVal + (myHarris_maxVal - myHarris_minVal) * myHarris_qualityLevel / max_qualityLevel)
            {
                circle(myHarris_copy, Point(j, i), 4, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)), FILLED);
            }
        }
    }
    imshow(myHarris_window, myHarris_copy);
}