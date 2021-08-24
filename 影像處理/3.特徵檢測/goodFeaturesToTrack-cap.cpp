#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <ctype.h>
using namespace cv;
using namespace std;


//  按滑鼠左鍵單顆描點  
//  按r描所有邊 
//  按c清除  
//  按n去除背景

Point2f point;
bool addRemovePt = false;
static void onMouse(int event, int x, int y, int /*flags*/, void* /*param*/)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        point = Point2f((float)x, (float)y);
        addRemovePt = true;
    }
}
int main(int argc, char** argv)
{
    VideoCapture cap;
    TermCriteria termcrit(TermCriteria::COUNT | TermCriteria::EPS, 20, 0.03);
    Size subPixWinSize(10, 10), winSize(31, 31);
    const int MAX_COUNT = 500;
    bool needToInit = false;
    bool nightMode = false;
  
    cv::CommandLineParser parser(argc, argv, "{@input|0|}");
    string input = parser.get<string>("@input");
    if (input.size() == 1 && isdigit(input[0]))
        cap.open(input[0] - '0');
    else
        cap.open(input);
    if (!cap.isOpened())
    {
        cout << "Could not initialize capturing...\n";
        return 0;
    }
    namedWindow("LK Demo", 1);
    setMouseCallback("LK Demo", onMouse, 0);
    Mat gray, prevGray, image, frame;
    vector<Point2f> points[2];
    for (;;)
    {
        cap >> frame;
        if (frame.empty())
            break;
        frame.copyTo(image);
        cvtColor(image, gray, COLOR_BGR2GRAY);
        if (nightMode)
            image = Scalar::all(0);
        if (needToInit)
        {
            // automatic initialization
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

            goodFeaturesToTrack(gray, points[1], MAX_COUNT, 0.01, 10, Mat(), 3, 3, 0, 0.04);
            cornerSubPix(gray, points[1], subPixWinSize, Size(-1, -1), termcrit);
            addRemovePt = false;
        }
        else if (!points[0].empty())
        {
            vector<uchar> status;
            vector<float> err;
            if (prevGray.empty())
                gray.copyTo(prevGray);
            calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,
                3, termcrit, 0, 0.001);
            size_t i, k;
            for (i = k = 0; i < points[1].size(); i++)
            {
                if (addRemovePt)
                {
                    if (norm(point - points[1][i]) <= 5)
                    {
                        addRemovePt = false;
                        continue;
                    }
                }
                if (!status[i])
                    continue;
                points[1][k++] = points[1][i];
                circle(image, points[1][i], 3, Scalar(0, 255, 0), -1, 8);
            }
            points[1].resize(k);
        }
        if (addRemovePt && points[1].size() < (size_t)MAX_COUNT)
        {
            vector<Point2f> tmp;
            tmp.push_back(point);
            cornerSubPix(gray, tmp, winSize, Size(-1, -1), termcrit);
            points[1].push_back(tmp[0]);
            addRemovePt = false;
        }
        needToInit = false;
        imshow("LK Demo", image);
        char c = (char)waitKey(10);
        if (c == 27)
            break;
        switch (c)
        {
        case 'r':
            needToInit = true;
            break;
        case 'c':
            points[0].clear();
            points[1].clear();
            break;
        case 'n':
            nightMode = !nightMode;
            break;
        }
        std::swap(points[1], points[0]);
        cv::swap(prevGray, gray);
    }
    return 0;
}