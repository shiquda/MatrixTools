#include "tools.hpp"
#include "opencv.hpp"

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
// 转换

Matrix convert_mat_to_matrix(cv::Mat a) {

    Matrix img;
    img.n = a.rows;
    img.m = a.cols;
    cout << a.rows << ' ' << a.cols << endl;
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            if (a.type() == CV_8U) {
                img.value[i][j] = double(a.at<uchar>(i, j));
            }
            else if (a.type() == CV_32F) {
                img.value[i][j] = double(a.at<float>(i, j));
            }
            else if (a.type() == CV_64F) {
                img.value[i][j] = a.at<double>(i, j);
            }
            else {
                std::cerr << "未知数据类型！" << std::endl;
                break;
            }
        }
    }
    return img;
}

cv::Mat convert_matrix_to_mat(Matrix img) {
    using namespace cv;
    cv::Mat a(img.n, img.m, CV_8U);

    for (int i = 0; i < img.n; i++) {
        for (int j = 0; j < img.m; j++) {
            a.at<uchar>(i, j) = uchar(img.value[i][j]);
        }
    }

    return a;
}


cv::Mat cv_mat_conv(cv::Mat a, cv::Mat b, int kernel_size, int padding, bool use_opencv) {
    if (use_opencv)
    {
        Scalar kernel_sum = sum(b);
        if (kernel_sum[0] != 0)
        {
            b = b / kernel_sum[0];
        }
        cv::Mat result;
        // 卷积操作
        filter2D(a, result, -1, b, Point(-1, -1), 0, BORDER_CONSTANT);

        //添加填充
        cv::Mat paddedResult;
        copyMakeBorder(result, paddedResult, padding, padding, padding, padding, BORDER_CONSTANT);

        return paddedResult;
    }
    else
    {
        Matrix ma = convert_mat_to_matrix(a);
        Matrix mb = convert_mat_to_matrix(b);
        Matrix result = mat_conv(ma, mb, kernel_size, padding, 1);
        return convert_matrix_to_mat(result);
    }

}

void demo() {
    cv::Mat image = imread("demolena.jpg", IMREAD_GRAYSCALE);  // 以灰度模式读取图像
    if (image.empty()) {
        std::cout << "Failed to load image!" << std::endl;
        return;
    }

    cv::Mat B1 = (Mat_<double>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1);
    cv::Mat B2 = (Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
    cv::Mat B3 = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    cv::Mat B4 = (Mat_<double>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
    cv::Mat B5 = (Mat_<double>(3, 3) << -1, -1, 0, -1, 0, 1, 0, 1, 1);
    cv::Mat B6 = (Mat_<double>(3, 3) << 1, 2, 1, 2, 4, 2, 1, 2, 1);

    cv::Mat kernels[6]{ B1, B2, B3, B4, B5, B6 };
    //for (int i = 0; i < image.rows; i++)
    //{
    //    for (int j = 0; j < image.cols; j++)
    //    {
    //        cout << static_cast<int>(image.at<uchar>(i, j)) << ' ';
    //    }
    //    cout << '\n';
    //}
    //auto start = std::chrono::high_resolution_clock::now();

    //cv_mat_conv(image, kernels[0], 3, 1, 1);

    //auto end = std::chrono::high_resolution_clock::now();

    //std::chrono::duration<double> diff = end - start;

    //std::cout << "Function took " << diff.count() << " seconds to run" << std::endl;

    for (int i = 0; i < 6; i++)
    {
        cv::Mat convolutedImage = cv_mat_conv(image, kernels[i], 3, 1, 0);
        imshow("Convoluted Image ", convolutedImage);
        waitKey(0);
    }
}

void otsu() {
    // 加载图像
    cv::Mat img = imread("demolena.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "Failed to load image!" << std::endl;
        return;
    }

    cv::Mat dst;

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

        cv::Mat img = imread(paths[i], IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cout << "Failed to load image!" << std::endl;
            return;
        }
        imshow("raw image", img);


        GaussianBlur(img, img, Size(3, 3), 0);

        imshow("blur image", img);

        cv::Mat dst;

        // 应用Otsu算法
        double thresh_val = threshold(img, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);
        imshow("OTSU imgge", dst);
        waitKey(0);
    }
}