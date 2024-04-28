#include <iostream>
using namespace std;

const int MAT_LEN = 10;

struct Mat
{
    int m, n; // 长度
    double value[MAT_LEN][MAT_LEN]{0};
};

// 矩阵基本操作
Mat mat_add(Mat a, Mat b) { // 默认认为矩阵是和规的，在上层函数检查
    Mat res_mat;
    res_mat.n = a.n;
    res_mat.m = a.m;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            res_mat.value[i][j] = a.value[i][j] + b.value[i][j];
        }
    }
    return res_mat;
}

Mat mat_num_multi(double k, Mat a) { // 默认认为矩阵是和规的，在上层函数检查
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            a.value[i][j] *= k;
        }
    }
    return a;
}

Mat mat_transpose(Mat a) {
    Mat res_mat;
    res_mat.m = a.n;
    res_mat.n = a.m;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            res_mat.value[j][i] = a.value[i][j];
        }
    }
    return res_mat;
}

Mat mat_mult(Mat a, Mat b) { // 默认认为矩阵是和规的，在上层函数检查
    Mat res_mat;
    res_mat.n = a.n;
    res_mat.m = b.m;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < b.m; j++)
        {
            for (int k = 0; k < a.n; k++)
            {
                res_mat.value[i][j] += a.value[i][k] * b.value[k][j];
            }
        }
    }
    return res_mat;
}

Mat mat_hada_mult(Mat a, Mat b) {
    Mat res_mat;
    res_mat.n = a.n;
    res_mat.m = a.m;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            res_mat.value[i][j] = a.value[i][j] * b.value[i][j];
        }
    }
    return res_mat;
}

Mat mat_cut(Mat a, int n_st, int n_ed, int m_st, int m_ed) {
    Mat res_mat;
    res_mat.n = n_ed - n_st + 1;
    res_mat.m = m_ed - m_st + 1;
    for (int i = 0; i < res_mat.n; i++)
    {
        for (int j = 0; j < res_mat.m; j++)
        {
            res_mat.value[i][j] = a.value[n_st + i][m_st + j];
        }
    }
    return res_mat;
}

double mat_sum(Mat a) {
    double sum = 0;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            sum += a.value[i][j];
        }
    }
    return sum;
}

Mat mat_conv(Mat a, Mat b, int kernel_size = 3, int padding = 1) // b是kernel
{
    Mat non_padding_mat;
    non_padding_mat.n = a.n - b.n + 1;
    non_padding_mat.m = a.m - b.m + 1;
    for (int i = 0; i < non_padding_mat.n; i++)
    {
        for (int j = 0; j < non_padding_mat.m; j++)
        {
            Mat a_cut = mat_cut(a, i, i + kernel_size - 1, j, j + kernel_size - 1);
            non_padding_mat.value[i][j] = mat_sum(mat_hada_mult(a_cut, b));
        }
    }
    Mat padding_mat;
    padding_mat.n = non_padding_mat.n + 2 * padding;
    padding_mat.m = non_padding_mat.m + 2 * padding;
    for (int i = 0; i < non_padding_mat.n; i++)
    {
        for (int j = 0; j < non_padding_mat.m; j++)
        {
            padding_mat.value[i + padding][j + padding] = non_padding_mat.value[i][j];
        }
    }
    return padding_mat;
}

// 矩阵I/O
Mat read_mat(int n = -1, int m = -1)
{
    if (n == -1 && m == -1) // 默认需要用户输入行数和列数
    {
        cout << "请输入行数和列数，中间以空格分割：";
        cin >> n >> m;
    }

    cout << "请输入一个 " << n << " 行 " << m << " 列的矩阵, 数字之间以空格分割: \n";
    Mat matrix;
    matrix.n = n;
    matrix.m = m;
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
        {
            cin >> matrix.value[i][j];
        }
    }
    return matrix;
}

void show_mat(Mat a)
{
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.m; j++)
        {
            cout << a.value[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 功能函数
void matriplus()
{
    cout << "欢迎使用矩阵相加功能！\n";
    cout << "请输入第一个矩阵：\n";
    Mat mat1 = read_mat();
    cout << "请输入第二个矩阵：\n";
    Mat mat2 = read_mat(mat1.n, mat1.m);
    Mat res_mat = mat_add(mat1, mat2);
    cout << "相加的结果是：\n";
    show_mat(res_mat);
}

void nummulti()
{
    cout << "欢迎使用矩阵数乘功能！\n ";
    cout << "请输入一个实数：";
    double k;
    cin >> k;
    cout << "请输入矩阵：\n";
    Mat a = read_mat();
    a = mat_num_multi(k, a);
    cout << "数乘的结果是：\n";
    show_mat(a);
}

void matritrans()
{
    cout << "欢迎使用矩阵转置功能！\n ";
    cout << "请输入矩阵：\n";
    Mat a = read_mat();
    a = mat_transpose(a);
    cout << "转置的结果是：\n";
    show_mat(a);
}

void matrimulti()
{
    cout << "欢迎使用矩阵相乘功能！\n";
    cout << "请输入第一个矩阵：\n";
    Mat mat1 = read_mat();
    cout << "请输入第二个矩阵：\n";
    Mat mat2 = read_mat(mat1.m, mat1.n);
    Mat res_mat = mat_mult(mat1, mat2);
    cout << "相乘积的结果是：\n";
    show_mat(res_mat);
}

void hadamulti()
{
    cout << "欢迎使用矩阵 Hadamard 乘积功能！\n";
    cout << "请输入第一个矩阵：\n";
    Mat mat1 = read_mat();
    cout << "请输入第二个矩阵：\n";
    Mat mat2 = read_mat(mat1.n, mat1.m);
    Mat res_mat = mat_hada_mult(mat1, mat2);
    cout << "矩阵 Hadamard 乘积的结果是：\n";
    show_mat(res_mat);
}

void conv()
{
    const int kernel_size = 3;
    cout << "欢迎使用矩阵卷积功能！\n";
    cout << "本功能的参数：kernel size = 3，padding = 1，stride = 1，dilation = 1；\n";
    cout << "请输入矩阵 A:\n";
    Mat a = read_mat();
    cout << "请输入方阵 B(kernel), 行数与列数应该不大于A:\n";
    Mat b = read_mat(kernel_size, kernel_size);
    Mat res_mat = mat_conv(a, b, kernel_size);
    cout << "矩阵卷积的结果是：\n";
    show_mat(res_mat);
}