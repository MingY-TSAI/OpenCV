#include <opencv2/core.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include <iostream> 

using namespace cv;
using namespace std;



int main()

{

    string image_path = "Resources/1.png";

    Mat img = imread(image_path, IMREAD_COLOR);

    if (img.empty())
    {
        cout << "Could not read the image: " << image_path << endl;

        return 1;
    }

    imshow("Display window", img);

    int k = waitKey(0); // 接收鍵盤按鍵

    if (k == 's') //按s鍵後反應

    {
        imwrite("starry_night.png", img);//下載圖片
    }

    return 0;

}
