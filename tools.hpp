#include <iostream>
using namespace std;

const int MAT_LEN = 10;

struct Mat
{
    int m, n; // ����
    double value[MAT_LEN][MAT_LEN]{0};
};

// �����������
Mat mat_add(Mat a, Mat b) { // Ĭ����Ϊ�����Ǻ͹�ģ����ϲ㺯�����
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

Mat mat_num_multi(double k, Mat a) { // Ĭ����Ϊ�����Ǻ͹�ģ����ϲ㺯�����
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

Mat mat_mult(Mat a, Mat b) { // Ĭ����Ϊ�����Ǻ͹�ģ����ϲ㺯�����
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

Mat mat_conv(Mat a, Mat b, int kernel_size = 3, int padding = 1) // b��kernel
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

// ����I/O
Mat read_mat(int n = -1, int m = -1)
{
    if (n == -1 && m == -1) // Ĭ����Ҫ�û���������������
    {
        cout << "�������������������м��Կո�ָ";
        cin >> n >> m;
    }

    cout << "������һ�� " << n << " �� " << m << " �еľ���, ����֮���Կո�ָ�: \n";
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

// ���ܺ���
void matriplus()
{
    cout << "��ӭʹ�þ�����ӹ��ܣ�\n";
    cout << "�������һ������\n";
    Mat mat1 = read_mat();
    cout << "������ڶ�������\n";
    Mat mat2 = read_mat(mat1.n, mat1.m);
    Mat res_mat = mat_add(mat1, mat2);
    cout << "��ӵĽ���ǣ�\n";
    show_mat(res_mat);
}

void nummulti()
{
    cout << "��ӭʹ�þ������˹��ܣ�\n ";
    cout << "������һ��ʵ����";
    double k;
    cin >> k;
    cout << "���������\n";
    Mat a = read_mat();
    a = mat_num_multi(k, a);
    cout << "���˵Ľ���ǣ�\n";
    show_mat(a);
}

void matritrans()
{
    cout << "��ӭʹ�þ���ת�ù��ܣ�\n ";
    cout << "���������\n";
    Mat a = read_mat();
    a = mat_transpose(a);
    cout << "ת�õĽ���ǣ�\n";
    show_mat(a);
}

void matrimulti()
{
    cout << "��ӭʹ�þ�����˹��ܣ�\n";
    cout << "�������һ������\n";
    Mat mat1 = read_mat();
    cout << "������ڶ�������\n";
    Mat mat2 = read_mat(mat1.m, mat1.n);
    Mat res_mat = mat_mult(mat1, mat2);
    cout << "��˻��Ľ���ǣ�\n";
    show_mat(res_mat);
}

void hadamulti()
{
    cout << "��ӭʹ�þ��� Hadamard �˻����ܣ�\n";
    cout << "�������һ������\n";
    Mat mat1 = read_mat();
    cout << "������ڶ�������\n";
    Mat mat2 = read_mat(mat1.n, mat1.m);
    Mat res_mat = mat_hada_mult(mat1, mat2);
    cout << "���� Hadamard �˻��Ľ���ǣ�\n";
    show_mat(res_mat);
}

void conv()
{
    const int kernel_size = 3;
    cout << "��ӭʹ�þ��������ܣ�\n";
    cout << "�����ܵĲ�����kernel size = 3��padding = 1��stride = 1��dilation = 1��\n";
    cout << "��������� A:\n";
    Mat a = read_mat();
    cout << "�����뷽�� B(kernel), ����������Ӧ�ò�����A:\n";
    Mat b = read_mat(kernel_size, kernel_size);
    Mat res_mat = mat_conv(a, b, kernel_size);
    cout << "�������Ľ���ǣ�\n";
    show_mat(res_mat);
}