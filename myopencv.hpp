#ifndef MYOPENCV_HPP
#define MYOPENCV_HPP

#include <opencv2/opencv.hpp>
////#include <chrono>

#include "tools.hpp"

Matrix convert_mat_to_matrix(cv::Mat a);

cv::Mat convert_matrix_to_mat(Matrix img);

cv::Mat cv_mat_conv(cv::Mat a, cv::Mat b, int kernel_size = 3, int padding = 1, bool use_opencv = 0);

void demo();

void otsu();

void seperate();

#endif