#include <conio.h>
#include <iostream>

#include "tools.hpp"
#include "opencv.hpp"

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

char menu()
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
         << "��ѡ���ܣ�\n"
        "*********************************************************\n"
        "*\t1 �������\t2 ��������\t3 ����ת��\t*\n"
        "*\t4 �������\t5 Hadamard�˻�\t6 ������\t*\n"
        "*\t7 ���Ӧ��\t8 OTSU �㷨\t9 ��������\t*\n"
        "*\t0 �˳�����\t\t\t\t\t*\n"
        "*********************************************************\n"
         << "��ѡ���� (0~9): ";
    int ch;
    ch = _getch();
    return ch;
}


int main()
{
    while (true)
    {
        system("cls");
        char choice;
        choice = menu();
        if (choice == '0') // ѡ���˳�
        {
            cout << "\nȷ���˳���? ȷ���밴Y������������������ȡ���˳���" << endl;
            char ch;
            ch = _getch();
            if (ch == 'y' || ch == 'Y') {
                cout << "Bye~\n";
                break;
            }
            else continue;
        }

        system("cls");
        switch (choice)
        {
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
        case '8':
            otsu();
            break;
        case '9':
            seperate();
            break;
        default:
            cout << "����������ٴ����룡\n" << endl;
        }
        wait_for_enter();
    }
    return 0;
}