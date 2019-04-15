/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 
 * 解题思路：1、2、4、8...  规律为2^(n-1)次方
 * 
 * */

#include <iostream>
using namespace std;

int jumpFloorII(int number)
{
    int sum = 1;
    while (number-- >= 2)
    {
        sum *= 2;
    }
    return sum;
}
int main()
{
    jumpFloorII(10);
    return 0;
}