/***
 * 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
 * 但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
 * 数值为0或者字符串不是一个合法的数值则返回0。
 * 
 * 输入描述：输入一个字符串,包括数字字母符号,可以为空
 * 输出描述：如果是合法的数值表达则返回该数字，否则返回0
 * 
 * 
 * 解题思路：普通的乘法就行了，网上优秀方法：使用位运算加快乘法运算
 * 
 * */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int length = str.size();
        int sum = 0;
        int sign = 0;
        for(int i = 0; i < length; i++) {
            if(i == 0 && str[i] == '-') {
                sign = 1;
                continue;
            } else if(i == 0 && str[i] == '+') {
                continue;
            }

            if(str[i] < '0' || str[i] > '9') {
                return 0;
            }
            int num = str[i] - 48;
            sum = sum * 10 + num;

        }
        if(sign) {
            sum = -sum;
        }
        return sum;
    }
};

int main(){

    Solution s;
    cout<<(int)'0';
    system("pause");
    return 0;
}
