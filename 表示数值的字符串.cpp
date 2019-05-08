/***
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * 
 * 
 * 解题思路：
 * 
 * */

#include <iostream>
// #include <vector>
// #include<algorithm>
// #include<string>
// #include <stack>
// #include <queue>
// #include <map>
// #include <stdlib.h>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        //检查符号、标点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for(int i = 0; i < strlen(string); i++){

        }
        return true;
    }

};

int main()
{

    system("pause");
    return 0;
}