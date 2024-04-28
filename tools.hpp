#include <iostream>
using namespace std;

const int MAT_LEN = 10;

struct Mat
{
    int m, n; // 长度
    double value[MAT_LEN][MAT_LEN]{0};
};

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
    cout << "功能尚未实现，敬请期待！";
}

void matrimulti()
{
    cout << "功能尚未实现，敬请期待！";
}

void hadamulti()
{
    cout << "功能尚未实现，敬请期待！";
}
void conv()
{
    cout << "功能尚未实现，敬请期待！";
}