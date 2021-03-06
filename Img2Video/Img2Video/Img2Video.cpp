// Img2Video.cpp : read a sequence of images, output a video
// Author: Zhiyuan Wang
// zywang@u.northwestern.edu
// Feb, 2, 2014
//#include <string.h>
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include "img2video.h"
using namespace cv;
using namespace std;

/* calculate gradient image */
Mat gradient(Mat src, int color);
/* get dirty lens mask from first few images in a sequence*/
Mat Mask(char*, int, int);
/* the following 3 function still need debug and revision*/
/* an implementation of algorithm in J. Gu et al. */
Mat SmoothBG();
/* obtain median value of a Mat */
uchar getMedian(Mat src);
/* get pixelwise max - min image for a sequence of images */
void Maxmin();

/******************************************************************************************
 * Note: input images can only be named by sequential number, as "%d.jpg".
 * no input: Run with default setting. Read image sequence under "C://sample_drive//sample_drive//cam_2//", 
             begin from 393408606.jpg, end with 393413167.jpg
 * one input: directory changed as the input
 * three input: directory path, begin image number, end image number
 */

int main(int argc, char* argv[])
{
	Img2Video img2video(1, 10443, "C://forSpeedLimit//Cam4//", "C://forSpeedLimit//Cam4//");
	/*
	int begin = 393408606;
	int end = 393413167;
	int i;
	int len = 4500;
	char filepath[100];
	char outpath[100];
	char* dirpath = "C://sample_drive//sample_drive//cam_5//";
	if(argc == 2)
	{
		dirpath = argv[1];
		//cout << argv[1] << endl;
	}
	else if(argc == 4)
	{
		dirpath = argv[1];
		begin = atoi(argv[2]);
		end = atoi(argv[3]);
	}
	else if(argc == 5)
	{
		dirpath = argv[1];
		begin = atoi(argv[2]);
		end = atoi(argv[3]);
		len = atoi(argv[4]);
	}
	*/
	img2video.main();
    return 0;
}



