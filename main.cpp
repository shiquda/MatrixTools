#include <conio.h>
#include <iostream>

#include "tools.hpp"
// #include <opencv2/opencv.hpp>
// using namespace cv;
using namespace std;

void wait_for_enter()
{
    cout << endl
         << "���س�������...";
    while (_getch() != '\r')
        ;
    cout << endl
         << endl;
}

void menu()
{
    cout << "��ӭʹ�� Matrix Tools! Created with love by @shiquda\n"
        <<    
 R"(
  __  __           _            _            _____                   _         _ 
 |  \/  |   __ _  | |_   _ __  (_) __  __   |_   _|   ___     ___   | |  ___  | |
 | |\/| |  / _` | | __| | '__| | | \ \/ /     | |    / _ \   / _ \  | | / __| | |
 | |  | | | (_| | | |_  | |    | |  >  <      | |   | (_) | | (_) | | | \__ \ |_|
 |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\     |_|    \___/   \___/  |_| |___/ (_)                                                                      
 )"
         << "��ѡ���ܣ�\n1 �������\t2 ��������\t3 ����ת��\n"
        "4 �������\t5 ���� handi\t6 \n"
        "7 \t8 \t9 \n"
        "0 �˳�����\n"
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
    while (true)
    {
        system("cls");

        menu();
        char choice;
        cin >> choice;
        if (choice == '0') // ѡ���˳�
        {
            cout << "\n ȷ���˳���? ȷ��������Y������������������ȡ���˳���" << endl;
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Bye~\n";
                break;
            }
            else continue;
        }

        switch (choice)
        {
        case '1':
            system("cls");
            matriplus();
            break;
        case '2':
            system("cls");
            nummulti();
            break;
        case '3':
            system("cls");
            matritrans();
            break;
        case '4':
            system("cls");
            matrimulti();
            break;
        case '5':
            system("cls");
            hadamulti();
            break;
        case '6':
            system("cls");
            conv();
            break;
        // case '7':
        // system("cls");
        //     demo();
        //     break;
        default:
            system("cls");
            cout << "����������ٴ����룡\n" << endl;
            menu();
        }
        wait_for_enter();
    }
    return 0;
}