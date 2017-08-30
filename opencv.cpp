#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

Mat image,image1,image2;  

char* windowName="Image Fusion";  
char* trackBarName="TrackBar";  
int trackBarValue=0;  
int trackBarMax=100;  
  
//�������ص�����  
void TrackBarFunc(int ,void(*));  
int main(int argc,char *argv[])  
{  
    image1=imread("2.jpg");  
    image2=imread("3.jpg");  
   
    //����image2�Ĵ�С��image1�Ĵ�Сһ�£��ںϺ���addWeighted()Ҫ�����������ͼ�γߴ���ͬ  
    resize(image2,image2,Size(image1.cols,image1.rows));  
    //������ʾ����  
    namedWindow(windowName);  
    //��ͼ�񴰿��ϴ���������  
    createTrackbar(trackBarName,windowName,&trackBarValue,trackBarMax,TrackBarFunc);  
    TrackBarFunc(0,0);  
    waitKey();  
    return 0;  
}  
void TrackBarFunc(int ,void(*))  
{  
    //ת�����ںϱ���  
    float rate=(float)trackBarValue/trackBarMax;  
    addWeighted(image1,rate,image2,1-rate,0,image);  
    imshow(windowName,image);     
}