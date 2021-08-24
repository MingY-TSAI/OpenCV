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
    //    image	    8 ��B��q�D�B�ǫ׿�J�Ϲ��C
    //    circles	��쪺�ꪺ��X�V�q. �C�ӦV�q�Q�s�X�� 3 �� 4 �����B�I�V�qpoint vector(x, y, radius) �� (x, y, radius, votes) .
    //    method	�˴���k�A�Ѩ�HoughModes�C�i�Ϊ���k�OHOUGH_GRADIENT�MHOUGH_GRADIENT_ALT�C
    //    dp	    �֥[������v�P�Ϲ�����v���Ϥ�C�Ҧp�A�p�G dp=1 �A�h�֥[���㦳�P��J�Ϲ��ۦP������v�C
    //              �p�G dp=2 �A�֥[�����e�שM���׬O��Ӫ��@�b�C���HOUGH_GRADIENT_ALT�A���˭ȬO dp=1.5�A
    //              ���D�ݭn�˴��@�ǫD�`�p�����C
    //    minDist	�˴��쪺�ꪺ���ߤ������̤p�Z���C�p�G�ѼƤӤp�A���F�@�ӯu�@�ӥ~�A�٥i��~�˴���h�ӾF�~��C
    //              �p�G�Ӥj�A�i��|��|�@�Ƕ��C
    //    param1	�Ĥ@�ӯS�w���k���ѼơC�bHOUGH_GRADIENT�MHOUGH_GRADIENT_ALT �����p�U�A
    //              ���O�ǻ��� Canny ��t�˴�������̤��������H�ȡ]���C���H�Ȥp�⭿�^�C
    //              �Ъ`�N�AHOUGH_GRADIENT_ALT�ϥ�Scharr��k�p��Ϲ��ɼơA�]���H�ȳq�`���󰪡A
    //              �Ҧp 300 �Υ��`�n���M���ת��Ϲ��C
    //    param2	�ĤG�ӯS�w���k���ѼơC�bHOUGH_GRADIENT �����p�U�A���O�˴����q��ߪ��֥[���H�ȡC
    //              ���V�p�A�˴��쪺����N�V�h�C�P���j�֥[���Ȭ۹��������N������^�C�bHOUGH_GRADIENT_ALT��k�����p�U�A
    //              �o�O�ꪺ���������׶q�C���V���� 1�A��k��ܪ��Ϊ��V�n�C�b�j�h�Ʊ��p�U�A0.9 ���ӨS���D�C
    //              �p�G�z�Q��n�a�˴��p���A�z�i�H�N�䭰�C�� 0.85�B0.8 �Ʀܧ�C�C
    //              ���H��]�n�ɶq����j���d�� [minRadius, maxRadius] �H�קK�X�{�ܦh���~����l�C
    //    minRadius	�̤p��b�|�C
    //    maxRadius	�̤j��b�|�C�p�G <= 0�A�h�ϥγ̤j�Ϲ��ؤo�C�p�G < 0�AHOUGH_GRADIENT��^���ߦӤ����b�|�C
    //              HOUGH_GRADIENT_ALT�l�׭p���b�|�C


    //param1
    //HOUGH_STANDARD
    //    classical or standard Hough transform.Every line is represented by two floating - point numbers(�l, �c),
    //    where �l is a distance between(0, 0) pointand the line, and �c is the angle 
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

