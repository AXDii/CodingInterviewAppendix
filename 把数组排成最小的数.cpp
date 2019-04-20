/***
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
 * 则打印出这三个数字能排成的最小数字为321323。
 * 
 * 解题思路，最简单,时间复杂度最高：全排列，保留最小的数
 * 
 * 较优解：法二，利用字符串比较
 * 
 * 
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        int len = numbers.size();
        int sign[len];
        for (int i = 0; i < len; i++)
        {
            sign[i] = 0;
        }
        int min = -1;
        dfs(numbers, sign, 0, 0, len, min);
        return to_string(min);
    }

    void dfs(vector<int> &numbers, int *sign, int num, int next, int n, int &min)
    {
        if (next == n)
        {
            // cout<<num<<endl;
            if (min == -1)
            {
                min = num;
            }
            else if (min > num)
            {
                min = num;
            }
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (sign[i] == 1)
            {
                continue;
            }
            sign[i] = 1;
            dfs(numbers, sign, make(numbers[i], num), next + 1, n, min);
            sign[i] = 0;
        }
    }

    //构造一个数，使得返回值是a和b拼接的数，比如a=23,b=84,返回2384
    int make(int a, int b)
    {
        int i = calIndex(b);
        cout << a << " " << b << " " << i << " ";
        int temp = a;
        for (int k = 0; k < i; k++)
        {
            temp = temp * 10;
        }
        temp += b;
        cout << temp << endl;
        return temp;
    }

    int calIndex(int num)
    {
        int count = 1;
        while (num >= 10)
        {
            num /= 10;
            count++;
        }
        return count;
    }

    string PrintMinNumber2(vector<int> numbers)
    {

        string answer = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
        {
            answer += to_string(numbers[i]);
        }
        return answer;
    }

    static bool cmp(int a, int b)
    {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
};

int main()
{

    Solution s;
    cout << s.calIndex(23);

    vector<int> a;
    a.push_back(3);
    a.push_back(32);
    a.push_back(321);
    s.PrintMinNumber(a);
    system("pause");
    return 0;
}
