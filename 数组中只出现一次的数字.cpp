/***
 * 
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * 
 * 解题思路1：使用map
 * 解题思路2：大佬的做法，使用异或运算。。。看不太懂
 * */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
;

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int x = 0;
        int len = data.size();
        for (int i = 0; i < len; ++i)
        {
            x = x ^ data[i];
        }
        int t = x ^ (x - 1) & x; //找1所在的最低位，这个比较简洁易懂
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < len; ++i)
        {
            if (data[i] & t)
            {
                *num1 ^= data[i];
            }
            else
            {
                *num2 ^= data[i];
            }
        }
    }
};

int main()
{

    Solution s;
    int *num1, *num2;
    vector<int> data;
    data.push_back(2);
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(3);
    data.push_back(1);
    data.push_back(4);
    data.push_back(7);
    data.push_back(5);
    data.push_back(5);
    s.FindNumsAppearOnce(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    system("pause");
    return 0;
}