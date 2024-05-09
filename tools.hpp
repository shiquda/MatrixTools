#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>

const int MAT_LEN = 300;

struct Matrix
{
    int m, n; // 长度
    double value[MAT_LEN][MAT_LEN]{0}; // 初始化为0
};

Matrix read_mat(int n = -1, int m = -1);

void show_mat(Matrix a);

Matrix mat_add(Matrix a, Matrix b);

Matrix mat_num_multi(double k, Matrix a);

Matrix mat_transpose(Matrix a);

Matrix mat_mult(Matrix a, Matrix b);

Matrix mat_hada_mult(Matrix a, Matrix b);

Matrix mat_cut(Matrix a, int n_st, int n_ed, int m_st, int m_ed);

double mat_sum(Matrix a);

Matrix mat_conv(Matrix a, Matrix b, int kernel_size = 3, int padding = 1, bool image_process = 0); // b是kernel

// 功能函数
void matriplus();

void nummulti();

void matritrans();

void matrimulti();

void hadamulti();

void conv();

void conv_application();


#endif