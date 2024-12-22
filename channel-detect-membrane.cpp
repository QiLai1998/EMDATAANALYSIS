#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<opencv2/opencv.hpp>
#include"iostream"

using namespace cv;
using namespace std;


///---------------------------color detector------trackbar-----220511------/////////

Mat imghsv, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
//这里是检测出橙色通道，但一个个测太麻烦所以用trackbar写一个while///


void main() {

	string path = "Resources/mm.jpg";
	Mat img = imread(path);
	cvtColor(img, imghsv, COLOR_BGR2HSV);



	namedWindow("trackqiqi", (640, 200));
	createTrackbar("hue min", "trackqiqi", &hmin, 179);
	createTrackbar("hue max", "trackqiqi", &hmax, 179);
	createTrackbar("sat min", "trackqiqi", &smin, 255);
	createTrackbar("sat max", "trackqiqi", &smax, 255);
	createTrackbar("val min", "trackqiqi", &vmin, 255);
	createTrackbar("val max", "trackqiqi", &vmax, 255);


	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);


		inRange(imghsv, lower, upper, mask);

		cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;//在控制台中显示调试的数值

		imshow("Image", img);
		imshow("imghsv", imghsv);
		imshow("image mask", mask);
		waitKey(1);//加个while循环，把waitkey改成1；while之外建个窗口和bar,这个挺简易的//


	}

}