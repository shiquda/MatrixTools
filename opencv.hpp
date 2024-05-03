#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat cv_mat_conv(Mat a, Mat b, int kernel_size = 3, int padding = 1) {
    Mat result;
    // 卷积操作
    filter2D(a, result, -1, b, Point(-1, -1), 0, BORDER_CONSTANT);

    // 添加填充
    Mat paddedResult;
    copyMakeBorder(result, paddedResult, padding, padding, padding, padding, BORDER_CONSTANT);

    return paddedResult;
}

void demo() {
    Mat image = imread("demolena.jpg", IMREAD_GRAYSCALE);  // 以灰度模式读取图像
    if (image.empty()) {
        std::cout << "Failed to load image!" << std::endl;
        return;
    }

    Mat B1 = (Mat_<double>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1) / 9.0;
    Mat B2 = (Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
    Mat B3 = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    Mat B4 = (Mat_<double>(3, 3) << -1 / 9.0, -1 / 9.0, -1 / 9.0, -1 / 9.0, 9 / 9.0, -1 / 9.0, -1 / 9.0, -1 / 9.0, -1 / 9.0);
    Mat B5 = (Mat_<double>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1);
    Mat B6 = (Mat_<double>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1) / 9.0;

    Mat kernels[6]{ B1, B2, B3, B4, B5, B6 };
    //for (int i = 0; i < image.rows; i++)
    //{
    //    for (int j = 0; j < image.cols; j++)
    //    {
    //        cout << static_cast<int>(image.at<uchar>(i, j)) << ' ';
    //    }
    //    cout << '\n';
    //}

    for (int i = 0; i < 6; i++)
    {
        Mat convolutedImage = cv_mat_conv(image, kernels[i]);
        imshow("Convoluted Image", convolutedImage);
        waitKey(0);
    }
}

void otsu() {
    // 加载图像
    Mat img = imread("demolena.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "Failed to load image!" << std::endl;
        return;
    }

    Mat dst;

    // 应用Otsu算法
    double thresh_val = threshold(img, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);


    //std::cout << "Optimal threshold value is: " << thresh_val << std::endl;

    imshow("Otsu Thresholding", dst);
    waitKey(0);
}

void seperate() {
    string paths[4]{ "snowball.jpg", "polyhedrosis.jpg", "ship.jpg", "brain.jpg" };
    for (int i = 0; i < 4; i++)
    {
        // 预处理去噪

        Mat img = imread(paths[i], IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cout << "Failed to load image!" << std::endl;
            return;
        }
        imshow("raw image", img);


        GaussianBlur(img, img, Size(3, 3), 0);

        imshow("blur image", img);

        Mat dst;

        // 应用Otsu算法
        double thresh_val = threshold(img, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);
        imshow("OTSU imgge", dst);
        waitKey(0);
    }
}