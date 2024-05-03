#include <conio.h>
#include <iostream>

#include "tools.hpp"
#include "opencv.hpp"

using namespace std;

void wait_for_enter()
{
    cout << endl
         << "按回车键继续...";
    while (_getch() != '\r')
        ;
    cout << endl
         << endl;
}

char menu()
{
    cout << "欢迎使用 Matrix Tools! Created with love by @shiquda\n"
        <<    
 R"(
  __  __           _            _            _____                   _         _ 
 |  \/  |   __ _  | |_   _ __  (_) __  __   |_   _|   ___     ___   | |  ___  | |
 | |\/| |  / _` | | __| | '__| | | \ \/ /     | |    / _ \   / _ \  | | / __| | |
 | |  | | | (_| | | |_  | |    | |  >  <      | |   | (_) | | (_) | | | \__ \ |_|
 |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\     |_|    \___/   \___/  |_| |___/ (_)                                                                      
 )"
         << "请选择功能：\n"
        "*********************************************************\n"
        "*\t1 矩阵相加\t2 矩阵数乘\t3 矩阵转置\t*\n"
        "*\t4 矩阵相乘\t5 Hadamard乘积\t6 矩阵卷积\t*\n"
        "*\t7 卷积应用\t8 OTSU 算法\t9 背景分离\t*\n"
        "*\t0 退出程序\t\t\t\t\t*\n"
        "*********************************************************\n"
         << "请选择功能 (0~9): ";
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
        if (choice == '0') // 选择退出
        {
            cout << "\n确定退出吗? 确认请按Y，按下任意其他键则取消退出：" << endl;
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
            cout << "输入错误，请再次输入！\n" << endl;
        }
        wait_for_enter();
    }
    return 0;
}