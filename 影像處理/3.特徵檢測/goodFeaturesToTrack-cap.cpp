#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <ctype.h>
using namespace cv;
using namespace std;


//  ���ƹ���������y�I  
//  ��r�y�Ҧ��� 
//  ��c�M��  
//  ��n�h���I��

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
            //	image				��J 8 ��ίB�I 32 ���q�D�Ϲ��C
            //	corners				�˴��쪺���I����X�V�q�C
            //	maxCorners			�n��^���̤j���ơC�p�G�����ƶq�h���쪺���A�h��^�䤤�̱j�����C
            //						maxCorners <= 0�N���ۨS���]�m�̤j�ȭ���åB��^�Ҧ��˴��쪺���I�C
            //	qualityLevel		��x�Ϲ����I���̤p�i������q���ѼơC�Ѽƭȭ��H�̨Ψ���q�׶q�A
            //						�Y�̤p�S�x�ȡ]�Ѩ�cornerMinEigenVal�^��Harris ����T���]�Ѩ�cornerHarris�^�C
            //						��q�p�󲣫~�����Q�ڵ��C�Ҧp�A�p�G�̨Ψ�����q�׶q = 1500�A
            //						�åB qualityLevel=0.01 �A�h��q�׶q�p�� 15 ���Ҧ������N�Q�ڵ��C
            //	minDistance			��^�����������̤p�i�઺�ڴX���o�Z���C
            //	mask				�i�諸�P����ϰ�C�p�G�Ϲ������š]�ݭn������ CV_8UC1 �B�j�p�P image �ۦP�^�A
            //						�h���w�˴����I���ϰ�C
            //	blockSize			�Ω�p��C�ӹ����F��W���ɼƨ��t�x�}�����������j�p�C
            //						�аѾ\ cornerEigenValsAndVecs �C
            //	useHarrisDetector	���ܬO�ϥ� Harris �˴����]�аѾ\cornerHarris�^�٬OcornerMinEigenVal ���ѼơC
            //	k					Harris �˴������ۥѰѼơC

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