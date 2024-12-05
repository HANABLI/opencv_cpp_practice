/**
 * 
*/

#include <gtest/gtest.h>
#include <stddef.h>
#include <GettingStartWithImage/ImageAsMatrix.hpp>
#include <opencv2/highgui.hpp>


std::string PANTHER_IMG = "C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\panther.png";
std::string NUMBER_ZERO_IMG = "C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\number_zero.jpg";
std::string BOY_IMG = "C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\boy.jpg";
std::string MUSK_IMG = "C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\musk.jpg";
class ImageAsMatrixTests
        : public ::testing::Test
{
public:
    std::string numZeroImagePath = NUMBER_ZERO_IMG;
    std::string boyImagePath = BOY_IMG;
    std::string muskImagePath = MUSK_IMG;
    std::string pantherImagePath = PANTHER_IMG;
    cv::Mat matTestImage;
    cv::Mat expectedImage;
private:
    virtual void SetUp() {
        
        
        matTestImage = cv::imread(numZeroImagePath, 0);
        int data[] = {1, 0, 3, 0, 3, 0, 3, 2, 4, 2, 0,
            0, 1, 0, 3, 3, 253, 253, 0, 0, 2, 1,
            0, 0, 8, 0, 249, 255, 255, 253, 71, 1, 5,
            3, 0, 2, 251, 255, 2, 0, 253, 254, 0, 2,
            1, 5, 0, 252, 4, 0, 3, 0, 255, 4, 0,
            0, 0, 2, 255, 0, 0, 0, 3, 253, 0, 4,
            0, 5, 4, 249, 4, 2, 0, 0, 255, 1, 0,
            2, 0, 0, 255, 3, 0, 5, 0, 254, 0, 4,
            0, 0, 0, 255, 1, 0, 0, 3, 255, 0, 0,
            1, 5, 0, 252, 2, 2, 2, 76, 250, 7, 0,
            0, 0, 5, 0, 254, 0, 0, 255, 254, 0, 1,
            0, 8, 0, 3, 253, 253, 255, 250, 1, 2, 1,
            2, 0, 0, 0, 5, 0, 4, 1, 3, 0, 0
        };

        expectedImage =  cv::Mat(13, 11, CV_8UC1, data);
    }
    virtual void TearDown() {
        cv::destroyAllWindows();
    }
};

TEST_F(ImageAsMatrixTests, ImageAsMatrixTests_placeholder_Test) {

    std::cout << matTestImage << std::endl;
    std::cout << "TestImage Type: " << matTestImage.type() << std::endl;
    ASSERT_EQ(expectedImage.type(), matTestImage.type());
    std::cout << "Data type = " << ImageAsMatrix::type2str(matTestImage.type()) << std::endl;
    std::cout << "Image Dimensions = " << matTestImage.size() << std::endl;
}


TEST_F(ImageAsMatrixTests, ImageAsMatrixTests_ManipulatingPixels__Test) {
    matTestImage.at<uchar>(0,0)=200;
    std::cout << matTestImage << std::endl;
}

TEST_F(ImageAsMatrixTests, ImageAsMatrixTests_ManipulatingPixelsGroups_Test) {
    cv::Mat matTestImagePart = matTestImage(cv::Range(0, 2), cv::Range(0, 4));
    std::cout << matTestImagePart << std::endl;
    matTestImagePart.setTo(111);
    std::cout << matTestImagePart << std::endl;
}

TEST_F(ImageAsMatrixTests, ImageAsMatrixTests_DisplayAnImage_Test) {
    //cv::figure_size(800, 200);
    cv::imshow("", matTestImage);
    cv::waitKey(0);
    auto boyImage = cv::imread(boyImagePath);
    cv::imshow("", boyImage);
    cv::waitKey(0);
}

TEST_F(ImageAsMatrixTests, ImageAsMatrixTests_SavingAnImage_Test) {
    auto boyImage = cv::imread(boyImagePath);
    cv::imwrite("C:\\Users\\ADMIN\\Documents\\3_Dev\\opencv-course\\GettingStartWithImage\\GettingStartWithImage\\test\\data\\images\\boy_with_axes.png", boyImage);
}

TEST_F(ImageAsMatrixTests, SplitingAnMergingChanesls_Test) {
    auto muskImage = cv::imread(muskImagePath);
    cv::Mat imgChannels[3];
    split(muskImage, imgChannels);

    cv::imshow("channel1", imgChannels[0]);
    cv::imshow("channel2", imgChannels[1]);
    cv::imshow("channel3", imgChannels[2]);
    cv::imshow("musk image", muskImage);
    cv::waitKey(0);
    
}

TEST_F(ImageAsMatrixTests, ManipulatingColorPixels_Test) {
    cv::Mat mptestImage = cv::imread(numZeroImagePath, 1);
    std::cout << mptestImage.at<cv::Vec3b>(0, 0) << std::endl;
    cv::imshow("", mptestImage);
    cv::waitKey(0);
    mptestImage.at<cv::Vec3b>(0, 0) = cv::Vec3b(0, 255, 255);
    cv::imshow("Yello pixel", mptestImage);
    cv::waitKey(0);
    mptestImage.at<cv::Vec3b>(1, 1) = cv::Vec3b(255, 255, 0);
    cv::imshow("blue pixel", mptestImage);
    cv::waitKey(0);
    mptestImage.at<cv::Vec3b>(2, 2) = cv::Vec3b(255, 0, 255);
    cv::imshow("red pixel", mptestImage);
    cv::waitKey(0);
    mptestImage(cv::Range(0, 3), cv::Range(0, 3)).setTo(cv::Scalar(255, 0, 0));
    mptestImage(cv::Range(3, 6), cv::Range(0, 3)).setTo(cv::Scalar(0, 255, 0));
    mptestImage(cv::Range(6, 9), cv::Range(0, 3)).setTo(cv::Scalar(0, 0, 255));
    cv::imshow("Region of Interest", mptestImage);
    cv::waitKey(0);
}

TEST_F(ImageAsMatrixTests, ImagesWithAlphaChannel_Test) {
    cv::Mat pantherImageTest = cv::imread(pantherImagePath, -1);
    std::cout << "panther image size: " << pantherImageTest.size() << std::endl;
    std::cout << "panther image channels number: " << pantherImageTest.channels() << std::endl;

    cv::Mat imgBGR;
    cv::Mat imgPNGChannels[4];
    cv::split(pantherImageTest, imgPNGChannels) ;
    cv::merge(imgPNGChannels, 3, imgBGR) ;

    cv::Mat imgMask = imgPNGChannels[3] ;

    cv::imshow("BGR panther image", imgBGR);
    cv::imshow("Mask panther image", imgMask);
    cv::waitKey(0); 
}