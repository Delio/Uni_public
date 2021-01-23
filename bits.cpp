#include <iostream>
using namespace std;

int ft_bits(int n, int i)
{
    int i_0 = 0x01;
    int i_1 = 0x02;
    int i_2 = 0x04;
    int i_3 = 0x08;
    int i_4 = 0x10;
    int i_5 = 0x20;
    int i_6 = 0x40;
    int i_7 = 0x80;

    switch (i)
    {
    case 0:
        n = n | i_0;
        break;
    case 1:
        n = n | i_1;
        break;
    case 2:
        n = n | i_2;
        break;
    case 3:
        n = n | i_3;
        break;
    case 4:
        n = n | i_4;
        break;
    case 5:
        n = n | i_5;
        break;
    case 6:
        n = n | i_6;
        break;
    case 7:
        n = n | i_7;
        break;
    default:
        break;
    }

    return n;
}

int main(int argc, char **argv)
{
    int n;
    int i;

    cout << "Введите число n" << endl;
    cin >> n;
    cout << "Введите число i" << endl;
    cin >> i;
    cout << "Число после замены бита равно " << ft_bits(n, i) << endl;;

    return 0;
}
