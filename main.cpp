#include <conio.h>
#include <iostream>

#include "tools.h"
// #include <opencv2/opencv.hpp>
// using namespace cv;
using namespace std;


// �˿�����в�������������ҵ�������޸�
struct Mat {
    int m, n;  // ���� 
    value[10001][10001]{ 0 };
};

void wait_for_enter()
{
    cout << endl
        << "���س�������";
    while (_getch() != '\r')
        ;
    cout << endl
        << endl;
}

void menu(){
    cout << "��ӭ���� Matrix Tools\n"
        <<"��ѡ���ܣ�\n1 �������\t2 ��������\t3 ����ת��\n4 �������\t5 ���� handi\t6 \n7 \t8 \t9 \n0 �˳�����"
        << "�����빦�� (0~9): ";
}
void demo()
{
    // /* ��vs+opencv��ȷ���ú󷽿�ʹ�ã��˴�ֻ����һ�ζ�ȡ����ʾͼ��Ĳο����룬���๦������������ƺͲ������� */
    // Mat image =
    //     imread("demolena.jpg"); // ͼ��ĻҶ�ֵ����ڸ�ʽΪMat�ı���image��
    // imshow("Image-original", image);
    // waitKey(0);

    // ��ʾ��Mat��ʽ���������໥ת��

    return;
}

int main()
{
    // ������ر���

    wait_for_enter();
    while (true) // ע���ѭ���˳�������
    {
        system("cls"); // ��������

        menu(); // ���ò˵���ʾ���������в������

        // ��Ҫ������˵�ѡ����choice

        if (choice == '0') // ѡ���˳�
        {
            cout << "\n ȷ���˳���?" << endl;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                break;
            else
                continue;
        }

        switch (choice)
        {
            // ���������������������Ʋ���ɣ����������������������͵ȣ�����ѡ��ӷ�������в���
        case '1':
            matriplus();
            break;
        case '2':
            nummulti();
            break;
        case '3':
            matritrans();
            break;
        case '4':
            matrimulti();
            break;
        case '5':
            hadamulti();
            break;
        case '6':
            conv();
            break;
        case '7':
            demo();
            break;
        default:
            cout << "\n ����������������" << endl;
            wait_for_enter();
        }
    }
    return 0;
}