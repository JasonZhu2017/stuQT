#include <QCoreApplication>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>

void testReshape()
{
    cv::Mat testMat = cv::Mat::zeros ( 5, 3, CV_8UC3 );
    //    int data = testMat.data;
        uchar index = 0;
        for(int j=0; j<5; j++)
        {
            uchar *data = testMat.ptr<uchar>(j);
            for (int i=0; i<3; i++)
            {
                *data++ = index++;
                *data++ = index++;
                *data++ = index++;
            }
        }
        std::cout << "size of testMat: " << testMat.rows << " x " << testMat.cols << std::endl;
        std::cout<<"testMat = "<<std::endl<<testMat<<std::endl;
        cv::Mat result = testMat.reshape ( 0, 15 );
        std::cout << " size of original testMat: " << testMat.rows << " x " << testMat.cols << std::endl;
        std::cout << " size of reshaped testMat: " << result.rows << " x " << result.cols << std::endl;
        std::cout << "result = " <<std::endl<< result << std::endl;
        cv::waitKey(0);
        system("pause");


}

void testROI()
{
    cv::Mat image;
    cv::Mat imageROI;
    cv::Mat logo;
    image = cv::imread("../images/boldt.jpg");

//    image = cv::imread("D:/zBox/work/projects/exercise/qt/images/boldt.jpg");
//    cv::namedWindow("image");
    cv::imshow("image", image);
    logo = cv::imread("D:/zBox/work/projects/exercise/qt/images/logo.bmp");
    cv::imshow("logo", logo);
    imageROI = image(cv::Rect(385, 270, logo.cols, logo.rows));
    cv::imshow("imageROI", imageROI);
    cv::addWeighted(imageROI, 1.0, logo, 0.3, 0., imageROI);
    cv::imshow("proccssed imageROI", imageROI);
    cv::imshow("proccssed image", image);
    cv::waitKey(0);
    system("pause");

}

void testROIMask()
{
    cv::Mat image, imageROI, logo, mask;
    image = cv::imread("../images/boldt.jpg");
    cv::imshow("image", image);
    logo = cv::imread("../images/logo.bmp");
    cv::imshow("logo", logo);
    mask = cv::imread("../images/logo.bmp", 0);
    cv::imshow("mask", mask);
//    imageROI = image(cv::Rect(385,270,logo.cols, logo.rows));
    imageROI = image(cv::Range(27, 27+logo.rows),cv::Range(385,385+logo.cols));
    cv::imshow("imageROI", imageROI);
    logo.copyTo(imageROI, mask);
    cv::imshow("masked imageROI", imageROI);
    cv::imshow("masked image", image);
    cv::waitKey(0);
    system("pause");
}

void testCalcHist()
{
    cv::Mat source = cv::imread("D:/zBox/work/projects/exercise/qt/images/baboon.jpg");
    cv::namedWindow("Source");
    cv::imshow("Source",source);
    cv::Mat hsv;
    cv::cvtColor(source,hsv,CV_BGR2HSV);
    int hbins = 60,sbins = 64;
    int histSize[] = {hbins,sbins};
    float hranges[] = {0,180};
    float sranges[] = {0,255};
    const float *ranges[] = {hranges,sranges};
    int channels[] = {0,1};
    cv::Mat hist;
    cv::calcHist(&hsv,1,channels,cv::Mat(),hist,2,histSize,ranges);
//    qDebug() << hist.cols << hist.rows;
    double maxVal = .0;
    cv::minMaxLoc(hist,0,&maxVal,0,0);
    int scale = 8;
    cv::Mat histImg =cv::Mat::zeros(sbins*scale,hbins*scale,CV_8UC3);
    for (int h = 0;h < hbins;h++)
    {
        for (int s = 0;s<sbins;s++)
        {
            float binVal = hist.at<float>(h,s);
            int intensity = cvRound(binVal*0.9*255/maxVal);
            cv::rectangle(histImg,cv::Point(h*scale,s*scale),cv::Point((h+1)*scale-1,(s+1)*scale-1),cv::Scalar::all(intensity),CV_FILLED);
        }
    }
    cv::imshow("H-S Histogram",histImg);
    cv::namedWindow("H-S Histogram");
//    cv::imwrite("hshistogram.jpg",histImg);
    cv::waitKey(0);
    system("pause");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString runPath = QCoreApplication::applicationDirPath();
    qDebug() << runPath;
//    testReshape();
//    testROI();
//    testROIMask();
//    int va = static_cast<int>(cv::norm<uchar,3>(cv::Vec3b(255,255,128)));
//    qDebug() << va;
    testCalcHist();
    return a.exec();
}
