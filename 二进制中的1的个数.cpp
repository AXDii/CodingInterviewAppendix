/**
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * 思路：数组右移，正数判断1的个数，负数判断0的个数后用32减去该数
 * 最优解：见法2
 * 
 */
#include <iostream>
using namespace std;
int NumberOf1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int count = 0;
    if (n > 0)
    {

        while (n >= 1)
        {
            if (n & 1 == 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
    else
    {
        while (n != -1)
        {
            if ((n & 1) == 0)
            {
                count++;
            }
            n = n >> 1;
        }
        return 32 - count;
    }
}

int main()
{
    cout << NumberOf1(7);
    system("pause");
    return 0;
}