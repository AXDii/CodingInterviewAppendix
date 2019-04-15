/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * 
 * 思路：法一：递归，不通过，时间复杂度高
 * 法二：利用非递归斐波那契数列解决
 * */
#include <iostream>
using namespace std;

int jumpFloor(int number)
{
    if (number < 0)
    {
        return 0;
    }
    else if (number == 0)
    {
        return 1;
    }
    static int count = 0;
    count = jumpFloor(number - 1) + jumpFloor(number - 2);
    return count;
}
int jumpFloor2(int n)
{

    int f1 = 1;
    int f2 = 1;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return f2;
    }
    int i = 2;
    int sum = 0;
    while (i++ <= n)
    {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}

int main()
{
    cout << jumpFloor(4) << endl;
    system("pause");
}