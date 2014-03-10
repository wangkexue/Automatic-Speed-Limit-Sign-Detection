#ifndef IMG2VIDEO_H
#define	IMG2VIDEO_H

#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;

class Img2Video 
{
private:
	int begin;
	int end;
	char dirpath[100];
	char outpath[100];
	char filepath[100];
public:
	Img2Video(int _begin, int _end, char _dirpath[100], char _outpath[100])
	{
		begin = _begin;
		end = _end;
		strcpy_s(dirpath, _dirpath);
		strcpy_s(outpath, _outpath);
	}
	~Img2Video()
	{
		delete []filepath;
	}
	void main()
	{
		sprintf_s(filepath, "%simage%06d.jpg", dirpath, begin);
		Mat frame = imread(filepath);
		sprintf_s(outpath, "%scam_grad.avi", dirpath);
		VideoWriter Output(outpath, CV_FOURCC('D', 'I', 'V', 'X'), 5, frame.size());
		namedWindow("frame", WINDOW_NORMAL);
		for(int i = begin; i <= end; i++)
		{
			sprintf_s(filepath, "%simage%06d.jpg", dirpath, i);
			//cout << filepath;
			frame = imread(filepath);
			if(frame.empty())
			{
				continue;
			}

			Output << frame;
			imshow("frame", frame);
			//imwrite("result.jpg", frame);
			// space key for pause
			if(waitKey(1)==32)
			{
				while(1)
				{
					int key = waitKey(1);
					
					if(key == 13)
					{
						char savepath[100];
						sprintf_s(savepath, "sample%06d.jpg", i);
						imwrite(savepath, frame);
						cout << savepath << endl;
					}	
					else if(key == 32)
						break;
				}
			}
			// esc key for exit
			if(waitKey(1)==27)
				exit(0);
		}
		destroyWindow("frame");
	}
};

#endif