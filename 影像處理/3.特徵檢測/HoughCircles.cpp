#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
using namespace cv;
using namespace std;
int main()
{
    Mat img, gray;
    img = imread("Resources/3.png");

    cvtColor(img, gray, COLOR_BGR2GRAY);
    // smooth it, otherwise a lot of false circles may be detected
    GaussianBlur(gray, gray, Size(3, 3), 2, 2);
 


    //void cv::HoughCircles(InputArray 	image, OutputArray 	circles, int 	method, double 	dp, double 	minDist, 
    //                        double 	param1 = 100, double 	param2 = 100, int 	minRadius = 0, int 	maxRadius = 0)

    //Parameters
    //    image	    8 位、單通道、灰度輸入圖像。
    //    circles	找到的圓的輸出向量. 每個向量被編碼為 3 或 4 元素浮點向量point vector(x, y, radius) 或 (x, y, radius, votes) .
    //    method	檢測方法，參見HoughModes。可用的方法是HOUGH_GRADIENT和HOUGH_GRADIENT_ALT。
    //    dp	    累加器分辨率與圖像分辨率的反比。例如，如果 dp=1 ，則累加器具有與輸入圖像相同的分辨率。
    //              如果 dp=2 ，累加器的寬度和高度是原來的一半。對於HOUGH_GRADIENT_ALT，推薦值是 dp=1.5，
    //              除非需要檢測一些非常小的圓圈。
    //    minDist	檢測到的圓的中心之間的最小距離。如果參數太小，除了一個真一個外，還可能誤檢測到多個鄰居圓。
    //              如果太大，可能會遺漏一些圓圈。
    //    param1	第一個特定於方法的參數。在HOUGH_GRADIENT和HOUGH_GRADIENT_ALT 的情況下，
    //              它是傳遞給 Canny 邊緣檢測器的兩者中較高的閾值（較低的閾值小兩倍）。
    //              請注意，HOUGH_GRADIENT_ALT使用Scharr算法計算圖像導數，因此閾值通常應更高，
    //              例如 300 或正常曝光和對比度的圖像。
    //    param2	第二個特定於方法的參數。在HOUGH_GRADIENT 的情況下，它是檢測階段圓心的累加器閾值。
    //              它越小，檢測到的假圓就越多。與較大累加器值相對應的圓圈將首先返回。在HOUGH_GRADIENT_ALT算法的情況下，
    //              這是圓的“完美”度量。它越接近 1，算法選擇的形狀越好。在大多數情況下，0.9 應該沒問題。
    //              如果您想更好地檢測小圓圈，您可以將其降低到 0.85、0.8 甚至更低。
    //              但隨後也要盡量限制搜索範圍 [minRadius, maxRadius] 以避免出現很多錯誤的圈子。
    //    minRadius	最小圓半徑。
    //    maxRadius	最大圓半徑。如果 <= 0，則使用最大圖像尺寸。如果 < 0，HOUGH_GRADIENT返回中心而不找到半徑。
    //              HOUGH_GRADIENT_ALT始終計算圓半徑。


    //param1
    //HOUGH_STANDARD
    //    classical or standard Hough transform.Every line is represented by two floating - point numbers(ρ, θ),
    //    where ρ is a distance between(0, 0) pointand the line, and θ is the angle 
    //    between x - axis and the normal to the line.Thus, the matrix must be(the created sequence will be) of CV_32FC2 type
    //HOUGH_PROBABILISTIC
    //    probabilistic Hough transform(more efficient in case if the picture contains a few long linear segments).
    //    It returns line segments rather than the whole line.Each segment is represented by startingand ending points,
    //    and the matrix must be(the created sequence will be) of the CV_32SC4 type.
    //HOUGH_MULTI_SCALE
    //    multi - scale variant of the classical Hough transform.The lines are encoded the same way as HOUGH_STANDARD.
    //HOUGH_GRADIENT
    //    basically 21HT, described in[287]
    //HOUGH_GRADIENT_ALT
    //    variation of HOUGH_GRADIENT to get better accuracy


    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT,
        2, gray.rows / 200, 100, 200);

    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // draw the circle center
        circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
        // draw the circle outline
        circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
    }

    imshow("circles", img);
    waitKey(0);
    return 0;
}

