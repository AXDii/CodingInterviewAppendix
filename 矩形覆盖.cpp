/**
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 
 * 
 * 解题思路：矩形需要数目为：1,2,3,5,8,13...  也是一题类似斐波那契的题
 * */

#include <iostream>
using namespace std;

int rectCover(int number)
{
    int f1 = 1;
    int f2 = 2;
    if (number == 1)
    {
        return 1;
    }
    if (number == 2)
    {
        return 2;
    }
    int sum = 0;
    while (number-- > 2)
    {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum;
}
int main()
{
    return 0;
}