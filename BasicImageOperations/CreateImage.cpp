#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <string>
int main(void) {
    std::string BOY_IMG = "C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\boy.jpg";
    auto image = cv::imread(BOY_IMG); 
    cv::imshow("Image", image);
    cv::waitKey(0);

    // Create a new image by copying the existing image
    const auto imageCopy = image.clone();
    cv::imshow("copyImage", imageCopy);
    cv::waitKey(0);

    // Create a empty matrix 100/200
    auto emptyMatrix = cv::Mat(100, 200, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::imshow("emptyMatrix", emptyMatrix);
    cv::waitKey(0);
    
    // fill the empty matrix with white pixels
    auto whiteMatrix = emptyMatrix.clone();
    whiteMatrix.setTo(cv::Scalar(255, 255, 255));
    cv::imshow("whiteMatrix", whiteMatrix);
    cv::waitKey(0);
    //create a matrix with the same size and type as the original matrix and fill it with 100
    auto emptyOriginal = cv::Mat(emptyMatrix.size(), emptyMatrix.type(), cv::Scalar(100, 100, 100));
    cv::imshow("emptyOriginal", emptyOriginal);
    cv::waitKey(0);
}