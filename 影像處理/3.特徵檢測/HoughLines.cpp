
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
int main()
{
    // Declare the output variables
    Mat dst, cdst, cdstP;
 

    Mat src = imread("Resources/4.png");

    // Edge detection
    Canny(src, dst, 50, 200, 3);


    // Copy edges to the images that will display the results in BGR
    cvtColor(dst, cdst, COLOR_GRAY2BGR);


    //void cv::HoughLines(InputArray 	image, OutputArray 	lines, double 	rho, double 	theta, int 	threshold,
    //                     double 	srn = 0, double 	stn = 0, double 	min_theta = 0, double 	max_theta = CV_PI)
    //Parameters
    //    image			8 位單通道二進制源圖像。圖像可以被函數修改。
    //    lines		    線的輸出向量。每條線由一個 2 或 3 元素向量vector (ρ,θ) or (ρ,θ,votes) 表示
    //                  ρ  是距坐標原點的距離 ( 0 , 0)(圖像的左上角) θ 是以弧度為單位的線旋轉角度 ( 0 ∼垂直線, π/ 2∼水平線 ）
    //                  votes 是累加器的值。
    //    rho	        累加器的距離分辨率（以像素為單位）。
    //    theta	        以弧度為單位的累加器的角度分辨率。
    //    threshold		累加器閾值參數。僅返回獲得足夠選票的那些行（>門檻 ）。
    //    srn	        對於多尺度霍夫變換，它是距離分辨率 rho 的除數。粗略累加器距離分辨率為 rho ，精確累加器分辨率為 rho/srn 
    //                  。如果 srn=0 和 stn=0 ，則使用經典的霍夫變換。否則，這兩個參數都應為正。
    //    stn	        對於多尺度 Hough 變換，它是距離分辨率 theta 的除數。
    //    min_theta     對於標準和多尺度霍夫變換，檢查線條的最小角度。必須介於 0 和 max_theta 之間。
    //    max_theta	    對於標準和多尺度霍夫變換，檢查線條的最大角度。必須介於 min_theta 和 CV_PI 之間。

    cdstP = cdst.clone();
    // Standard Hough Line Transform
    vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(dst, lines, 1, CV_PI / 2, 200, 0, 0); // runs the actual detection
    // Draw the lines
    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
    }


    //void cv::HoughLinesP(InputArray 	image, OutputArray 	lines, double 	rho, double 	theta, 
    //                        int 	threshold, double 	minLineLength = 0, double 	maxLineGap = 0 )

    //Parameters
    //    image	        8 位單通道二進制源圖像。圖像可以被函數修改。
    //    lines	        線的輸出向量。每條線由  4元素向量vector (x1, y1, x2, y2), 其中(x1, y1) 和(x2, y2) 是每個檢測到的線段的終點。.
    //    rho	        累加器的距離分辨率（以像素為單位）
    //    theta	        以弧度為單位的累加器的角度分辨率。
    //    threshold	    累加器閾值參數。僅返回獲得足夠選票的那些行（>門檻 ）。
    //    minLineLength	最小線長。比它短的線段被拒絕。
    //    maxLineGap	連接它們的同一條線上的點之間的最大允許間隙。

    // Probabilistic Line Transform
    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(dst, linesP, 1, CV_PI / 2, 30, 50, 10); // runs the actual detection

    // Draw the lines
    for (size_t i = 0; i < linesP.size(); i++)
    {
        Vec4i l = linesP[i];
        line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
    }


    //void cv::HoughLinesPointSet(InputArray 	_point,
    //    OutputArray 	_lines,
    //    int 	lines_max,
    //    int 	threshold,
    //    double 	min_rho,
    //    double 	max_rho,
    //    double 	rho_step,
    //    double 	min_theta,
    //    double 	max_theta,
    //    double 	theta_step
    //)
    //用於標準霍夫變換在一組點中查找線。

    // Show results
    imshow("Source", src);
    imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
    imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
    // Wait and Exit
    waitKey();
    return 0;

}