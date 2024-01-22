#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdlib.h>
using namespace std;
void randomtable(int table[3][3]);
void movetile(int table[3][3], char move);
void printtable(int table[3][3]);
void mainmenu();
void autorun(int table[3][3]);
bool victory(int table[3][3]);
float a, b, c, d;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int table[3][3];
    char move;
    while (true)
    {
        mainmenu();//màn hình chính, chi tiết xem void mainmenu ở dưới :v
        //trường hợp nhập vào số 1, tự chơi tự giải
        if (a == 1)
        {
            randomtable(table);
            while (true)
            {
                printtable(table);
                cout << "Press 0 to exit\n";
                cout << "Enter the move (W/A/S/D): ";
                cin >> move;
                if (move == '0')
                {
                    cout << "Do you want to return to the main screen or exit the game? (1/2): ";
                    cin >> d;
                    if (d == 1)
                    {
                        system("CLS");
                        break;
                    }
                    else if (d == 2)
                    {
                        cout << "Thanks for playing. Goodbye!\n";
                        return 0;
                    }
                }
                movetile(table, move);
                system("CLS");
                if (victory(table))
                {
                    cout << "Congratulations! You solved the puzzle!\n";
                    break;
                }
            }
        }//trường hợp 2, game tự chơi tự giải, bug ngay đây
        else if (a == 2)
        {
            autorun(table);
        }//không quan trọng
        else if (a == 3)
        {
            cout << "Rule is simple!!!\n";
            cout << "You will have a bunch of random numbers in a 3x3 table on the screen\n";
            cout << "Your mission is to swap them until the numbers on the table become:\n";
            cout << " 1  2  3 \n";
            cout << " 4  5  6 \n";
            cout << " 7  8    \n";
            cout << "Good luck!\n";
            cout << "Press 0 to close ";
            cin >> b;
            if (b == 0)
            {
                system("CLS");
            }
        }
        else if (a == 4)//không quan trọng
        {
            cout << "Vo Minh Quang - 052205011234 - CL2304CLCB\n";
            cout << "Tai lieu tham khao:\n";
            cout << "https://www.youtube.com/watch?v=23OuPV4CwwE\n";
            cout << "https://cplusplus.com/reference/algorithm/random_shuffle/\n";
            cout << "https://deviot.vn/tutorials/c-co-ban.78025672/mang-2-chieu-phan-1.59527410\n";
            cout << "https://www.youtube.com/watch?v=1PxFHyYkgNU&t=439s";
            cout << "Press 0 to close";
            cin >> c;
            if (c == 0)
            {
                system("CLS");
            }
        }
        else if (a == 5)//không quan trọng :frogyes:
        {
            return 0;
        }
    }
    return 0;
}
//màn hình chính
void mainmenu()
{
    cout << "Welcome to da Puzzle Game!!!\n";
    cout << "Game start(1)\n";
    cout << "Game start(Auto Solved)(2)\n";
    cout << "How to play(3)\n";
    cout << "About us(4)\n";
    cout << "Exit(5)\n";
    cout << "Choose your action(1,2,3,4,5)\n";
    cin >> a;
    system("CLS");
    //không có dòng này game nó bug cmnr, còn bug gì đừng hỏi :frogthonk80:
    if (a == 0)
    {
        a = -1;
    }
}
//chế độ tự dộng chơi (BUG NGAY DAY)
void autorun(int table[3][3])
{
    while (true)
    {
        printtable(table);
        //ko có gì cao siêu, cho nó chọn ngẫu nhiên 1 ô mà đi
        char move = "WASD"[rand() % 4];
        movetile(table, move);
        system("CLS");
        if (victory(table))
        {
            cout << "Auto-run completed. Puzzle solved!\n";
            break;
        }
    }
}
//tạo bảng ngẫu nhiên
void randomtable(int table[3][3])
{
    int diffnumber[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    random_shuffle(begin(diffnumber), end(diffnumber));
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = diffnumber[k++];
        }
    }
}
//in bảng ra màn hình
void printtable(int table[3][3])
{
    cout << "Current Puzzle:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << table[i][j] << " ";
            }
        }
        cout << endl;
    }
}
//bộ điều khiển wasd
void movetile(int table[3][3], char move)
{
    int emptyrow ; int emptycol; //chỗ này lỗi toy, đã sửa :frogyes:
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == 0)
            {
                emptyrow = i;
                emptycol = j;
                break;
            }
        }
        if (emptyrow != -1)
            break;
    }
    switch (move)
    {
    case 'w':
        if (emptyrow > 0)
        {
            swap(table[emptyrow][emptycol], table[emptyrow - 1][emptycol]);
        }
        break;
    case 'a':
        if (emptycol > 0)
        {
            swap(table[emptyrow][emptycol], table[emptyrow][emptycol - 1]);
        }
        break;
    case 's':
        if (emptyrow < 2)
        {
            swap(table[emptyrow][emptycol], table[emptyrow + 1][emptycol]);
        }
        break;
    case 'd':
        if (emptycol < 2)
        {
            swap(table[emptyrow][emptycol], table[emptyrow][emptycol + 1]);
        }
        break;
    default:
        cout << "Invalid move! Please use W, A, S, or D.\n";
        break;
    }
}
//kiểm tra xem win chưa :frog~1:
bool victory(int table[3][3])
{
//bảng win mẫu để so sánh
    int victorytable[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
//so sánh từng phần tử của 2 bảng, nếu giống nhau thì win, ko thì éo
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] != victorytable[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
