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
    Mat res_mat = mat_add(mat1, mat2);
    cout << "���� Hadamard �˻��Ľ���ǣ�\n";
    show_mat(res_mat);
}

void conv()
{
    cout << "������δʵ�֣������ڴ���";
}