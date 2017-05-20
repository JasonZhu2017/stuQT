#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    cv::Mat image = cv::imread("D:\\zBox\\work\\projects\\exercise\\qt\\myOpenCVProject\\img.jpg");
    cv::namedWindow("zjh image window");
    cv::imshow("zjh image window", image);
    cv::waitKey(50000);
    return 1;
}
