#include <iostream>
using namespace std;

const int MAT_LEN = 10;

struct Mat
{
    int m, n; // ����
    double value[MAT_LEN][MAT_LEN]{0};
};

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
    cout << "������δʵ�֣������ڴ���";
}

void matrimulti()
{
    cout << "������δʵ�֣������ڴ���";
}

void hadamulti()
{
    cout << "������δʵ�֣������ڴ���";
}
void conv()
{
    cout << "������δʵ�֣������ڴ���";
}