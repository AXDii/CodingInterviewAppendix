/***
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)
 * 中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 * 
 * 解题思路：使用stl中的map就好了，法一解题速度太慢了
 * 
 * */

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        int arr[52][2] = {0};
        int stackSize = -1;
        int stack[52] = {0};
        for (unsigned i = 0; i < str.length(); i++)
        {
            int index = 0;
            if (str[i] >= 65 && str[i] <= 90)
            {
                index = str[i] - 65;
            }
            else
            {
                index = str[i] - 71;
            }
            arr[index][0]++;
            if (arr[index][0] == 1)
            {
                stack[++stackSize] = index;
            }
            arr[index][1] = i;
        }
        int res = -1;
        for (int i = 0; i <= stackSize; i++)
        {
            if (arr[stack[i]][0] == 1)
            {
                res = arr[stack[i]][1];
                break;
            }
        }
        return res;
    }

    int FirstNotRepeatingChar2(string str)
    {
        map<char, int> mp;
        for (int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for (int i = 0; i < str.size(); ++i)
        {
            if (mp[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
//'A-z':65-90; 'a-z':97-122;
int main()
{
    Solution s;
    string str = "aafskatfs";
    cout << s.FirstNotRepeatingChar(str);
    system("pause");
    return 0;
}