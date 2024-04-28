#include <conio.h>
#include <iostream>

#include "tools.hpp"
// #include <opencv2/opencv.hpp>
// using namespace cv;
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

void menu()
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
         << "请选择功能：\n1 矩阵相加\t2 矩阵数乘\t3 矩阵转置\n"
        "4 矩阵相乘\t5 矩阵 handi\t6 \n"
        "7 \t8 \t9 \n"
        "0 退出程序\n"
         << "请输入功能 (0~9): ";
}
void demo()
{
    // /* 对vs+opencv正确配置后方可使用，此处只给出一段读取并显示图像的参考代码，其余功能流程自行设计和查阅文献 */
    // Mat image =
    //     imread("demolena.jpg"); // 图像的灰度值存放在格式为Mat的变量image中
    // imshow("Image-original", image);
    // waitKey(0);

    // 提示：Mat格式可与数组相互转换

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
        if (choice == '0') // 选择退出
        {
            cout << "\n 确定退出吗? 确认请输入Y，输入任意其他键则取消退出：" << endl;
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
            cout << "输入错误，请再次输入！\n" << endl;
            menu();
        }
        wait_for_enter();
    }
    return 0;
}