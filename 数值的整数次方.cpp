/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。
 * 求base的exponent次方。
 * 
 * 解题思路：java需要注意小数问题，而C++直接求就好了
 * */
#include <iostream>
using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {

        if (exponent == 0)
        {
            return 1.000000;
        }

        double mul = 1.0;
        /* 如果指数大于0 */
        if (exponent > 0)
        {
            for (int index = 0; index < exponent; index++)
            {
                mul *= base;
            }
        }
        else
        {
            exponent = -exponent;
            for (int index = 0; index < exponent; index++)
            {
                mul *= base;
            }
            mul = 1.0 / mul;
        }

        return mul;
    }
};

int main()
{
    return 0;
}