/***
 * 
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
 * 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你
 * 把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输
 * 出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 * 
 * 解题思路：利用字符串的操作
 * 
 * */

#include <iostream>
// #include <vector>
// #include<algorithm>
#include<string>
// #include <stack>
// #include <queue>
// #include <map>
// #include <stdlib.h>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len == 0) return ""; 
        n %= len;
        str += str;
        return str.substr(n, len);
    }
};
int main()
{

    system("pause");
    return 0;
}