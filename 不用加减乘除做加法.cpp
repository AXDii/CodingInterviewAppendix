/***
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 * 
 * 解题思路：num1 ^ num2 是 不需要进位的数，num1 & num2 是需要进位的数
 * (num1 & num2)<<1，是进一位，重复k1 = num1 ^ num2; k2 = (num1 & num2)>>1;k2是否为0，是的话返回k1，否则重复上述步骤 
 * 
 * */


class Solution {
public:
    int Add(int num1, int num2)
    {
        return num2 == 0 ? num1 : Add(num1 ^ num2, (num1 & num2) << 1);
    }
};

#include<iostream>
using namespace std;
int main(){
    return 0;
}